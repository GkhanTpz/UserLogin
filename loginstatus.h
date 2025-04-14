#ifndef LOGIN_STATUS_H
#define LOGIN_STATUS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 256

// Declare the global password variable (defined in user_login.c)
extern char password[MAX_PASSWORD_LENGTH];

// Login status enum
typedef enum Status
{
    LOGIN_SUCCESS,
    LOGIN_FAILURE_BAD_CREDENTIALS,
    LOGIN_FAILURE_BAD_PASSWORD,
    LOGIN_FAILURE_PASSWORD_CHANGE_REQUESTED
} LoginStatus;

// Function to handle login result
static inline void UserCheck(LoginStatus status, const char* username)
{
    char new_password[MAX_PASSWORD_LENGTH];
    char response, response_str[5]; // Create a string (array of characters) to store the user's input

    switch (status)
    {
    case LOGIN_SUCCESS:
        printf("Successful login. Welcome, %s!\n", username);
        break;

    case LOGIN_FAILURE_BAD_CREDENTIALS:
        printf("Invalid username. Please try again.\n");
        break;

    case LOGIN_FAILURE_BAD_PASSWORD:
        printf("Invalid password. Do you want to change your password? (y/n): ");
        fgets(response_str, sizeof(response_str), stdin); // Read input from the user, including spaces and newline
        response_str[strcspn(response_str, "\n")] = 0; // Remove the newline character at the end of the input

        char response = response_str[0]; // Take the first character from the input (like 'y' or 'n')

        if (response == 'y' || response == 'Y')
        {
            printf("Enter new password: ");
            fgets(new_password, sizeof(new_password), stdin);
            new_password[strcspn(new_password, "\n")] = 0;
           
            // Save hashed password to file
            char hash_cmd[512];
            snprintf(hash_cmd, sizeof(hash_cmd), "printf \"%%s\" \"%s\" | sha256sum | awk '{print $1}' > password.txt", new_password);
            int status = system(hash_cmd);

            if (status == 0) {
                strncpy(password, new_password, MAX_PASSWORD_LENGTH);
                password[MAX_PASSWORD_LENGTH - 1] = '\0';
                printf("Password changed and saved successfully.\n");
            }
            else {
                printf("Failed to save the new password.\n");
            } 
        }
        else
        {
            printf("Password change not requested. Try again.\n");
        }
        break;

    default:
        printf("Unknown login status.\n");
        break;
    }
}

#endif // LOGIN_STATUS_H