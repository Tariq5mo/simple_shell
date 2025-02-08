# 0x16. C - Simple Shell

This project is about creating a simple UNIX command interpreter in C as part of the ALX Software Engineering program. It focuses on understanding the basics of shell functionalities, process management, and system calls.

## Table of Contents

- [Introduction](#introduction)
- [Background](#background)
- [Team](#team)
- [Concepts](#concepts)
- [Learning Objectives](#learning-objectives)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [Testing](#testing)
- [Tasks](#tasks)
- [Authors](#authors)

---

## Introduction

This project involves writing a simple UNIX command interpreter, commonly known as a shell. The shell provides an interface for users to interact with the operating system by executing commands.

## Background

The Simple Shell project is a challenging and anticipated project that tests my understanding of:

- Basic programming concepts
- C programming language
- Engineering thinking
- Group work
- Learning how to learn

It is crucial to avoid copying code or looking at solutions from others. Focus on understanding and building the shell from scratch.

## Team

This project was completed in teams of two. Our team consists of:

- Talal Omer
- Tariq Omer

## Concepts

Key concepts covered in this project include:

- Team Projects and Pair Programming
- Understanding the UNIX shell
- Process management (PID, PPID)
- Environment manipulation
- System calls (execve, fork, wait)
- PATH variable
- Error handling

## Learning Objectives

By the end of this project, I should be able to explain the following without assistance:

- The creators of the original Unix operating system and the first UNIX shell.
- The inventor of the B programming language.
- The role and significance of Ken Thompson.
- How a shell operates.
- Understanding PID and PPID.
- Manipulating the environment of the current process.
- Distinguishing between functions and system calls.
- Creating processes.
- Understanding the prototypes of `main`.
- How the shell uses the PATH to locate programs.
- Executing programs using the `execve` system call.
- Suspending process execution until child termination.
- Understanding EOF (End-of-File).

## Requirements

### General

- **Allowed editors:** `vi`, `vim`, `emacs`
- **Compilation:** Ubuntu 20.04 LTS using `gcc` with options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files must end with a new line
- A `README.md` file is mandatory
- Code should adhere to the Betty style (checked using `betty-style.pl` and `betty-doc.pl`)
- No memory leaks
- Maximum 5 functions per file
- Header files should be include-guarded
- Use system calls only when necessary

### Output

- Your program must have the exact same output as `sh (/bin/sh)` and the same error output.
- The program name in error messages must match `argv[0]`.

### Allowed Functions and System Calls

- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `getpid` (man 2 getpid)
- `isatty` (man 3 isatty)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `stat` (__xstat) (man 2 stat)
- `lstat` (__lxstat) (man 2 lstat)
- `fstat` (__fxstat) (man 2 fstat)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)

## Compilation

my shell will be compiled using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Testing

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
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Tasks

### 0. Betty would be proud (mandatory)

Write code that passes the Betty checks.

### 1. Simple shell 0.1 (mandatory)

Write a UNIX command line interpreter.

- Usage: `simple_shell`
- Display a prompt and wait for the user to type a command.
- The prompt is displayed again each time a command has been executed.
- Command lines are simple, with no semicolons, pipes, or redirections.
- Command lines consist of only one word (no arguments).
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors and the “end of file” condition (Ctrl+D).
- Do not use the PATH, implement built-ins, or handle special characters.
- `execve` is the core part of your Shell.

### 2. Simple shell 0.2 (mandatory)

Simple shell 0.1 + Handle command lines with arguments.

### 3. Simple shell 0.3 (mandatory)

Simple shell 0.2 + Handle the PATH. `fork` must not be called if the command doesn’t exist.

### 4. Simple shell 0.4 (mandatory)

Simple shell 0.3 + Implement the `exit` built-in command.

### 5. Simple shell 1.0 (mandatory)

Simple shell 0.4 + Implement the `env` built-in command.

### 6. Simple shell 0.1.1 (#advanced)

Simple shell 0.1 + Write your own `getline` function.

### 7. Simple shell 0.2.1 (#advanced)

Simple shell 0.2 + You are not allowed to use `strtok`.

### 8. Simple shell 0.4.1 (#advanced)

Simple shell 0.4 + Handle arguments for the built-in `exit`.

### 9. setenv, unsetenv (#advanced)

Simple shell 1.0 + Implement the `setenv` and `unsetenv` builtin commands.

### 10. cd (#advanced)

Simple shell 1.0 + Implement the builtin command `cd`.

### 11. ; (#advanced)

Simple shell 1.0 + Handle the commands separator `;`.

### 12. && and || (#advanced)

Simple shell 1.0 + Handle the `&&` and `||` shell logical operators.

### 13. alias (#advanced)

Simple shell 1.0 + Implement the `alias` builtin command.

### 14. Variables (#advanced)

Simple shell 1.0 + Handle variables replacement.

### 15. Comments (#advanced)

Simple shell 1.0 + Handle comments (`#`).

### 16. File as input (#advanced)

Simple shell 1.0 + Your shell can take a file as a command line argument.

- `man sh`

## Authors

- Talal Omer
- Tariq Omer
