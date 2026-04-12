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