// This is a fragment of an old TUI library.
// Use with caution.
// - ObjectOops

#ifndef TUI_HPP
#define TUI_HPP

#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <string>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

namespace tin {
    bool isInit {false};
    // Note: Assumes that the terminal state is with canonical and echo mode enabled. So it resets to those settings once done.
    bool init() {
        isInit = true;
        termios state; // State of terminal.
        std::memset(&state, 0, sizeof(state));
        if (tcgetattr(STDIN_FILENO, &state) < 0) return false; // Get state.
        // c_lflag refers to local something.
        state.c_lflag &= ~ICANON; // No buffering.
        state.c_lflag &= ~ECHO; // Supress echoing.
        // c_cc refers to some argument array.
        state.c_cc[VMIN] = 1; // Minimum number of bytes for read.
        state.c_cc[VTIME] = 0; // Time to wait. 0, but this setting just tells it to block?
        if (tcsetattr(0, TCSANOW, &state) < 0) return false; // Set state.
        return true;
    }
    bool uninit() {
        isInit = false;
        termios state; // State of terminal.
        std::memset(&state, 0, sizeof(state));
        if (tcgetattr(STDIN_FILENO, &state) < 0) return false; // Get state.
        // c_lflag refers to local something.
        state.c_lflag |= ICANON; // Buffering.
        state.c_lflag |= ECHO; // Echo.
        if (tcsetattr(STDIN_FILENO, TCSADRAIN, &state) < 0) return false; // Set state.
        return true;
    }
    // Checks if data is available in the input buffer. Does not block the calling thread.
    bool kbhit() {
        if (!isInit) init();
        timeval tv; // Specifies the duration to wait for data if none is detected.
        tv.tv_sec = 0;
        tv.tv_usec = 0;
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        // Test for data.
        if (select(1, &fds, nullptr, nullptr, &tv) < 0) return false; // Fail safe.
        if (FD_ISSET(STDIN_FILENO, &fds)) return true;
        return false;
    }
    // Gets a character as soon as one is available. Blocks the calling thread.
    // To be used in conjunction with kbhit.
    char getch() {
        if (!isInit) init();
        char c;
        if (read(STDIN_FILENO, &c, 1) < 0) c = '\0'; // Wacky read.
        return c;
    }
}

#endif
