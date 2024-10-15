#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

char savedText[MAX_LINES][MAX_LENGTH]; // 텍스트 파일의 각 줄을 저장할 2차원 배열
int lineCount = 0;

// 텍스트 파일을 읽고 2차원 배열에 저장하는 함수
void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        exit(1);
    }

    while (fgets(savedText[lineCount], MAX_LENGTH, file) != NULL) {
        // 줄바꿈 문자 제거
        savedText[lineCount][strcspn(savedText[lineCount], "\n")] = '\0';
        lineCount++;
        if (lineCount >= MAX_LINES) {
            printf("파일이 너무 많습니다.\n");
            break;
        }
    }
    fclose(file);
}

// 특정 줄을 출력하는 함수
void printLine(int line) {
    if (line >= 0 && line < lineCount) {
        printf("%d: %s\n", line + 1, savedText[line]);
    } else {
        printf("잘못된 줄 번호입니다.\n");
    }
}

// 줄 범위를 출력하는 함수
void printRange(int start, int end) {
    if (start >= 0 && end < lineCount && start <= end) {
        for (int i = start; i <= end; i++) {
            printLine(i);
        }
    } else {
        printf("잘못된 줄 범위입니다.\n");
    }
}

// 모든 줄을 출력하는 함수
void printAll() {
    for (int i = 0; i < lineCount; i++) {
        printLine(i);
    }
}

// 사용자 입력을 처리하는 함수
void processInput(const char *input) {
    if (strcmp(input, "*") == 0) {
        printAll();
    } else if (strchr(input, ',') != NULL) {
        char *token = strtok((char *)input, ",");
        while (token != NULL) {
            int line = atoi(token) - 1;
            printLine(line);
            token = strtok(NULL, ",");
        }
    } else if (strchr(input, '-') != NULL) {
        int start, end;
        sscanf(input, "%d-%d", &start, &end);
        printRange(start - 1, end - 1);
    } else {
        int line = atoi(input) - 1;
        printLine(line);
    }
}

int main() {
    const char *filename = "test.txt";
    readFile(filename);

    char input[50];
    printf("출력할 줄 번호를 입력하세요 (예: 1, 1-3, *, 2,5,7): ");
    scanf("%s", input);

    processInput(input);

    return 0;
}

