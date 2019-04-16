# 0x15 C - Simple Shell

---
## Description
A simple UNIX command interpreter, this version with the process of SH shell can run from main commands and work with the flags of this. In this document, you will find the main characterizes at the functionality of this program.

---

### Requirements
You need a SO based in linux. This program was tested on virtual machine Ubuntu 14.05.5 LTS

* you can find in this link of [Vagrant] (https://app.vagrantup.com/ubuntu/boxes/trusty64)



### Install
* First you need clone this repository in your machine, [The link] (https://github.com/Noeuclides/simple_shell) or execute this line:
    ```
    $ git clone https: // github.com / Noeuclides / simple_shell.git
    ```
* Once cloned, you need to in the directory simple-shell, and compile:
    ```
    gcc -Wall -Werror -Wextra -pedantic * .c -o MiShell
    ```
* Then you execute the program:
    ```
    . / MiShell
    ```
There will show the promp of the program:
   ```
   (o _ o)
   ```


### Testing
* You can test with interactive mode:
```
$ ./hsh
($) / bin / ls
hsh main.c shell.c
($)
($) exit
$
```
* But also in non-interactive mode:
```
$ echo "/ bin / ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/ bin / ls
/ bin / ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

### [Style code: [betty]] (https://github.com/holbertonschool/Betty)

The code is rigth folling the standard ISO implemented in the Betty style. Follow the link to see the propertys of the style.


### Content

You'll find in the directory the following files:

|   **File**    |  **Decription**                       |
|---------------|---------------------------------------|
| | |
| | |
| | |
| | |


### Tools
* [Emacs.] (Https://www.gnu.org/software/emacs/)
* [vim] (https://www.vim.org/)
* [GDB (Debugger)] (https://www.gnu.org/software/gdb/)
* Coffe

### [functions]
*free_listint - function that free a list.
*prompt - function that start the prompt wait for user command and execute it.
*concat_path - function that concatenate path and verify if it exist.
*tok - function to eliminate delimiters of the string that the user write.
*quotes - function to eliminate quotes of the string that the user write.
*hijo_path - function that executes the command if it exist.
*_getenv - function that finds the PATH variable in the env.
*get_path - function to get the path of directories.
*linking_path - function that generates the linked list with the dir's PATH.
*print_env - function that prints a copy of the enviroment variables.
*handler - function that handles a signal(crtl + c).
### [more functions]
* Write a function that returns the sum of all the data (n) of a listint_t linked list.

### Notes
Special thanks to everybody- (to my mistress, to my apa)

### Authors
* ** Nicolas Martinez ** - [GitHub - Neuclides] (https://github.com/Noeuclides)
* ** Alejo-rey ** - [GitHub - Alejo-rey] (https://github.com/Alejo-Rey)