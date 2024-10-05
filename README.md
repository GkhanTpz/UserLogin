---

# Simple Login System in C

This C program simulates a login system that checks the user credentials (username and password) and provides an option to change the password if it is entered incorrectly.

## Features:
- User enters a username and password.
- Checks if the credentials match predefined values.
- If the password is incorrect, the user can change it.
- The user is given feedback based on their input.

---

## Code Overview

```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LOGIN_STATUS_H

#define MAX_USERNAME_LENGTH 15
#define DEFAULT_USERNAME "gokhan"
int DEFAULT_PASSWORD = 1234;
```

### Explanation:
- **stdio.h**: Standard library for input and output.
- **stdbool.h**: Enables the use of Boolean data types (`true` and `false`).
- **string.h**: Used for string handling functions such as `strcmp()`.
- **LOGIN_STATUS_H**: A macro to ensure the login status header is included.
- **MAX_USERNAME_LENGTH**: Limits the username length to 15 characters.
- **DEFAULT_USERNAME** and **DEFAULT_PASSWORD**: Predefined credentials that the user must input to log in.

---

## Enum for Login Status

```c
// Declares possible outcomes for the login process
typedef enum
{
    LOGIN_SUCCESS,
    LOGIN_FAILURE_BAD_CREDENTIALS,
    LOGIN_FAILURE_BAD_PASSWORD,
    LOGIN_FAILURE_PASSWORD_CHANGE_REQUESTED
} LoginStatus;
```

### Explanation:
This enum defines the possible outcomes for the login process:
- `LOGIN_SUCCESS`: The login is successful.
- `LOGIN_FAILURE_BAD_CREDENTIALS`: Either the username or both username and password are incorrect.
- `LOGIN_FAILURE_BAD_PASSWORD`: The username is correct, but the password is incorrect.
- `LOGIN_FAILURE_PASSWORD_CHANGE_REQUESTED`: User requests to change the password after entering an incorrect one.

---

## The `userCheck()` Function

```c
int password, new_password;
char response, username[MAX_USERNAME_LENGTH];

// Function that checks username and password
void userCheck(LoginStatus Login)
{
    while (true)
    {
        if (Login == LOGIN_SUCCESS)
        {
            printf("Successful login. Welcome, %s!\n", username);
            break;
        }
        else if (Login == LOGIN_FAILURE_BAD_CREDENTIALS)
        {
            printf("Invalid username. Please try again.\n");
            break;
        }
        else if (Login == LOGIN_FAILURE_BAD_PASSWORD)
        {
            printf("Invalid password. Do you want to change your password? (y/n)\n");
            scanf(" %c", &response);

            if (response == 'Y' || response == 'y')
            {
                printf("Enter new password: ");
                scanf("%d", &new_password);
                DEFAULT_PASSWORD = new_password;
                printf("Password changed successfully.\n");
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
```

### Explanation:
- The function `userCheck()` processes the login status and provides corresponding feedback:
    - If the login is successful, a welcome message is printed.
    - If the username is incorrect, an error message is shown.
    - If the password is incorrect, the user is prompted to either change the password or try again.

---

## Main Function

```c
int main()
{
    printf("Welcome!\n");

#ifdef LOGIN_STATUS_H
    while (true)
    {
        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%d", &password);

        if (strcmp(DEFAULT_USERNAME, username) == 0 && DEFAULT_PASSWORD == password)
        {
            userCheck(LOGIN_SUCCESS);  // Credentials are correct
            break;
        }
        else if ((strcmp(DEFAULT_USERNAME, username) != 0 && DEFAULT_PASSWORD != password) ||
                 (strcmp(DEFAULT_USERNAME, username) != 0 && DEFAULT_PASSWORD == password))
        {
            userCheck(LOGIN_FAILURE_BAD_CREDENTIALS);  // Incorrect username or both wrong
        }
        else if (strcmp(DEFAULT_USERNAME, username) == 0 && DEFAULT_PASSWORD != password)
        {
            userCheck(LOGIN_FAILURE_BAD_PASSWORD);  // Username correct, password incorrect
        }
    }
#else
    printf("loginstatus.h is not defined or not located\n");
#endif // LOGIN_STATUS_H

    return 0;
}
```

### Explanation:
- The `main()` function drives the program:
    - Prompts the user for a username and password.
    - Uses `strcmp()` to check if the username matches the predefined one (`DEFAULT_USERNAME`).
    - Depending on the entered credentials, calls the `userCheck()` function with the appropriate status (`LOGIN_SUCCESS`, `LOGIN_FAILURE_BAD_CREDENTIALS`, or `LOGIN_FAILURE_BAD_PASSWORD`).

---

## How the Program Works:
1. The user is prompted to enter a username and password.
2. The program compares the entered values with the predefined credentials.
3. If the username and password are correct, the user is successfully logged in.
4. If the username is incorrect, an error message is shown.
5. If the password is incorrect but the username is correct, the user is given an option to change the password.

### Example Output:
```
Welcome!
Enter username: gokhan
Enter password: 1234
Successful login. Welcome, gokhan!
```
