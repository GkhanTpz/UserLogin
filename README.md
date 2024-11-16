🔒 Simple Login System in C

A simple login system implemented in C, allowing users to authenticate with predefined credentials and optionally change their password if entered incorrectly.

🚀 Features

	•	User Authentication: Users log in with a username and password.
	•	Password Change Option: If the entered password is incorrect, users can opt to change it.
	•	Feedback Messages: Provides detailed feedback on login status.
	•	Predefined Credentials: Credentials are defined within the program.

🛠️ Code Overview

📝 Predefined Constants

#define MAX_USERNAME_LENGTH 15
#define DEFAULT_USERNAME "gokhan"
int DEFAULT_PASSWORD = 1234;

	•	MAX_USERNAME_LENGTH: Limits the username input length to 15 characters.
	•	DEFAULT_USERNAME and DEFAULT_PASSWORD: Hardcoded credentials for authentication.

🔄 Enum for Login Status

typedef enum {
    LOGIN_SUCCESS,
    LOGIN_FAILURE_BAD_CREDENTIALS,
    LOGIN_FAILURE_BAD_PASSWORD,
    LOGIN_FAILURE_PASSWORD_CHANGE_REQUESTED
} LoginStatus;

Defines various outcomes of the login process.

Status	Description
LOGIN_SUCCESS	Login was successful.
LOGIN_FAILURE_BAD_CREDENTIALS	Username or both credentials are invalid.
LOGIN_FAILURE_BAD_PASSWORD	Username is correct, but password is not.
LOGIN_FAILURE_PASSWORD_CHANGE_REQUESTED	User opted to change the password.

📂 Core Functions

userCheck()

Handles login outcomes based on the LoginStatus.

void userCheck(LoginStatus Login)

Key Scenarios:
	•	Welcomes the user if login is successful.
	•	Prompts for re-entry if the username is invalid.
	•	Asks if the user wants to reset their password upon incorrect password entry.

🖥️ Main Program Logic

The main() function drives the program.

int main()

	•	Accepts username and password input.
	•	Compares input with predefined credentials using strcmp().
	•	Calls userCheck() with an appropriate login status.

Control Flow:
	1.	Correct username and password → Welcome message.
	2.	Incorrect username → Error message and retry.
	3.	Correct username, incorrect password → Password reset option.

📋 Example Usage

Scenario: Successful Login

Welcome!
Enter username: gokhan
Enter password: 1234
Successful login. Welcome, gokhan!

Scenario: Password Reset

Welcome!
Enter username: gokhan
Enter password: 4321
Invalid password. Do you want to change your password? (y/n)
y
Enter new password: 5678
Password changed successfully.

🛠️ Installation & Usage

	1.	Clone the Repository:

git clone https://github.com/your-username/simple-login-system.git
cd simple-login-system


	2.	Compile the Program:
Use a C compiler like gcc:

gcc login.c -o login


	3.	Run the Program:

./login

📝 License

This project is licensed under the MIT License.