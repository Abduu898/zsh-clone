#include "my_shell.h"
#include <string.h>
// shell loop 
// input Parsing ( so we can exe )
// commands execution:
// Handle Built-in commands exp . cd , pwd , echo , env , setenv ,wich , exit1
// Also execute external commands
// Manage enviroments vars 
// Manage Path 
// Err Handling 


// cd , pwd , echo , env , setenv ,wich , exit1, 
int shell_builts(char** args,char** env,char* initial_directory)
{
  (void)env;
  (void)initial_directory;
  printf("Args[0] : %s\n",args[0]);

if (my_strcmp(args[0],"cd") == 0){
  printf("CD\n");
  // return command_cd(args,initial_directory);
}
else if (my_strcmp(args[0],"pwd")==0){
  // command_pwd();
}
else if (my_strcmp(args[0],"echo")==0){
// command_echo(args,env);
}
else if (my_strcmp(args[0],"env")==0){
 //  command_env(env);
}
else if (my_strcmp(args[0],"which")==0){
 //  command_which(args,env);
}
else if (my_strcmp(args[0],"exit") ==0 || my_strcmp(args[0],"quit") == 0) {
  printf("Exiting shell...\n");
  exit(EXIT_SUCCESS);
}else{
  //not a built-in command;
}
 return 0;
}



void shell_loop(char **env){

    char* input =NULL;
 size_t input_size=0;
 char** args;

    char* initial_directory = getcwd(NULL,0);
    while (1){
   
    printf("[Ab_shell]> ");
   if(getline(&input, &input_size, stdin)== -1) //EOF, then will get out of the loop ;, ctrl+D 
   {
  perror("getline");
  break;
 }
   // printf("Input : %s", input);

   args = parse_input(input);
   //   for (size_t i = 0; args[i] != NULL; i++){
        
      //  printf("Args : %s",args[i]);
    //    printf("\n");
    //  }
  
   // }

    if(args[0]!=NULL){
    shell_builts(args, env, initial_directory);
    }
    free_tokens(args); 

    
  }


}







int main(int argc, char** argv, char **env){
    (void)argc;
    (void)argv;
    (void)env;
    
    shell_loop(env);

  //just for testing the my_strcmp  char str1[] = "hello"; char str2[] = "hello";int result = my_strcmp(str1, str2);printf("Comparison result: %d\n", result); // Should print 0 for equal strings or 1 for different strings


  return 0;
}