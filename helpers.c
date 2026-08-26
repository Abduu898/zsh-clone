#include "my_shell.h"
// 0: strings are ==
//<0 str1 <str2 
// >0 then str1>str2 

// an unsigned char is an int between 0 to 255
int my_strcmp(const char* str1,const char* str2)
{
    while(*str1 &&(*str1 == *str2)){
        str1++;
        str2++;
    }

    return *(unsigned char*)str1 - *(unsigned char*)str2;
}
int my_strlen(const char* str){
    size_t len=0;
    while(*str){
        len++;
        str++;
    }
    return len;
}

//0: if strings are qual to n characters
//<0 if str1 < str2
//>0 if str1 > str2

int my_strncmp(const char * str1, const char* str2 , size_t n){

    size_t i=0;
    while (i < n && str1[i] && str2[i])
    {
        if (str1[i] != str2[i])
        {
            return (unsigned char)str1[i] - (unsigned char)str2[i];
            //unsigned char means a char that can only store non negative values (0 to 255). This is useful for comparing characters in a way that is consistent with their ASCII values, especially when dealing with extended character sets.
        }
        i++;
    }
    if (i==n)
    {
        return 0; // The first n characters are equal
    }
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}

char* my_getenv(const char *name, char** env){
    if(name == NULL || env == NULL){
        return NULL;
    }
    size_t name_len =my_strlen(name);

    for(size_t i=0; env[i] != NULL; i++){
       
        //check if the curr env starts with ' names='
        if(my_strncmp(env[i], name, name_len) == 0 && env[i][name_len] == '='){
            return env[i] + name_len + 1; // Return the value part of the environment variable
        }
    }

    return NULL; // Environment variable not found
}