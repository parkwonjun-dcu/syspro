#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100   // 최대 줄 수
#define MAX_LENGTH 256  // 최대 문자 수

char savedText[MAX_LINES][MAX_LENGTH]; // 내용 2차원 배열 
int lineCount = 0; // 카운트 된 줄수

// 파일 열기 및 내용을 2차원 배열에 저장하는 함수
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

// 줄 번호 입력에 따라 출력하는 함수
void printLines(char *input) {
    if (strcmp(input, "*") == 0) { //1. 모든 줄 출력
        for (int i = 0; i < lineCount; i++) {
            printf("%d: %s", i + 1, savedText[i]);
        }
    } 
    else { 
        char *token = strtok(input, ","); // 쉼표로 구분하기
        
	while (token != NULL) {
            if (strchr(token, '-') != NULL) { 
                int start, end;
                sscanf(token, "%d-%d", &start, &end); // 2. 범위 추출 : '-'이 포함된 경우
                for (int i = start; i <= end; i++) {
                    if (i > 0 && i <= lineCount) {
                        printf("%d: %s", i, savedText[i - 1]); // 범위 내 줄 출력
                    }
                }
            } else { 
                int line;
                sscanf(token, "%d", &line); // // 단일 줄 번호 ,줄 번호 추출
                if (line > 0 && line <= lineCount) {
                    printf("%d: %s", line, savedText[line - 1]); // 줄 번호에 해당하는 내용 출력
                } else {
                    printf("유효하지 않은 줄 번호입니다: %s\n", token); // 잘못된 줄 번호 처리
                }
            }
            token = strtok(NULL, ","); // 다음 요소로 이동
        }
    }
}

int main() {
    const char *filename = "test.txt"; // 사용할 파일 이름
    readFile(filename); // 파일 읽기

    char input[256]; // 사용자 입력 저장
    printf("출력할 줄 번호를 입력하세요 (예: 1, 2, 3, 2-4, *): ");
    fgets(input, sizeof(input), stdin); // 사용자 입력 받기

    printLines(input); // 입력된 줄 번호에 따라 출력
    return 0;
}

