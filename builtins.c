#include "my_shell.h"


// cd, cd [path] : change the current working directory to the specified path. If no path is provided, it should change to the user's home directory.,cd - : change to the previous working directory.
//cd ~ : change to the home directory.
//handle non existing directories and print an appropriate error message.
int command_cd(char** args,char* initial_directory){
   
 (void)initial_directory;
    if (args[1] == NULL)
    {
        printf("cd: expected argument to \"cd [dir]\"\n");
    }else if(chdir(args[1]) == 0){
        // Directory changed successfully
        printf("CD Worked!\n");
    }else{
        perror("cd");
    }
    return 0;
    
}
int command_pwd(){
   char* cwd= NULL;

  
  // Use dynamic allocation to get the current working directory
  // getcwd(NULL,0) be like We know you'll need to allocate memory for the path, so we'll just do it for you!
   cwd = getcwd(NULL,0);
  if (cwd != NULL) {
    printf("PATH: %s\n", cwd);    
    printf("%s\n",cwd);
    free(cwd); // Free the allocated memory
    } else {
        perror("pwd");
    }
    return 0;
}
int command_echo(char** args,char** env);
int command_env(char** env);
int command_which(char** args,char** env);
