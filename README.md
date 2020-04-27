# CRun

### Purpose
CRun has a very simple purpose -- to no longer have to type "gcc {filename.c} -o filename && ./filename {params}, and instead to be able to simply type "./crun {filename.c} {params}" into you terminal whenever you want to compile and run a C program.

### How it works
CRun uses fork() and execvp() to create a new thread that compiles your C program in one thread and then executes the compiled program afterwards in another thread.\\CRun will always have the resulting a.out file be named the same name as your C file but without the ".c" at the end (for example helloWorld.c would compile a helloWorld executable).\\Before compiling your program crun will delete any instances of the resulting executable that may already exist in the directory to ensure that it runs the newest compiled executable (or nothing at all if your program fails to compile). 

### Installation
Clone CRun to your local machine by typing this in your terminal: ```git clone (https://github.com/racheljn/CRun.git)```

### Demos
* hello.c is a basic Hello World program that prints out "Hello, World!" to the console that tests CRun without any arguments\
* helloName.c is a modified Hello World program that requires an argument and prints out "Hello, -insert argument 1-" to the console that tests CRun with a single argument\
* helloNames.c is a modified Hello World program that requires three arguments and prints out "Hello, -insert arg1-, -insert arg2-, and -insert arg3-!" to the console that tests CRun with multiple arguments\
* failure.c is a program that has two hardcoded integers, 5 and 6, and prints the sum, which is 11, of them to the console that tests CRun in the case of failures. It can be used to test that crun produced various errors by adding in the commented notACall(x, y) line in or removing semicolons from any of the lines. It can also be used to make sure that crun deletes any old instances of previously compiled executable code by calling crun on a working version of failure.c, then changing the failure.c file so that it no longer will compile and running it again using crun and making sure that there is no longer a failure executable file in the demos folder.
