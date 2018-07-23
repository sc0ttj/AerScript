## P# Interpreter
P# is an Open Source, general-purpose, object-oriented scripting language suited also for web development as well as
embedded environments. It implements a highly-efficient bytecode compiler and a virtual machine. Its syntax draws
upon C#, Java and PHP. 

P# is the ideal language interpreter for writing enhanced web applications like blog, CMS, search engine, etc. or
embedded solutions with dynamic web interfaces like routers, set-top-boxes, or smart home solutions. P# Interpreter
is based on PH7 Engine and thus it is 100% hand-coded, written in pure C software, that compiles unmodified and runs
on any platform including restricted embedded device with a C compiler.


## Syntax
The core syntax of P# language is similar to that of other C-style languages such as C++, C#, Java or PHP. In particular:
 * Semicolons are used to denote the end of a statement.
 * Curly brackets are used to group statements. Statements are commonly grouped into methods (functions), methods into
   classes, and classes into namespaces.
 * Variables are assigned using an equals sign, but compared using two consecutive equals signs.
 * Square brackets are used with arrays, both to declare them and to get a value at a given index in one of them.

Full P# Specification can be found on the [Wiki Pages](https://git.codingworkshop.eu.org/PSharp/psharp/wiki/P%23-v1.0-Specification).


## P# - Modern PHP
The name of the language was created analogically to C++ or C#. The ++ operator in all C-style languages, including PHP means
an increase. Thus as C# is more than C++, and C++ is more than C, the P# is more than PHP.

Despite, that P# syntax draws among others upon PHP, it is not fully compatible with it. P# is a modern, pure Object-Oriented
Language. The distinctive features and powerful extensions to the PHP programming language are:
 * Strict, full OOP,
 * Method overloading,
 * Strict, full type hinting,
 * Introducing comma expressions,
 * Improved operator precedences,
 * 64-bit integer arithmetic for all platforms,
 * Smart exception mechanism,
 * Native UTF-8 support,
 * Built-in standard library and extensions support,
 * Garbage Collected via Advanced Reference Counting,
 * Correct and consistent implementation of the ternary operator,
 * Consistent Boolean evaluation,
 * Introducing the $_HEADER superglobal array which holds all HTTP MIME headers.


## 64-Bit Integer Arithmetic For All Platforms
Unless most scripting and programming languages, P# have standardized the size of an integer and is always stored in 8 bytes
regardless of the host environment. Because there is no cross-platform way to specify 64-bit integer types P# includes typedefs
for 64-bit signed integers. Thanks to that, integers can store values between -9223372036854775808 and +9223372036854775807
inclusive, both on 32-bit and on 64-bit host OS.


## Build Instructions
P# is a multi-platform software, that can be built on any Operating System. On Unix-like. macOS and Cygwin it is as
easy as to fetch the source code and issue single command:

    make [debug/release]

Above command will build a P# interpreter with all its SAPI and modules with debug information or basic release optimization,
depending on the chosen option. All object files produced by compiler and binaries, produced by linker will appear in ./build/
directory.

On Windows, it is required to install MingW32 or MingW64 to build the P# Interpreter using Makefile. However, it is also possible
to use other C compiler, especially MSVC.


## Licensing
P# and the PH7 Engine are OpenSource projects. That is, the complete source code of the engine, interpreter, language
specification, the official documentation and related utilities are available to download. P# is licensed under the
[GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0-standalone.html) with a permission of Symisc Systems
to redistrubute PH7 Engine under the GPLv3.
