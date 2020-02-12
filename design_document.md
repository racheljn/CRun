#### Project Description:
Our project would be creating a new kernel command for compiling and then running C language programs in the terminal.
Our command:		run program.c <command line args>
Without our command:	gcc program.c -o program.c && ./a.out <command line args>

#### Design Rationale:
This modification will eliminate the need to type a needlessly long command to compile and run c programs, thus increasing the efficiency of developing and testing C programs.

#### Linux Modules:
We will modify the gcc module.

#### New Modules:  
We will export a new module called run.
