#include "my_shell.h"

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
if (strcmp(args[0],"cd")){
//48:26
}
else if (strcmp(args[0]),"pwd"){
  
}
else if (strcmp(args[0]),"echo"){

}
else if (strcmp(args[0]),"env"){

}
else if (strcmp(args[0]),"wich"){

}
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
    // we stoped at min 35:42 
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
shell_loop(env);
return 0;
}