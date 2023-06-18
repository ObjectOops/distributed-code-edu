# The Python Programming Language - Rudimentary Guide
![Python logo.](assets/python_logo_animated.gif)
Important terms will be **bolded**.  
Cases where there may be exceptions or nuances have asterisks.  
For an advanced guide, see [30-Days-Of-Python](https://github.com/Asabeneh/30-Days-Of-Python).
## Contents
- [What is Python?](#what-is-python)
- [Why Python?](#why-python)
- [Running Python](#running-python)
    - How to Run
    - The Python Interpreter
    - About Files
    - Basics
        - Hello World
        - IO
        - Comments
        - Errors
        - Vocabulary
- [Variables](#variables)
    - About Variables
    - Integers
    - Floats
    - Booleans
    - Strings
        - Character
    - Tuples
    - Lists
        - Multidimensional
    - Dictionaries
    - Sets
    - Literals
    - Casting
    - None
    - Binary and Hex
    - Object Oriented Programming
- [Arithmetic and Logic](#arithmetic-and-logic)
    - Math in Computers
    - Basic Operators
    - Operator Precedence
    - The `math` Module
    - Comparison Operators
        - `==`
        - `!=`
        - `<`
        - `>`
        - `>=`
        - `<=`
    - Boolean Operators
        - AND, OR, NOT, XOR
- [Control Flow](#control-flow)
    - About Control Flow
    - Conditionals
        - If
        - Elif
        - Else
    - Loops
        - For
        - While
    - Nesting
- [Functions](#functions)
    - About Functions
    - Making a Function
    - Using a Function
    - Function Scope
- [Modules](#modules)
    - About Modules
    - Making a Module
    - Using a Module
- Glossary
- [More](#more)
    - The Python Standard Library
    - Common Algorithms
    - File IO
- [Project](#project)
## What is Python?
Python is a general purpose programming language that's easy to read and use.  
It was first released in 1991 by Guido van Rossum, a Dutch programmer.  
In case you don't know, a programming language can be thought of as instructions given to a computer to do something.
## Why Python?
Python is one of the most popular and widely used programming languages.  
As mentioned, it's easy to read and use. It can also be described as more "human friendly", which basically means you don't have to work as hard to get the computer to do things.  
A large part of Python's popularity comes from the variety of things you can do with it. Some general examples are:
- Making games.
- Making websites.
- Controlling robots.
- Artificial intelligence.
- Track down airplane flights.

So why doesn't everyone just use Python? Reasons may vary, but for instance, Python is known for being slower at running than other languages and relies on being run a certain way to work*. Different programming languages take different approaches to run on different devices. Some other widely used languages with their own advantages and disadvantages are:
- C/C++
- Java
- JavaScript (which is different from Java!)
- C#
- TypeScript
- Ruby

Overall, Python is one of the best languages to learn to start programming. You won't have to worry about speed or how it's exactly run here.
## Running Python
### How to Run
**OpenVSCode Server**:
- This guide was written with configurations and additional software utilities for OpenVSCode Server, which your instructor may be using.
- Your instructor should provide a page of links which can be accessed in the browser. Follow the instructions that appear once you've opened your folder.
- Your instructor may shutdown this option at the end of class. In that case, you can install Python on your own device, or use Replit.

**Replit**:
1. Make an account.
2. Follow the set up instructions.
3. Click [Create Repl] and select Python.
4. Click the green run button.
- Replit should walk you through most of this.
- This option will always be available.

> Both options above work by sending the code you write to a server - a computer somewhere else - which runs the code and then sends back the output over the internet.  
> For Python to always be available to run, follow the guide on the Python website to install the **Python Interpreter**.
## The **Python Interpreter**
In order to understand why computers behave the way they do, it is important to understand the difference between **compiled** and **interpreted** languages.  

The stuff you, the programmer, write is called **source code**. And while it may show up on the computer's screen, the computer itself cannot run these instructions.  

Traditionally, an "advanced" program called a **compiler** would "translate" (**compile**) the **source code** into what's called **machine code**. This **machine code** can be run directly on the physical metal of the computer. These kinds of programs are generally very fast at running*.
```
Source Code        --> Machine Code
 ________________       ________________
|this is some    |     |101011010101111 |
|code that we    |     |111010101011010 |
|want to run     |     |101001110100010 |
|but the         | --> |110101011101011 |
|computer        |     |100101001010110 |
|cannot          |     |101011010011101 |
|understand it.  |     |101011011010101 |
|________________|     |________________|
```
> (The "machine code" above isn't actual machine code. It's purely demonstrative.)

The reason why **machine code** is a bunch of "1s and 0s" is because a "1" represents a small piece of metal in the computer being turned on, and "0" represents it being turned off. This is called **binary**. That was an oversimplification. This "translation" is very difficult to reverse*.  
Some people, particularly in **cybersecurity**, are tasked with reading and understanding **machine code**. It's more normal for them to read **machine code** in **hexadecimal** (**hex**)*.
```
Binary             --> Hexadecimal
 ________________       ________________
|101011010101111 |     |29 AF 38 DD E8  |
|111010101011010 |     |AF 71 23 03 8A  |
|101001110100010 |     |FF E8 72 10 CD  |
|110101011101011 | --> |32 48 9B CD EF  |
|100101001010110 |     |34 8B ED A9 83  |
|101011010011101 |     |FE D8 32 89 3B  |
|101011011010101 |     |B3 28 32 8E D3  |
|________________|     |________________|
```
> (Likwise, the hexadecimal above isn't an accurate representation of the binary, and is purely demonstrative.)
Note that **machine code** is specific to the type of device is was created on*. For example, the **machine code** for a program on Windows will not run on your IPad, because their metal components and systems are too different*.

___

However, in **interpreted** languages, a program called the **interpreter** "translates" the **source code** into **byte code***. **Byte code** still cannot be understood by the computer, but the **interpreter** itself is able to understand it and, because it's already a program, execute instructions.
```
 _____________       ___________
| Source Code | --> | Byte Code |
|_____________|     |___________|
                          |
                          V
    Computer    <-- [Interpreter]
```
Unlike **compiled** languages, **Interpreted** languages require the **interpreter** to run*. This is sometimes a disadvantage, as the additional weight of the **interpreter** (called **overhead**) makes the program slower to run compared to pure **machine code***. However, an advantage of this design is that many **interpreted** languages only have to be "translated" once to **byte code**, and that **byte code** can be run on any device with the correct **interpreter***.

___

Python is an **interpreted** language and requires the use of the **Python Interpreter**.  
Many code editors will automatically launch the **Python Interpreter** for you.
## About Files
Your **source code** is contained within a file. Think of a file as a piece of paper.  
Python files end in `.py`. *Everything that comes before the `.` is the program name, and can contain characters A-Z, a-z, 0-9, and the symbols "-", "_", and ".".  
We typically call the main file `main.py`.
## Basics
Open your main file, click on the editor, and begin coding!  
Your editor may provide tips as you type. Most will automatically fill things in if you press the tab key.
### Hello World
This is the most basic Python program. It outputs the text "Hello, world!" to the **terminal** (mysterious black or white colored box).
```py
print("Hello, world!")
```
Here, we make use of the `print` function. This function is used to output stuff to the **terminal**. The **terminal** is the most basic form of output*.
## IO
IO stands for "input & output". The `print` function is an example of `output`. We can get input from the terminal using the `input` function.
```py
input("Enter something: ")
```
Now the program will wait for you to type something in the **terminal** before exiting. Similar to the `print` function, we can specify what text appears.
### Comments
Comments are parts of the **source code** which the **interpreter** ignores.  
In Python, everything past the pound symbol ("#") is considered a comment.
```py
# This is a comment before we print.
print("Hello, world!") # This is a comment while we print.
# This is a comment after we print.
```
We can also make multiline comments by using three double quotation marks.
```py
"""
Everything in here
is a comment.
"""
print("Hello, world!")
"""
This is also
a comment
"""
```
### Errors
The **Python Interpreter** is very strict about how a program should be written. This is because if it assumes how to correct a mistake, it may make the mistake worse*.  
When you do something wrong the **interpreter** will print an error message to the **terminal** describing what you did wrong and where the problem is.  
*Important*: Many beginners ignore error messages because they look scary. Do not ignore error messages. Try to understand what it says, and search the internet if you need help.

Let's take a look at a possible error message with the `print` function.
```py
 print("Hello, world!")
# Notice, there is an extra space before `print`!
```
Error:
```
  File "main.py", line 1
    print("Hello, world!")
IndentationError: unexpected indent
```
Here's what we know:
- The error is in `main.py`.
- It's at line 1.
- There was an unexpected indent.
What does this mean?:
- `print("Hello, world!")` has an unexpected indent.
How to fix it:
- Remove the space before the `print`.

As we see, the way you type code greatly affects whether you will receive an error message. You should adhere to type exactly as the examples in this guide show until you're comfortable enough.  

Sometimes the **interpreter** will not find errors immediately, and will instead give you an error as it is running the program. This is called a **runtime exception***.

___

Here are some examples of code with errors:
```py
print("Hello, world!)
# Error: SyntaxError: unterminated string literal --> missing the last double-quote.
```
```py
print("Hello, world!
")
# Error: SyntaxError: unterminated string literal --> the last double-quote is on the wrong line.
```
```py
pri nt("Hello, world!)
# Error: SyntaxError: invalid syntax --> there's an extra space in `print`.
```
```py
print("Age of Yoda:" 500)
# Error: SyntaxError: invalid syntax --> there should be a comma before the 500.

# Correct
print("Age of Yoda:", 500)
```
You try, correct the code below (there are multiple errors):
```py
    print My name is Alice.") print("My name is Bob.) 500
```
### Vocabulary
Here are some terms you may want to know before continuing:
parenthesis   --> ()
brackes       --> []
curly braces  --> {}
dot           --> .
bang          --> !
pound         --> #
modulo        --> %
carat         --> ^
ampersand     --> &
asterisk      --> *
hyphen        --> -
colon         --> :
forward slash --> /
backslash     --> \
## Variables
# About Variables
Variables are names used to represent data to store.  
In Python, variable names cannot:
- Have spaces.
- Start with a number.
- Contain symbols other than A-Z, a-z, 0-9, and "_".

Here are some valid variable names:
- age_of_yoda
- favorite_food
- Dog_1
- Cat_2
- FISH_3000_V

Here are some invalid variable names:
- i like ice cream
- 123alice
- 456BOB
- obiwan.kenobi
- `!@#$%^&*`

___

The type of data a single variable can contain in Python is diverse. These are the most basic **data types**.  
The **integer**, **float**, and **boolean** are referred to as **primitive data types**.
## Integers
An **integer** is a whole number.  
We can store an **integer** into a variable and then output it with the print function.
```py
num = 5
print("Number:", num) # Outputs "Number: 5".
```
The equals sign in `num = 5` is called the **assignment operator** - because we're assigning the value of `5` to `num`.  
Also note that we can make the `print` function output multiple things by separating them with ", ".
## Floats
Also known as **floating-point** numbers, a **float** is a real number with digits going past the decimal point.  
```py
pi = 3.14159
print("The value of PI is:", pi) # Outputs "The value of PI is: 3.14159".
```
It's called "floating-point" because the decimal point can float to the left or right*.  
There are important characteristics of **floats** which will be covered in the math section.
## Booleans
A **boolean**, or **bool**, is useful for representing the state of something. It can only be one of two values: `True` or `False`.
```py
are_you_alive = True
print("Alive?:", are_you_alive) # Outputs "Alive?: True".
death_star_destroyed = False
print("Mission Status:", death_star_destroyed) # Outputs "Mission Status: False".
```
Notice that there are no quotation marks around `True` or `False`.
## Strings
**Strings** store characters. Python has the advantage of being able to store all possible characters*.  
**Strings** can be surrounded by either double-quotes or single-quotes.
```py
their_names_are = "Alice and Bob"
print(their_names_are) # Outputs "Alice and Bob".
darth_vader = 'Anakin Skywalker' # Single-quotes also work. There is no difference.
print(darth_vader) # Outputs "Anakin Skywalker".
```
To make a **string** spanning multiple lines, use three quotes.
```py
haiku = """I'd like ice cream now.
Please give me some soon, thank you.
Yum, it's very nice.
"""
print(haiku)
# Outputs:
# (insert poem here)
```
### Characters
In other programming languages, there is an additional **primitive data type** called the **character** or **char**. Like its name suggests, it stores a single character. In Python, **strings** and **chars** are the same thing, but it's important to know the distinction.
## Tuples
A **tuple** is a collection of values or other variables. The number of values, and the values themselves in a **tuple** cannot change - this is called **immutable**. In other languages, it's called an **array** (though the values inside an **array** may be modified).  
Each value in the **tuple** is separated by ", " and is called an **element**. All elements are contained withing the parenthesis.  
Note that a **tuple** makes a copy of the variables given to it.
```py
my_pets = ("cat", "fish", "catfish")
print(my_pets) # Outputs "('cat', 'fish', 'catfish')".
```
When **variables** are used to create a **tuple**, those variables are usually copied.
> There are some exceptions, such as lists and objects.

```py
friend_1 = "Alice"
friend_2 = "Bob"
friend_3 = "Mace Windu"
friends = (friend_1, friend_2, friend_3)

friend_3 = "Yoda"

print(friend_1, friend_2, friend_3)
print(friends)

# Outputs:
# Alice Bob Yoda
# ('Alice', 'Bob', 'Mace Windu')
# Tuples make copies of variables.
```
We can access the value of an **element** at a specific position, called a **index**. This can be one using the **subcript operator**, where the **index** of the **element** is inclosed in double brackets.  
Note that **indices** count up from 0!
```py
my_pets = ("cat", "fish", "catfish")
print(my_pets[0]) # Outputs "cat", the 1st element.
print(my_pets[1]) # Outputs "fish", the 2nd element.
print(my_pets[2]) # Outputs "catfish", the 3rd element.
```
If an **index** outside the bounds of the **tuple** is used, Python will **throw a runtime exception**.
Finally, we can find the length of a **tuple** by calling the `len` function, which is like `print`. We will cover more about functions later.
```py
my_pets = ("cat", "fish", "catfish")
num_pets = len(my_pets)
print("# Pets:", num_pets) # Outputs "# Pets: 3".
```
## Lists
Similar to a **tuple**, a **list** can store a number of other values. Where a **list** differs from a **tuple** is that its **elements** can be modified (called **mutable**) and it can change size.  
In other programming languages, this is referred to as a **linked list**, **vector**, more more generally, **variable-length array**.  
A **list** is created very similarly to a **tuple**, but it uses brackets instead.
```py
todo_list = ["eat", "sleep", "work"]
print(todo_list) # Outputs "['eat', 'sleep', 'work']".
```
The **elements** inside a **list** can be accessed *and changed* through the **subscript operator**.
```py
todo_list = ["eat", "sleep", "work"]
todo_list[0] = "tea"
todo_list[1] = "speel"
todo_list[2] = "krow"
print(todo_list) # Outputs "['tea', 'speel', 'krow']".
```
The length of a **list** can also be accessed through the `len` function. You will also receive a **runtime exception** if attempting to use an **index** outside the **list**'s bounds.  
We can add additional elements to the **list** by using a special kind of function called a method. We will discuss more about methods later.
```py
todo_list = ["eat", "sleep", "work"]

# The `append` method can only be used on lists*.
todo_list.append("play")

print(todo_list) # Outputs "['eat', 'sleep', 'work', 'play']".
```
**Lists** are special in that they are always **passed by reference**. This means that two variables can share the same **list**!
```py
list_1 = [1, 2, 3]
list_2 = list_1
list_1.append(4)

print(list_1) # Outputs "[1, 2, 3, 4]".
print(list_2) # Outputs "[1, 2, 3, 4]".
# Both variables are updated because they share the same list!
```
Here are some other useful methods to use with **lists**. Note that there are more methods available than listed here.
```py
todo.clear() # Clears everything in todo.
todo_copy = todo.copy() # Makes a copy of todo and assigns the copy to todo_copy. This way, the two variables have their own list.
todo.insert(index, value) # Inserts the value into the list at index.
todo.pop(index) # Removes the value at index.
todo.sort() # Sorts the list ascending. By alphabet for strings and value for numbers.
```
> Note that, unlike many other languages, a Python **list** can contain multiple **data types**, as such:
```py
stuff = ["Alice", True, "Bob", 0, 2.71, False]
```
> But this is not recommended.
### Multidimensional Arrays
Let's say you want to model a chess board.  
To do this, we need to represent a grid.  
This can be done by making a **list** of other **lists**, called a **multidimensional list / array**.
```py
# Python allows us to make lists cross multiple lines. Be careful when doing this though.

# This is a 3x3 grid of zeroes.
grid = [
    [0, 0, 0], 
    [0, 0, 0], 
    [0, 0, 0]
]

# Change the value at row #2, column # 2, to 5. Remember that indices start from 0, so 1 --> #2.
grid[1][1] = 5

# The grid is now:
"""
[0, 0, 0], 
[0, 5, 0], 
[0, 0, 0]
"""
```
Be careful when using the `copy` method on **multidimensional lists**, as it won't copy the **lists** contained within!  
These **lists** can also be expanded into three dimensions, four dimensions, five, etc!
## Dictionaries
The **Dictionary**, known in other languages as the **map** or **hash map**, are a more advanced **data type** which not even the *AP Computer Science A* exam bothers covering, so we'll get through it fast. Take care to research it in your own time if it's utility strikes you.  
Simply put, a **dictionary** is what it's name implied. In a real dictionary, if you're looking for a word, the table at the front tells you which page it's on. Think of a Python **dictionary** as a table that gives you a certain value for a specific search.  
The **dictionary** uses curly braces.  
For dictionaries, the value inside the subscript operator is called the **key**. Each **key** is *unique* and maps to a value.
```py
prices = {
    "apple":1.5, 
    "banana":1.0, 
    "cherries":3.0, 
    "durian":10.0
}

print(prices["cherries"]) # Outputs "3.0".
```
## Sets
A **set** is literally a **dictionary** but it only has **keys**. Because **keys** are unique, a **set** will never have duplicate **elements**.
```py
leaderboard = {"alice64", "bob32", "obiwan2048"}
```
## Literals
A literal is a value without a variable name.  
We've actually already used literals, those are usually the values to the right of the **assignment operator**.
Here's an example.
```py
# Outputs "500", even though the value 500 doesn't have a variable.
# After the print finishes, the value 500 is destroyed because it doesn't have a variable to hold it.
print("Age of Yoda:", 500)
```
## Casting
We can convert one **primitive data type** into another through a process called **casting**.  
Note that, if you attempt to cast one **data type** to another but it doesn't make sense to do so, the **interpreter** will **throw a runtime exception**.
```py
# Convert a string into an integer.
num = int("12345")
# Convert a float into a string.
text = str(2.71)
# We normally don't cast anything to bools.
b = bool(num)
# We cannot cast to non-primitive data types such as tuples, lists, etc.
```
When converting from a **float** to an **integer**, the **float** is *floored*, basically it loses everything past the decimal point.
```py
num = int(3.14159)
print(num) # Outputs "3".
```
## None
There is a special kind of value in Python called `None`. In other languages, it's often called `null`.  
Use this value when you have a variable which you plan to store something into, but don't want to yet.
```py
what_do_i_want_to_do_when_i_grow_up = None
# Maybe you'll figure it out later in life.
```
Be careful with `None`, as it's not "compatible" with interacting with other **data types** or functions.
## Binary and Hex
We can convert **integers** to **string** representations from other number systems, such as **binary** (base 2), **hexadecimal** (base 16), **octal** (base 8).
> Our normal number system is called **decimal** (base 10).

```py
print(bin(64))
print(hex(64))
print(oct(64))

# Outputs:
"""
0b1000000
0x40
0o100
"""
```
You won't need to understand how these number systems work for now.
## Object Oriented Programming
Python is an **object oriented** programming language. That means that data can be **abtracted**, or contained and represented, by **objects***.  
For example, you are a person. As a person, you have ~~organs~~ a name, age, and address. If we want to represent a bunch of people, we could have three separate **lists** for each one of these properties, and associate each person by their index for these three **lists**.  
However, it would make more sense to have a single **list** which would contain a **data type** which itself represents a person.  
**Object oriented programming** allows us to create our own **data types** by combining other **data types**.

___

If you are confused by the following, it may help to refer to the functions section of this guide.  

First, to model our people, we need a **class**. A **class** can be thought of as a blueprint for making **objects**. It itself is not an **object** and contains no data, but rather outlines what is required to make an **object** from that **class**.
```py
class Person:
    def __init__(self, name, age, address):
        self.name = name
        self.age = age
        self.address = address
```
Here's what's happening:
1. We make a class called `Person`.
2. We make a special kind of **method** called a **constructor**. A **method** is a kind of function which is specific to a **object**. This method is executed whenever a new `Person` is created (in the program).
3. The variable `self` contains the object being created. We assign each of the values provided to the **method** to `self`.

Now we can use our class.
```py
alice = Person("Alice", 21, "The Cartesian Coordinate Plane")
bob = Person("Bob", 21, "The Polar Coordinate Plane")
people = [alice, bob]
```
Additional **methods** can be assigned to the `People` **class** to add functionality.
```py
class Person:
    def __init__(self, name, age, address):
        self.name = name
        self.age = age
        self.address = address
    
    def birthday(self, new_age):
        self.age = new_age
```
```py
alice = Person("Alice", 21, "The Cartesian Coordinate Plane")

# We could also change Alice's age by using `alice.age = 22`, but methods are sometimes preferred*.
alice.birthday(22)

print(alice.age) # Outputs "22".
```
Using our **list** from earlier, we can also call methods on the elements within the **list**.
```py
# Recall that `people[1]` contains `bob`.
people[1].birthday(22)
print(bob.age) # Outputs 22.
```
Note that, like **lists** (and actually **tuples** too), **objects** are **passed by reference** and so the variable `bob` and `people[1]` contain the same `Person` **object**.
# Arithmetic and Logic
## Math in Computers
Computers store numbers using special circuits called **registers***.  
These registers, being physical things, can only hold a specific number of bits, which are represented by the "1s & 0s" from earlier. Many computers nowadays are 64-bit, which means that a register can hold 64-bits of information at a time*.  
> Some older computers are only 32-bit.

This means that in some programming languages, there is a maximum and minimum number that computers can store.  
Python does not have this limitation, but it's important to understand that computers do not "perceive" numbers that way we do.
## Basic Operators
Addition, subtraction, multiplication, division, and powers can be done through arithmetic operators.
```py
a = 5 + 5 # a is 10
b = a - 5 # b is 5
a = a * 10 # a is now itself multiplied by 10 --> a is 100
c = a / 3 # c is 33.333333333333336
d = a // 3 # d is 33
a = a ** 0 # a is now itself to the power of 0 --> a is 1
```
There are two important things to notice here. 
1. `c` should be repeating to infinity, but because a computer cannot represent an infinite number of digits, it simply stops at some point.
2. `d` is 33. There are two kinds of division; `d`'s division automatically *floors* the **float** to an **integer**. This kind of division where we discard everything past the decimal place is actually very common in other languages.
## Operator Precedence
(Also see operator associativity.)
Mathematical operations in Python usually take on the same order of operations in normal Algebra. Likewise, surrounding an expression in parenthesis makes it to be evaluated prior to its surroundings.  
```
Precedence / Priority
Highest <--------------------> Lowest
Parenthesis, Arithmetic, Comparison, Boolean
```
## The `math` Module
Some more advanced mathematical operations can be accessed through the `math` **module**. We'll cover more about **modules** in a later section.
```py
import math

print(math.sqrt(64)) # Outputs "8.0".

# Triginometric functions, for example, can also be accessed through the math module.
```
## Comparison Operators
**Comparison operators** are used to compare variables and values against each other. 
