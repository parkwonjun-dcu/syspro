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
            printf("파일에 줄이 너무 많습니다. %d줄까지만 처리합니다.\n", MAX_LINES);
            break;
        }
    }
    fclose(file);
}

// 텍스트 파일의 내용을 거꾸로 출력하는 함수
void printReversed() {
    for (int i = lineCount - 1; i >= 0; i--) {
        printf("%s\n", savedText[i]);
    }
}

int main() {
    const char *filename = "test.txt";
    readFile(filename);

    printf("파일의 내용을 거꾸로 출력합니다:\n");
    printReversed();

    return 0;
}

