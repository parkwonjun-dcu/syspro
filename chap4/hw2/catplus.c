#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 80 // 

void print_file(FILE *fp, int print_line_numbers) {
    char buffer[MAXLINE]; 
    int line = 1; 

    while (fgets(buffer, MAXLINE, fp) != NULL) {
        if (print_line_numbers) {
            printf("%3d %s", line++, buffer);
        } else {
            printf("%s", buffer);
        }
    }
}

int main(int argc, char *argv[]) {
    int print_line_numbers = 0; 
    int file_start_index = 1; 

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        print_line_numbers = 1;
        file_start_index = 2; 
    }

    if (argc < file_start_index + 1) {
        print_file(stdin, print_line_numbers);
    } else {
        for (int i = file_start_index; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r"); 
            if (fp == NULL) {
                fprintf(stderr, "Error opening file %s\n", argv[i]);
                continue; 
            }
            print_file(fp, print_line_numbers); 
            fclose(fp); 
        }
    }

    return 0;
}


