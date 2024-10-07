#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE];
char shortest[MAXLINE];

int main() {
    int len;
    int min;
    int first = 1;  

    while (gets(line) != NULL) {
        len = strlen(line);

        if (first || len < min) { 
            min = len;
            copy(line, shortest);
            first = 0;  
        }
    }

    printf("가장 짧은 줄: %s\n", shortest);
}

