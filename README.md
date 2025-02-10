# Simple Shell Implementation

## Overview

A lightweight UNIX command interpreter written in C, developed as part of the ALX Software Engineering program. This shell supports basic command execution, built-in commands, and environment variable management.

## Quick Start

```bash
# Compile the shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# Run in interactive mode
./hsh

# Run in non-interactive mode
echo "/bin/ls" | ./hsh
```

## Features

- **Command Execution**: Execute standard Unix commands
- **Built-in Commands**:
  - `cd` - Change directory
  - `exit` - Exit the shell
  - `env` - Display environment variables
  - `setenv` - Set environment variables
  - `unsetenv` - Unset environment variables
- **Path Resolution**: Automatically finds executables in PATH
- **Error Handling**: Comprehensive error messages
- **Memory Management**: No memory leaks
- **Comment Support**: Lines starting with '#'

## Project Structure

```
.
├── shell.c          # Main shell implementation
├── built-in.c       # Built-in command handlers
├── cd.c            # Directory navigation
├── find_path.c     # PATH resolution
├── strtoargs.c     # Command parsing
├── setenv.c        # Environment variable management
├── main.h          # Header definitions
└── README.md       # Documentation
```

## Technical Details

### Requirements

- **Allowed editors:** `vi`, `vim`, `emacs`
- **Compilation:** Ubuntu 20.04 LTS using `gcc` with options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- **Code Style:** Betty style compliant
- **Memory:** No memory leaks
- **Functions:** Maximum 5 functions per file
- **Headers:** Include guarded

### Allowed Functions and System Calls

- Basic I/O: `access`, `read`, `write`
- Process Control: `fork`, `wait`, `waitpid`, `execve`
- Memory Management: `malloc`, `free`
- Directory Operations: `chdir`, `getcwd`, `opendir`, `readdir`, `closedir`
- String Manipulation: `strtok`
- Error Handling: `perror`, `exit`

## Development and Testing

### Interactive Mode
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

### Non-Interactive Mode
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
```

## Implementation Tasks

1. **Basic Shell (0.1-0.4)**
   - Command interpreter implementation
   - Argument handling
   - PATH resolution
   - Exit built-in

2. **Environment Management (1.0)**
   - Env built-in implementation
   - Environment variable handling

3. **Advanced Features**
   - Custom getline implementation
   - Built-in command enhancements
   - Logical operators
   - Variable replacement
   - Comment handling
   - File input support

## Tasks

### 0. Betty would be proud
- Follow the Betty style guide
- No errors from Betty-style checks

### 1. Simple Shell 0.1
- Display a prompt and wait for user input
- Execute commands with their arguments
- Handle errors
- Handle the "end of file" condition (Ctrl+D)

### 2. Simple Shell 0.2
- Handle command lines with arguments
- Implement PATH handling
- Don't call fork if command doesn't exist

### 3. Simple Shell 0.3
- Handle the PATH
- Implement fork must not be called if command doesn't exist

### 4. Simple Shell 0.4
- Implement the exit built-in
- Usage: exit
- No arguments handling needed

### 5. Simple Shell 1.0
- Implement the env built-in
- Print current environment

### 6. Simple Shell 0.1.1
- Write your own getline function
- Use a buffer to read many chars at once
- Minimize the number of read system calls

### 7. Simple Shell 0.2.1
- Handle arguments for the built-in exit
- Usage: exit status

### 8. Simple Shell 0.4.1
- Handle Ctrl+C
- Shell should not quit when user inputs ^C

### 9. setenv, unsetenv
- Implement the setenv and unsetenv builtin commands
- setenv: Initialize/modify environment variable
- unsetenv: Remove environment variable

### 10. cd
- Implement the builtin command cd
- Handle the command line argument
- Update PWD environment variable

### 11. ;
- Handle the commands separator ;

### 12. && and ||
- Handle the && and || shell logical operators

### 13. alias
- Implement the alias builtin command
- Usage: alias [name[='value'] ...]

### 14. Variables
- Handle variables replacement
- Handle $? variable
- Handle $$ variable

### 15. Comments
- Handle comments (#)

### 16. File as input
- Usage: simple_shell [filename]
- Execute commands from file

## Team

- **Talal Omer**
  - GitHub: [talalOmer](https://github.com/talalOmer)
- **Tariq Omer**
  - GitHub: [tariqOmer](https://github.com/Tariq5mo)

## Additional Resources

- [Unix Shell Documentation](http://man7.org/linux/man-pages/man1/sh.1.html)
- [Writing a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)
- [Linux System Calls](http://man7.org/linux/man-pages/man2/syscalls.2.html)

---

## Learning Objectives

By the end of this project, developers should understand:
- Unix shell operation and design
- Process management (PID, PPID)
- Environment manipulation
- System calls vs. functions
- Program execution with execve
- EOF handling

For detailed implementation requirements and specifications, refer to the task sections above.
