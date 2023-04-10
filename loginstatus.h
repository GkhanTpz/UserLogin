#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LOGIN_STATUS_H

typedef enum {
    LOGIN_SUCCESS,
    LOGIN_FAILURE_BAD_CREDENTIALS,
    LOGIN_FAILURE_BAD_PASSWORD,
    LOGIN_FAILURE_PASSWORD_CHANGE_REQUESTED
    } LoginStatus;// LoginStatus sadece LOGIN_SUCCESS, LOGIN_FAILURE_BAD_CREDENTIALS, LOGIN_FAILURE_BAD_PASSWORD, LOGIN_FAILURE_PASSWORD_CHANGE_REQUESTED değerini alabilir.


int password, newpass, defpass=1234;
char answer, user[15], defuser[15]="gokhan";

void userCheck(LoginStatus Login) // kullanıcı girişini kontrol eden fonksiyon
{
    while (true)
    {
        if(Login == LOGIN_SUCCESS)
        {
            printf("Successful login. Welcome, %s!\n",user);
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
            scanf(" %c",&answer);

            if (answer == 'Y' || answer == 'y')
            {
                printf ("%s","Enter new password: ");
                scanf("%d",&newpass);
                defpass = newpass;
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
