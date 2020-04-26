#include <unistd.h>
   #include <stdio.h>
   #include <sys/wait.h>
   #include <string.h>
   #include <stdlib.h>
   #include <string.h>

   #define  TRUE     1

   int main(int argc, char *argv[]){
      char input[25];
      int  retval = 0;

      char cfile[strnlen(argv[1], 500) + 1];
      char fileout[strnlen(argv[1], 500) + 1];
      strcpy(cfile, argv[1]);
      strcpy(fileout, cfile);
      fileout[strlen(fileout)-2] = '\0';

      char *fileoutArgs[argc];
      memcpy(fileoutArgs, &argv[1], (argc)*sizeof(*argv));
      fileoutArgs[0] = fileout;

      char *compileArgs[5];
      compileArgs[0] = "gcc";
      compileArgs[1] = cfile;
      compileArgs[2] = "-o";
      compileArgs[3] = fileout;
      compileArgs[4] = NULL;
      printf("%s\n", fileout);

      pid_t returnedValue = fork();
      if( returnedValue < 0 ) {
         perror( "error forking" );
         return -1;

      // fork was successful, so handle the input
      } else if( returnedValue == 0 ) {
         remove(fileout);
         retval = execvp( "gcc", compileArgs );
         perror( "error executing command" );
         return -1;

     // wait for the forked child to finish
      } else {
         if( waitpid( returnedValue, 0, 0 ) < 0 ) {
            perror( "error waiting for child" );
            return -1;
         }
      }
      pid_t returnedValue2 = fork();
      if( returnedValue2 < 0 ) {
         perror( "error forking" );
         return -1;

      // fork was successful, so handle the input
      } else if (returnedValue2 == 0 ){
        char fileoutexe[100] = "./";
        strcat(fileoutexe, fileout);
        fileoutArgs[0] = fileoutexe;
        retval = execvp( fileoutexe, fileoutArgs );
        perror( "error executing command" );
        return -1;
      } else {
         if( waitpid( returnedValue2, 0, 0 ) < 0 ) {
            perror( "error waiting for child" );
            return -1;
         }
      }
    }
