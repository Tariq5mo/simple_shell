# Simple Shell Implementation

[![C Language](https://img.shields.io/badge/Language-C-blue)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/License-MIT-green)](LICENSE)
[![Build Status](https://img.shields.io/badge/Build-Passing-success)](https://github.com/talalOmer/simple_shell)

## Overview

A lightweight UNIX command interpreter written in C, developed as part of the ALX Software Engineering program. This shell provides a command-line interface for users to interact with the operating system, supporting basic command execution, built-in commands, environment variable management, and more.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
  - [Interactive Mode](#interactive-mode)
  - [Non-Interactive Mode](#non-interactive-mode)
- [Command Syntax](#command-syntax)
- [Built-in Commands](#built-in-commands)
- [Project Structure](#project-structure)
- [Technical Details](#technical-details)
- [Implementation Tasks](#implementation-tasks)
- [Testing & Examples](#testing--examples)
- [Troubleshooting](#troubleshooting)
- [Developers](#developers)
- [Additional Resources](#additional-resources)
- [Learning Objectives](#learning-objectives)

## Features

- **Command Execution**: Execute standard Unix commands with arguments
- **Built-in Commands**:
  - `cd [directory]` - Change directory (supports relative and absolute paths)
  - `exit [status]` - Exit the shell with optional status code
  - `env` - Display all environment variables
  - `setenv VARIABLE VALUE` - Set or modify environment variables
  - `unsetenv VARIABLE` - Remove environment variables
- **Path Resolution**: Automatically searches for executables in PATH directories
- **Input Handling**:
  - Handles command lines with multiple arguments
  - Supports comments using `#` character
- **Error Handling**: Provides descriptive error messages with process IDs
- **Memory Management**: Implements proper allocation/deallocation to prevent leaks
- **Signal Handling**: Proper handling of signals like Ctrl+D (EOF)

## Installation

### Prerequisites

- Linux/Unix-based operating system
- GCC compiler with C99 support
- Make utility (optional)

### Build from Source

```bash
# Clone the repository
git clone https://github.com/talalOmer/simple_shell.git
cd simple_shell

# Compile the shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# Make executable
chmod +x hsh
```

## Usage

### Interactive Mode

Launch the shell:

```bash
./hsh
```

You'll see the prompt `($)` where you can enter commands:

```bash
($) ls -l
total 100
-rwxr-xr-x 1 root root 16384 Mar 15 12:34 hsh
-rw-r--r-- 1 root root  3214 Mar 15 12:32 main.c
-rw-r--r-- 1 root root  2874 Mar 15 12:33 shell.c
($) pwd
/home/user/simple_shell
($) exit
```

### Non-Interactive Mode

Execute commands from other programs or files:

```bash
# Using echo
echo "ls -la" | ./hsh

# Using a file
cat commands.txt | ./hsh

# Or direct execution
./hsh < commands.txt
```

## Command Syntax

The shell supports various command formats:

- **Basic Commands**: `command [arguments]`
- **Path Commands**: Commands in PATH like `ls` or with full paths like `/bin/ls`
- **Built-ins**: Special commands implemented in the shell itself
- **Comments**: Text following `#` is ignored

## Built-in Commands

| Command | Syntax | Description |
|---------|--------|-------------|
| `exit` | `exit [status]` | Exits shell with optional status code (0-255) |
| `env` | `env` | Displays all environment variables |
| `setenv` | `setenv VARIABLE VALUE` | Creates or updates an environment variable |
| `unsetenv` | `unsetenv VARIABLE` | Removes an environment variable |
| `cd` | `cd [DIRECTORY]` | Changes current directory. Without args goes to HOME |

## Project Structure

```plantxt
simple_shell/
├── build_path.c    # PATH environment processing, linked list creation
├── built-in.c      # Built-in command handlers (exit, env)
├── cd.c            # Directory navigation implementation
├── find_path.c     # PATH searching, string utilities
├── free_list.c     # Memory management for linked lists
├── main.h          # Header file with function prototypes
├── requirement.c   # Utility functions (string comparison, number conversion)
├── setenv.c        # Environment variable management functions
├── shell.c         # Main shell loop, command execution
├── strtoargs.c     # Command string parsing and memory management
└── README.md       # Project documentation
```

## Technical Details

### Requirements

- **Coding Standards**:
  - Compliant with Betty style guide
  - No more than 5 functions per file
  - All header files are include-guarded

- **Compilation**:
  - Ubuntu 20.04 LTS using GCC
  - Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`

- **Execution Environment**:
  - Ubuntu 20.04 LTS
  - Memory management: No leaks allowed

### Allowed Functions and System Calls

| Category | Functions |
|----------|-----------|
| **Process Control** | `fork`, `wait`, `waitpid`, `execve`, `exit` |
| **File Operations** | `open`, `close`, `read`, `write`, `access` |
| **Memory Management** | `malloc`, `free` |
| **Directory Operations** | `chdir`, `getcwd`, `closedir`, `opendir`, `readdir` |
| **String Manipulation** | `strtok` |
| **Error Handling** | `perror`, `strerror` |
| **Other** | `isatty`, `stat` |

## Implementation Tasks

Our implementation follows a progressive development approach, with tasks ranging from basic shell functionality to advanced features:

1. **Core Shell (Tasks 0-4)**
   - Basic command parsing and execution
   - PATH resolution
   - Error handling fundamentals

2. **Environment and Builtins (Tasks 5-10)**
   - Environment variable management
   - Implementation of builtin commands
   - Directory navigation

3. **Advanced Features (Tasks 11-16)**
   - Command separators and logical operators
   - Variable substitution
   - Comment handling
   - File input processing

## Testing & Examples

### Basic Command Execution

```bash
($) ls
README.md  hsh  main.h  shell.c
($) pwd
/home/user/simple_shell
($) echo Hello, world!
Hello, world!
```

### Built-in Commands

```bash
# Environment variables
($) env
USER=root
HOME=/root
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
...

# Setting environment variables
($) setenv TEST_VAR test_value
($) env | grep TEST_VAR
TEST_VAR=test_value

# Changing directories
($) cd /tmp
($) pwd
/tmp
```

### Error Handling

```bash
($) nonexistent_command
./hsh: 1: nonexistent_command: not found
($) exit abc
./hsh: 1: exit: Illegal number: abc
```

## Troubleshooting

### Common Issues

| Issue | Solution |
|-------|----------|
| **Command not found** | Check spelling and PATH environment variable |
| **Permission denied** | Ensure file is executable (`chmod +x file`) |
| **Segmentation fault** | May indicate memory access issues - report to developers |

### Reporting Bugs

If you encounter any issues, please report them by opening an issue on GitHub with:

1. Command executed
2. Expected output
3. Actual output
4. System information

## Developers

- **Talal Omer** - [GitHub](https://github.com/talalOmer) - Lead Developer
- **Tariq Omer** - [GitHub](https://github.com/Tariq5mo) - System Architecture

## Additional Resources

- [UNIX Shell Documentation](http://man7.org/linux/man-pages/man1/sh.1.html)
- [Writing a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)
- [Linux System Calls Handbook](http://man7.org/linux/man-pages/man2/syscalls.2.html)
- [The Linux Programming Interface](https://man7.org/tlpi/)

---

## Learning Objectives

By working with this project, developers will gain understanding of:

- **Process Control**: How the shell manages processes, PIDs, and PPIDs
- **Memory Management**: Proper allocation and deallocation in C
- **File Descriptors**: Working with standard I/O and file operations
- **Command Parsing**: Text processing and tokenization techniques
- **Environment Variables**: How they're stored, accessed, and manipulated
- **System Calls**: The difference between functions and system calls

This project serves as a comprehensive introduction to system programming concepts and provides practical experience with fundamental Unix operations.
