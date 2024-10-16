#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100   // 최대 줄 수
#define MAX_LENGTH 256  // 최대 문자 수

char savedText[MAX_LINES][MAX_LENGTH]; // 내용을 저장할 2차원 배열
int lineCount = 0; // 저장된 줄 수

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r"); // 파일 열기
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        exit(1); // 파일 열기 실패 시 종료
    }

    while (lineCount < MAX_LINES) { // 최대 줄 수까지 반복
        if (fgets(savedText[lineCount], MAX_LENGTH, file) == NULL) {
            break; // 파일 끝 또는 오류 발생
        }
        lineCount++; // 줄 수 증가
    }

    fclose(file); // 파일 닫기
}


void printReversed() {
    for (int i = lineCount - 1; i >= 0; i--) { // 마지막 줄부터 첫 줄까지
        printf("%s\n", savedText[i]); // 줄 출력
    }
}

int main() {
    const char *filename = "test.txt"; 
    readFile(filename); 

    printf("저장된 내용을 역순으로 출력합니다:\n");
    printReversed(); 

    return 0; 
}

