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
    char response;

    switch (status)
    {
    case LOGIN_SUCCESS:
        printf("✅ Successful login. Welcome, %s!\n", username);
        break;

    case LOGIN_FAILURE_BAD_CREDENTIALS:
        printf("❌ Invalid username. Please try again.\n");
        break;

    case LOGIN_FAILURE_BAD_PASSWORD:
        printf("❌ Invalid password. Do you want to change your password? (y/n): ");
        scanf(" %c", &response);

        if (response == 'y' || response == 'Y')
        {
            printf("Enter new password: ");
            scanf("%s", new_password);

            // Not actually saving — just demo!
            printf("🔐 Password changed (simulated). It will not persist after restart.\n");
            // Real implementation: hash new_password and save it
        }
        else
        {
            printf("🔁 Password change not requested. Try again.\n");
        }
        break;

    default:
        printf("⚠️ Unknown login status.\n");
        break;
    }
}

#endif // LOGIN_STATUS_H