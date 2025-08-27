# Bank Management System

This project is a simple console-based **Bank Management System** written in C++. It enables users to sign up, sign in, and perform basic banking operations such as deposit, withdrawal, checking balance, and viewing transaction history. Additionally, it includes an admin interface for managing customer accounts and monitoring account balances.

## Features

### Customer Operations

- **Signup**: Create a new bank account using a mobile number and password. Only valid mobile numbers (starting with 9, 8, 7, or 6 and of length 10) are accepted. The opening balance is set to $2000.
- **Signin**: Access your account using your mobile number and password.
- **Deposit/Withdraw**: Deposit or withdraw money from your account. Alerts are shown for low balance.
- **Balance Check**: View your current account balance.
- **Interest Calculation**: For savings accounts, calculate monthly interest.
- **Transaction History**: View a record of your deposits and withdrawals.

### Admin Operations

- **View Monthly Interest**: Display monthly interest details for all customers.
- **Check Proper Balance Accounts**: View accounts that always maintain the required minimum balance.
- **Check Low Balance Accounts**: Identify accounts with occasional low balances.
- **Dormant Account Management**: Delete accounts with repeated low balances.
- **View Customer Data**: Display all customer details.

## How It Works

- Account data is stored in binary files (`125_Bank_FH.dat`, `125_Bank_FH_TH.dat`, `125_Bank_FH_Dormat.dat`).
- Each customer is identified by their mobile number and password.
- The system enforces a minimum balance requirement.
- Admin access is protected by the password `"admin123"`.

## File Structure

- **Bank_FH.cpp**: Main source file containing all logic for customer and admin operations.
- **Data Files**:
  - `125_Bank_FH.dat`: Stores customer account data.
  - `125_Bank_FH_TH.dat`: Stores transaction history.
  - `125_Bank_FH_Dormat.dat`: Temporary file used during dormant account deletion.

## Usage

1. **Compile the Source Code**  
   Use a C++ compiler (e.g., g++):
   ```
   g++ Bank_FH.cpp -o Bank_FH
   ```

2. **Run the Program**
   ```
   ./Bank_FH
   ```

3. **Follow the Menu**
   - Choose between Admin Signin, Customer Signup, Customer Signin, and Exit.
   - For admin operations, enter the password `"admin123"` when prompted.
   - For customer operations, use your registered mobile number and password.

## Important Notes

- The code uses legacy functions like `gets()` and `fflush(stdin)`, and direct console manipulation (`system("CLS")`, `getch()`). These may not be portable to all systems and are discouraged in modern C++.
- This project is intended for educational purposes and demonstration of basic C++ file I/O and class usage.
- Data is stored in binary files and is not encrypted.
- The code is monolithic and procedural; there is no error handling for file operations or invalid input beyond basic checks.

## Example

### Main Menu

```
**********MENU**********
1. Admin Signin
2. Customer Signup
3. Customer Signin
4. EXIT
Enter your choice:
************************
```

### Customer Signup Flow

- Enter your mobile number.
- Enter and confirm your password.
- Choose account type (Savings/Current).
- You are signed up with a starting balance of $2000.

### Customer Signin Flow

- Enter your mobile number and password.
- Access account features:
  - Check Balance
  - Deposit/Withdraw
  - View Transaction History
  - For savings account: Calculate Interest

### Admin Flow

- Enter `admin123` as password.
- Access admin features: view interest, manage accounts, and view customer data.

## License

This project is provided as-is for educational purposes. No warranty is provided.

## Author

- [PalTrivedi](https://github.com/PalTrivedi)
