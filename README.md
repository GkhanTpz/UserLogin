# 🔒 Simple Login System in C

This is a beginner-friendly login system written in C. It allows users to authenticate with predefined credentials, provides feedback for different login scenarios, and includes a password reset option for incorrect password entries. This project demonstrates the use of enums, functions, and basic string handling in C.

---

## 🛠️ Code Explanation

### 📝 Predefined Constants

```c
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

const char DEFAULT_USERNAME[MAX_USERNAME_LENGTH] = "Gokhan";
const char DEFAULT_PASSWORD_HASH[65] = "03ac674216f3e15c761ee1a5e255f067953623c8b388b4459e13f978d7c846f4"; // hash of '1234'
```

- **`MAX_USERNAME_LENGTH` and `MAX_PASSWORD_LENGTH`**: Sets a limit of 50 characters for the username and the password input to prevent buffer overflow issues.
- **`DEFAULT_USERNAME` and `DEFAULT_PASSWORD_HASH`**: These represent the hardcoded credentials that the system checks against user input.

---

### 🔄 Login Status Enum

The `LoginStatus` enum defines all possible outcomes of the login process.

```c
typedef enum {
    LOGIN_SUCCESS,
    LOGIN_FAILURE_BAD_CREDENTIALS,
    LOGIN_FAILURE_BAD_PASSWORD,
    LOGIN_FAILURE_PASSWORD_CHANGE_REQUESTED
} LoginStatus;
```

| Enum Value                              | Meaning                                                                 |
|-----------------------------------------|-------------------------------------------------------------------------|
| `LOGIN_SUCCESS`                         | The username and password are correct, and the user is authenticated.  |
| `LOGIN_FAILURE_BAD_CREDENTIALS`         | Either the username or both the username and password are invalid.      |
| `LOGIN_FAILURE_BAD_PASSWORD`            | The username is correct, but the password is incorrect.                 |
| `LOGIN_FAILURE_PASSWORD_CHANGE_REQUESTED` | The user opts to reset the password after an incorrect password attempt.|

---

### 📂 Functions Overview

#### `userCheck(LoginStatus status, const char* username)`

Handles the result of the login attempt and interacts with the user based on the login status.

```c
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
```

- **`LOGIN_SUCCESS`**: Displays a welcome message.
- **`LOGIN_FAILURE_BAD_CREDENTIALS`**: Alerts the user of an invalid username and allows them to retry.
- **`LOGIN_FAILURE_BAD_PASSWORD`**: Informs the user of an incorrect password and offers a password reset.
- **`LOGIN_FAILURE_PASSWORD_CHANGE_REQUESTED`**: Handles the password reset process.

#### Main Program (`main()`)

The `main()` function drives the logic of the program.

```c
while(true)
    {
        printf ("%s","Enter username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0;  // remove newline

        printf("%s","Enter password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = 0;  // remove newline

        // Prepare the shell command
        snprintf(cmd, sizeof(cmd), "./user_checker.sh \"%s\" \"%s\"", username, password);

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
```

- Prompts the user for a username and password.
- Uses `strcmp()` to compare the input username with `result` taken by `user_checker.sh`.
- If the username matches:
  - Checks the password.
  - If the password is incorrect, prompts for a reset option (`y`/`n`).
- If the username doesn't match, it prompts for re-entry.
- Password reset updates the `new_password` variable.

---

### 🧩 Program Workflow

1. **Input Handling**: Accepts user input for `username` and `password`.
2. **Validation**:
   - Compares the username using `strcmp()`.
   - Validates the password directly since it’s numeric.
3. **Feedback**: Calls `userCheck()` with appropriate `LoginStatus` based on the input.
4. **Password Reset**: Allows the user to update the password upon request.

---

## 📋 Example Scenarios

### 1️⃣ Successful Login

```plaintext
Enter username: Gokhan
Enter password: 1234
Successful login. Welcome, Gokhan!
```

### 2️⃣ Invalid Password and Reset

```plaintext
Enter username: Gokhan
Enter password: 1111
Incorrect password. Do you want to change your password? (y/n): y
Enter new password: 5678
Password changed (simulated). It will not persist after restart.
```

---

## 💻 How to Run the Program

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/your-username/simple-login-system.git
cd simple-login-system
```

### 2️⃣ Compile the Program

Use GCC or another C compiler:

```bash
gcc user_login.c -o user_login
```

### 3️⃣ Execute the Program

```bash
./user_login
```

## 📝 **License**

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
