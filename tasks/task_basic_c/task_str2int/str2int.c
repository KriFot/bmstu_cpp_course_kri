#include <assert.h>
#include "str2int.h"
#include "stdio.h"

//proverka na pustoty
int is_space(char c) {
    return (c == ' ');
}

//proverka na ot 0 do 9
int is_digit(char c) {
    return(c>='0' && c<='9');
}

int str2int(const char *str) {

    assert(str != NULL && ""); // proverka na 

    int result = 0;
    int sign = 1;
    int max_int = 2147483647;
    int min_int = -2147483647;
    while (*str != '\0' && is_space(*str)){
        str++;
    }
    if (*str == '-' || *str =='+'){
        sign = (*str == '-') ? -1 : 1;
        str++;
    }
    while (*str != '\0' && is_digit(*str)){
        int digit = *str - '0';

        assert(result > (max_int - digit)/10 && "");
        
        result = result * 10 + digit;
        str++;
    }
    if (result * sign > max_int || result * sign < min_int){
        assert(0 && "");
    } 

    return result * sign;
}
