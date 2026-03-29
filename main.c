#include "my_shell.h"

// shell loop 
// input Parsing ( so we can exe )
// commands execution:
// Handle Built-in commands exp . cd , pwd , echo , env , setenv ,wich , exit1
// Also execute external commands
// Manage enviroments vars 
// Manage Path 
// Err Handling 




void shell_loop(char **env){

    char* input =NULL;
size_t input_size=0;
char** args;
while (1){
   
    printf("[Ab_shell]> ");
   if(getline(&input, &input_size, stdin)== -1) //EOF, then will get out of the loop ;, ctrl+D 
   {
  perror("getline");
  break;
 }
  // printf("Input : %s", input);

  args = parse_input(input);

}
}

int main(int argc, char** argv, char **env){
    (void)argc;
    (void)argv;
shell_loop(env);
return 0;
}