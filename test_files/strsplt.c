#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* @brief: splitting strings into newlines
* Retunr: always 0;
*/

int main() {
    char *token;
    
    char cum[50] = "house hold items";
    token = strtok(cum, " ");
    while (token)
    {
    printf("%s\n", token);
    token = strtok(NULL, " ");
    }
    
    return 0;
}
