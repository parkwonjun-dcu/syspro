#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

void All_Environ() {
    extern char **environ;
    for (char **env = environ; *env != 0; env++) {
        printf("%s\n", *env);
    }
    exit(0);
}
void PATH_Environ(const char *name) {
    char *value = getenv(name);
    if (value != NULL) {
        printf("%s = %s\n", name, value);
    } else {
        printf("%s Error.\n", name);
    }
    exit(0);
}

void UserPID() {
    printf("My Realistic User ID: %d (%s)\n", getuid(), getpwuid(getuid())->pw_name);
    printf("My valid User ID: %d (%s)\n", geteuid(), getpwuid(geteuid())->pw_name);
}

void GroupPID() {
    printf("My Realistic Group ID: %d (%s)\n", getgid(), getgrgid(getgid())->gr_name);
    printf("My Valid Group  ID: %d (%s)\n", getegid(), getgrgid(getegid())->gr_name);
}

void MyPID() {
    printf("My process Number ID: %d\n", getpid());
}

void MyPPID() {
    printf("My parent's Process Number: %d\n", getppid());
}

int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "e::ugip")) != -1) {
        switch (opt) {
            case 'e':
				  if (strcmp(optarg, "PATH") == 0) {
                    PATH_Environ("PATH");
					break;
                } else {
                    All_Environ();
					break;
                }
            
			case 'u':
                UserPID();
                break;
            case 'g':
                GroupPID();
                break;
            case 'i':
                MyPID();
                break;
            case 'p':
                MyPPID();
                break;
            default:
                fprintf(stderr, "Usage: %s [-e[env_var_name]] [-u] [-g] [-i] [-p]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
	
    return 0;
}

