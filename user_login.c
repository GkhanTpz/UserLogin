#include <stdio.h>
#include "loginstatus.h" // This library checks username and password entered by user


int main()
{
    printf ("%s","Welcome!\n");

#ifdef LOGIN_STATUS_H
    while(true)
    {
        printf ("%s","Enter username:");
        scanf("%s",username);

        printf("%s","Enter password: ");
        scanf ("%d",&password);

        if(strcmp(DEFAULT_USERNAME,username) == 0 && DEFAULT_PASSWORD == password) // If username entered user is true
        {
            userCheck(LOGIN_SUCCESS); // This declares the function that user info is true
            break;
        }
        // If username and password entered by user is false
        else if((strcmp(DEFAULT_USERNAME,username) != 0 && DEFAULT_PASSWORD != password) || (strcmp(DEFAULT_USERNAME,username) != 0 && DEFAULT_PASSWORD == password))
            userCheck(LOGIN_FAILURE_BAD_CREDENTIALS); // This declarate the function that user info is false

        else if(strcmp(DEFAULT_USERNAME,username) == 0 && DEFAULT_PASSWORD != password) // If password entered user is false
            userCheck(LOGIN_FAILURE_BAD_PASSWORD); // This declares the function that password entered by user is false
    }
#else
    printf("loginstatus.h is not defined or not located");
#endif // LOGIN_STATUS_H

    return 0;
}

