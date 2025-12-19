#include <iostream>
using namespace std;
class BankAccount {
private:
    int pin;
public:
    int balance,accountnumber;
    string uname,branchname ;
    BankAccount(){
        cout<<"a new account has been created\n";
    }
    BankAccount(string name, int accnum, int bal, int pincode, string branchname){
        uname = name;
        accountnumber = accnum;
        balance = bal;
        pin = pincode;
        branchname = branchname;
    }
    void deposit(int amount){
        balance += amount;
        cout<<"Amount deposited: "<<amount<<endl;
    }
    void withdraw(int amount, int pincode){
        if(pincode == pin){
            if(amount <= balance){
                balance -= amount;
                cout<<"Amount withdrawn: "<<amount<<endl;
            } else {
                cout<<"Insufficient balance\n";
            }
        } else {
            cout<<"Incorrect PIN\n";
        }
    }
    void displayBalance(int pincode){
        if(pincode == pin){
            cout<<"Current balance: "<<balance<<endl;
        } else {
            cout<<"Incorrect PIN\n";
        }
    }
    void changePin(int oldPin, int newPin){
        if(oldPin == pin){
            pin = newPin;
            cout<<"PIN changed successfully\n";
        } else {
            cout<<"Incorrect old PIN\n";
        }
    }
    void displayDetails(){
        cout<<"Account Holder: "<<uname<<endl;
        cout<<"Account Number: "<<accountnumber<<endl;
        cout<<"Branch Name: "<<branchname<<endl;
    }
    void closeAccount(int pincode){
        if(pincode == pin){
            cout<<"Account closed successfully\n";
            balance = 0;
        } else {
            cout<<"Incorrect PIN\n";
        }
    }
    void transferFunds(BankAccount &toAccount, int amount, int pincode){
        if(pincode == pin){
            if(amount <= balance){
                balance -= amount;
                toAccount.balance += amount;
                cout<<"Transferred "<<amount<<" to account number "<<toAccount.accountnumber<<endl;
            } else {
                cout<<"Insufficient balance\n";
            }
        } else {
            cout<<"Incorrect PIN\n";
        }
    }
    void checkbalance(){
        cout<<"Balance is: "<<balance<<endl;
    }

};

int main() {
    BankAccount account1("Akshat Patel", 123456, 1000, 1111, "Main Branch");
    BankAccount account2("Akshat p", 654321, 500, 2222, "City Branch");

    account1.displayDetails();
    account1.deposit(500);
    account1.displayBalance(1111);
    account1.withdraw(200, 1111);
    account1.displayBalance(1111);
    account1.changePin(1111, 1234);
    account1.transferFunds(account2, 300, 1234);
    account1.displayBalance(1234);
    account2.displayBalance(2222);
    account1.closeAccount(1234);
    account1.displayBalance(1234);

    return 0;
}