 #include <stdio.h>
  2 #include <stdlib.h>
  3 #include <string.h>
  4
  5 #define MAX_LINES 100   // ▒~\▒~L~@ ▒~D ▒~H~X
  6 #define MAX_LENGTH 256  // ▒~\▒~L~@ 문▒~^~P ▒~H~X
  7
  8 char savedText[MAX_LINES][MAX_LENGTH]; // ▒~B▒▒~Z▒▒~]~D ▒| ~@▒~^▒▒~U|  2차▒~[~P 배▒~W▒
  9 int lineCount = 0; // ▒| ~@▒~^▒▒~P~\ ▒~D ▒~H~X
 10
 11 void readFile(const char *filename) {
 12     FILE *file = fopen(filename, "r"); // ▒~L~L▒~]▒ ▒~W▒기
 13     if (file == NULL) {
 14         printf("▒~L~L▒~]▒▒~]~D ▒~W▒ ▒~H~X ▒~W~F▒~J▒▒~K~H▒~K▒.\n");
 15         exit(1); // ▒~L~L▒~]▒ ▒~W▒기 ▒~K▒▒~L▒ ▒~K~\ ▒~E▒~L
 16     }
 17
 18     while (lineCount < MAX_LINES) { // ▒~\▒~L~@ ▒~D ▒~H~X▒~L▒~@ ▒~X복
 19         if (fgets(savedText[lineCount], MAX_LENGTH, file) == NULL) {
 20             break; // ▒~L~L▒~]▒ ▒~A~] ▒~X~P▒~J~T ▒~X▒▒~X ▒~\▒~C~]
 21         }
 22         lineCount++; // ▒~D ▒~H~X ▒~]▒~@
 23     }
 24
 25     fclose(file); // ▒~L~L▒~]▒ ▒~K▒기
 26 }
 27
 28
 29 void printReversed() {
 30     for (int i = lineCount - 1; i >= 0; i--) { // ▒~H▒~@▒~I ▒~D▒~@▒~D▒ 첫 ▒~D▒~L▒~@
 31         printf("%s\n", savedText[i]); // ▒~D ▒~\▒| ▒
 32     }
 33 }
 34
 35 int main() {
 36     const char *filename = "test.txt";
 37     readFile(filename);
 38
 39     printf("▒| ~@▒~^▒▒~P~\ ▒~B▒▒~Z▒▒~]~D ▒~W▒▒~H~\▒~\▒▒~\ ▒~\▒| ▒▒~U▒▒~K~H▒~K▒:\n");
 40     printReversed();
 41
 42     return 0;
 43 }
 44
~
~
~
~

