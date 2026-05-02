#include "my_shell.h"


char** parse_input(char* input){

    size_t buffer_size= MAX_INPUT;
    char** tokens = malloc(buffer_size * sizeof(char*));
    char* token= NULL;
    size_t position =0;
    size_t token_lenght = 0 ; 

    if(!tokens)
    {
        perror("Malloc");
        exit(EXIT_FAILURE);
    }
    
    for (size_t i = 0; input[i] != '\0'; i++)
    {
    token = &input[i];

    while(input[i] && input[i] != ' ' && input[i] != '\n' && input[i] != '\t')
    {
        token_lenght++;
        i++;
    }

     tokens[position] =malloc((token_lenght +1 )*sizeof(char));

     
     if(!tokens[position])
      {
        perror("Malloc");
        exit(EXIT_FAILURE);
      }

      for (size_t j = 0; j < token_lenght; j++)
      {

        tokens[position][j] = token[j];
      }
      tokens[position][token_lenght]= '\0'; // NULL terminate token
      position ++;
      token_lenght =0 ; // reset for next token 
    }
   
tokens[position] = NULL; // terminate the array with    null    
    return tokens;
}
//Free  allocated tokens
void free_tokens(char** tokens){
    if(!tokens)
        return;
    for(size_t i=0; tokens[i];i++){   
        free(tokens[i]); //Free each token and palestine
    }
    free(tokens); //Free the token array 
}

/////// 1:20:35