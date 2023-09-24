# distributed-code-edu
Exposes [OpenVSCode Server](https://github.com/gitpod-io/openvscode-server) on a publicly accessible port and provides a starting page for navigating to hard-coded paths.
## Purpose
Originally intended for teaching primary to intermediate school students how to program in Python. Can be adapted for other uses and languages.  
It is sometimes infeasible to strafe around a classroom peering over shoulders and individually helping each student. This attempts to solve that to a certain capacity.
## Security
Close to none. But, this is designed for instructing people who are new to programming, let alone using a shell, computer, or even type.
## Usage
1. Create a devcontainer or use Docker, recommended with Codespaces (4-cores).
2. Checkout gh-pages.
    - Modify `directories.txt` to contain the desired folder names for each student.
    - Currently, it contains sample names for 32 students.
    - Run `./compile.sh` and `./page_writer.out` to update `index.md` to reflect `directories.txt`.
    - Commit and push to GitHub. Enable GitHub Pages on gh-pages if it doesn't automatically.
    - The resulting page will contain links to specific paths on the server. Assign students their link / directory if applicable.
3. Checkout main.
    - Primary functionality:
        - Modify `directories.txt` to contain the desired folder names for each student.
        - Run `cd utilities && ./create_directories.out` to create those directories in `students`.
            - Also copies template files in `utilities/template`.
        - Run `./start.sh` and **change port 3000 to public**.
        - Now the links generated in the previous section should work.
        - When not instructing, shutdown the server with <kbd>CTRL</kbd> + <kbd>C</kbd>.
            - On Mac, use `ps all` to determine the PID of `./start.sh` and terminate it with `kill -15 [insert PID here]`. Or use `killall sh` (less recommended).
            - Or just close the terminal session.
        - Also see notes in `utilities/template/readme.md`.
    - Additional functionality:
        - Run `cd utilities && ./extension_monitor.out` to monitor the user-installed extensions. This is because there is no guaranteed way of preventing a student from inadvertently installing unwanted extensions. The side panel is hidden from students by default, but it's not completely fool-proof.
            - In the same way, use `./add_file.out [insert relative file path]` and `./remove_file.out [insert relative file path]` to add and remove files respectively from all student directories.
        - Modify `utilities/valid_extensions.txt` to include the extension IDs of valid extensions used by the monitor.
        - Add content to `utilities/template` to customize the default files provided to each student.
        - Modify `settings.json` for globally applied settings.
        - The version of OpenVSCode Server can be changed in the Dockerfile. **This may cause additional nuances, such as needing to update `.gitignore`**.
## Updating
Run `./uninstall.sh` to remove all executables, pull from the source repo, and then rebuild the devcontainer.  
Remember to update `.gitignore`.
## Note on Performance
Four cores can support at least fifteen connected devices with negligible strain.  
The maximum load is likely higher.  
If using Codespaces, you may be automatically timed out after half an hour. You can extend this in your GitHub settings.
