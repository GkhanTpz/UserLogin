#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "loginstatus.h" // This library checks username and password entered by user


int main()
{
    char username[256];
    char password[256];
    char cmd[512];
    char result[15];
    FILE* fp;

    printf ("%s","Welcome!\n");

#ifdef LOGIN_STATUS_H
    while(true)
    {
        printf ("%s","Enter username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0;  // remove newline

        printf("%s","Enter password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = 0;  // remove newline

        // Prepare the shell command
        snprintf(cmd, sizeof(cmd), "bash user_checker.sh \"%s\" \"%s\"", username, password);

        // Execute the script and read the result
        fp = popen(cmd, "r");
        if (fp == NULL) {
            perror("Failed to run script");
            return 1;
        }

        fgets(result, sizeof(result), fp);
        pclose(fp);

        // Remove newline from result
        result[strcspn(result, "\n")] = 0;

        // Interpret script result
        if (strcmp(result, "true") == 0) {
            UserCheck(LOGIN_SUCCESS, username);
            break;
        }
        else if (strcmp(result, "bad_password") == 0) {
            UserCheck(LOGIN_FAILURE_BAD_PASSWORD, username);
        }
        else if (strcmp(result, "bad_username") == 0) {
            UserCheck(LOGIN_FAILURE_BAD_CREDENTIALS, username);
        }
        else {
            printf("Unknown error occurred.\n");
            break;
        }
    }
#else
    printf("loginstatus.h is not defined or not located");
#endif // LOGIN_STATUS_H

    return 0;
}

