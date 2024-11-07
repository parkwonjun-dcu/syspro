#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

// 모든 환경 변수를 출력하는 함수
void All_Environ() {
    extern char **environ;
    for (char **env = environ; *env != 0; env++) {
        printf("%s\n", *env);
    }
    exit(0);
}

// 특정 환경 변수를 출력하는 함수
void PATH_Environ(const char *name) {
    char *value = getenv(name);
    if (value != NULL) {
        printf("%s = %s\n", name, value);
    } else {
        printf("%s Error.\n", name);
    }
}

// 사용자 ID 정보를 출력하는 함수
void UserPID() {
    printf("My Realistic User ID: %d (%s)\n", getuid(), getpwuid(getuid())->pw_name);
    printf("My valid User ID: %d (%s)\n", geteuid(), getpwuid(geteuid())->pw_name);
}

// 그룹 ID 정보를 출력하는 함수
void GroupPID() {
    printf("My Realistic Group ID: %d (%s)\n", getgid(), getgrgid(getgid())->gr_name);
    printf("My Valid Group  ID: %d (%s)\n", getegid(), getgrgid(getegid())->gr_name);
}

// 프로세스 ID를 출력하는 함수
void MyPID() {
    printf("My process Number ID: %d\n", getpid());
}

// 부모 프로세스 ID를 출력하는 함수
void MyPPID() {
    printf("My parent's Process Number: %d\n", getppid());
}

int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "e:")) != -1) {
        switch (opt) {
            case 'e':
                PATH_Environ(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s -e [env_var_name]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    return 0;
}

