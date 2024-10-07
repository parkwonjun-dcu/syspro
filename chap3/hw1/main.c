#include <stdio.h>
#include <string.h>
#include "copy.h"

#define MAXLINE 100
#define MAXSTRINGS 5

char lines[MAXSTRINGS][MAXLINE]; 
char longest[MAXLINE];             

int main() {
    int len[MAXSTRINGS];         
    int maxIndex = 0;              
    int i;

    for (i = 0; i < MAXSTRINGS; i++) {
        printf("문장 %d 입력: ", i + 1);
        fgets(lines[i], MAXLINE, stdin);
        len[i] = strlen(lines[i]);
        if (lines[i][len[i] - 1] == '\n') { 
            lines[i][len[i] - 1] = '\0';
            len[i]--;
        }
    }
    for (i = 0; i < MAXSTRINGS; i++) {
        for (int j = i + 1; j < MAXSTRINGS; j++) {
            if (len[i] < len[j]) {
                char temp[MAXLINE];
                copy(lines[i], temp);
                copy(lines[j], lines[i]);
                copy(temp, lines[j]);

                int tempLen = len[i];
                len[i] = len[j];
                len[j] = tempLen;
            }
        }
    }

    printf("\n문장 길이에 따라 정렬된 결과:\n");
    for (i = 0; i < MAXSTRINGS; i++) {
		printf("%s\n", lines[i]);
	}

	return 0;
}
