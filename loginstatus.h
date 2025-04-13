#ifndef LOGIN_STATUS_H
#define LOGIN_STATUS_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

// Default credentials (can be modified later)
const char DEFAULT_USERNAME[MAX_USERNAME_LENGTH] = "Gokhan";
const char DEFAULT_PASSWORD_HASH[65] = "03ac674216f3e15c761ee1a5e255f067953623c8b388b4459e13f978d7c846f4"; // hash of '1234'


// Login status enum
typedef enum Status
{
    LOGIN_SUCCESS,
    LOGIN_FAILURE_BAD_CREDENTIALS,
    LOGIN_FAILURE_BAD_PASSWORD,
    LOGIN_FAILURE_PASSWORD_CHANGE_REQUESTED
} LoginStatus;

// Function to handle login result
void UserCheck(LoginStatus status, const char* username)
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
            scanf("%s", new_password);

            // Not actually saving — just demo!
            printf("Password changed (simulated). It will not persist after restart.\n");
            // Real implementation: hash new_password and save it
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