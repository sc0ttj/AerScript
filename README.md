## Aer Interpreter
Aer (/ɛə/ from Latin: aer, meaning air) is a lightweight, OpenSource, general-purpose, object-oriented scripting  programming
language suited also for web development as well as embedded environments. It implements a highly-efficient bytecode compiler
and a virtual machine. The term Aer is used interchangeably with AerScript. Its syntax draws upon C++, C#, Java and PHP.

Aer is the ideal language interpreter for writing enhanced web applications like blog, CMS, search engine, etc. or
embedded solutions with dynamic web interfaces like routers, set-top-boxes, or smart home solutions. Aer Interpreter
is based on PH7 Engine and thus it is 100% hand-coded, written in pure C software, that compiles unmodified and runs
on any platform including restricted embedded device with a C compiler.


## Syntax
The core syntax of Aer language is similar to that of other C-style languages such as C++, C#, Java or PHP. In particular:
 * Semicolons are used to denote the end of a statement.
 * Curly brackets are used to group statements. Statements are commonly grouped into methods (functions), methods into
   classes, and classes into namespaces.
 * Variables are assigned using an equals sign, but compared using two consecutive equals signs.
 * Square brackets are used with arrays, both to declare them and to get a value at a given index in one of them.

Full Aer Specification can be found on the [Wiki Pages](https://git.codingworkshop.eu.org/AerScript/aer/wiki/Aer-v1.0-Specification).


## AerScript - Modern PHP
Despite, that Aer syntax draws among others upon PHP, it is not fully compatible with it. Aer is a modern, pure Object-Oriented
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
Unless most scripting and programming languages, Aer have standardized the size of an integer and is always stored in 8 bytes
regardless of the host environment. Because there is no cross-platform way to specify 64-bit integer types Aer includes typedefs
for 64-bit signed integers. Thanks to that, integers can store values between -9223372036854775808 and +9223372036854775807
inclusive, both on 32-bit and on 64-bit host OS.


## Native UTF-8 Support
Aer has builtin native support for UTF-8 characters. That is, you are not restricted to use only plain-English to name variables
or methods. Any UTF-8 encoded natural language can be used without the need for ICU or any other internationalization package.


## Build Instructions
Aer is a multi-platform software, that can be built on any Operating System. On Unix-like. macOS and Cygwin it is as
easy as to fetch the source code and issue single command:

    make [debug/release]

Above command will build a Aer interpreter with all its SAPI and modules with debug information or basic release optimization,
depending on the chosen option. All object files produced by compiler and binaries, produced by linker will appear in ./build/
directory.

On Windows, it is required to install MingW32 or MingW64 to build the Aer Interpreter using Makefile. However, it is also possible
to use other C compiler, especially MSVC.


## Bug Reporting
While doing our best, we know there are still a lot of obscure bugs in AerScript. To help us make Aer the stable and solid
product we want it to be, we need bug reports and bug fixes. If you can't fix a bug yourself and submit a fix for it, try
to report an as detailed report. When reporting a bug, you should include all information that will help us understand what's
wrong, what you expected to happen and how to repeat the bad behavior. You therefore need to tell us:
 * your operating system's name and version
 * what version of Aer Interpreter you're using
 * anything and everything else you think matters.
Tell us what you expected to happen, what did happen and how you could make it work another way. Dig around, try out and test.
Then, please include all the tiny bits and pieces in your report. You will benefit from this, as it will enable us to help you
quicker and more accurately.


## Licensing
Aer and the PH7 Engine are OpenSource projects. That is, the complete source code of the engine, interpreter, language
specification, the official documentation and related utilities are available to download. Aer is licensed under the
[GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0-standalone.html) with a permission of Symisc Systems
to redistribute PH7 Engine under the GPLv3.
