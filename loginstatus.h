#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LOGIN_STATUS_H

#define MAX_USERNAME_LENGTH 15
#define DEFAULT_USERNAME "gokhan"
int DEFAULT_PASSWORD = 1234;

//This declarates if username and password entered by user is true or not 
typedef enum
{
    LOGIN_SUCCESS,
    LOGIN_FAILURE_BAD_CREDENTIALS,
    LOGIN_FAILURE_BAD_PASSWORD,
    LOGIN_FAILURE_PASSWORD_CHANGE_REQUESTED
}LoginStatus;


int password, new_password;
char response, username[MAX_USERNAME_LENGTH];

// The Function checking username and password
void userCheck(LoginStatus Login)
{
    while (true)
    {
        if(Login == LOGIN_SUCCESS)
        {
            printf("Successful login. Welcome, %s!\n",username);
            break;
        }
        else if(Login == LOGIN_FAILURE_BAD_CREDENTIALS)
        {
            printf("%s","Invalid username. Please try again.\n");
            break;
        }
        else if(Login == LOGIN_FAILURE_BAD_PASSWORD)
        {
            printf("%s","Invalid password. Do you want to change your password? (y/n)\n");
            scanf(" %c",&response);

            if (response == 'Y' || response == 'y')
            {
                printf ("%s","Enter new password: ");
                scanf("%d",&new_password);
                DEFAULT_PASSWORD = new_password;
                printf("%s","Password changed successfully.\n");
            }
            else
            {
            printf("Password change not requested. Please try again with correct password.\n");
            return LOGIN_FAILURE_PASSWORD_CHANGE_REQUESTED;
            }
            break;
        }
    }
}
