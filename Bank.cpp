#include <iostream>
using namespace std;
class bank{
    private:
        int pin;
    public:
        string name,branch,ifsc;
        int accnum,balance;
        bank(){
            cout<<"A new bank object is created"<<endl;
        }
        bank(string name, int accnum, int balance, int pin, string branch, string ifsc){
            this->name = name;
            this->accnum = accnum;
            this->balance = balance;
            this->pin = pin;
            this->branch = branch;
            this->ifsc = ifsc;
        }
        void debit(int amount, int pin){
            if (pin==this->pin){
                if(amount<=balance){
                    balance=balance-amount;

                    cout<<"Amount debited: "<<amount<<endl; 
                }
            }
         else{
                cout<<"Incorrect PIN"<<endl;
            }
        }
        void credit(int amount){
            balance=balance+amount;
            cout<<"Amount credited: "<<amount<<endl;
        }
        void checkbalance(int pin){
            if(pin==this->pin){
                cout<<"current balance:"<<balance<<endl;
            }
            else{
                cout<<"incorrect pin please try again"<<endl;
            }
        }           
        void changepin(int oldpin,int newpin){
            if(oldpin==this->pin){
                this->pin=newpin;
                cout<<"PIN changed successfully"<<endl;
            }
            else{
                cout<<"enter the correct pin to change the pin"<<endl;
            }
        }
        void display(){
            cout<<"Account Holder Name: "<<name<<endl;
            cout<<"Accounr Number: "<<accnum<<endl;
            cout<<"Branch Name: "<<branch<<endl;
            cout<<"IFSC Code: "<<ifsc<<endl;
        }
    };

    int main() {

        bank b1("Akshat Patel",1234,1000,1234,"khargone","KHG123");
        b1.display();
        b1.credit(1000);
        b1.checkbalance(1234);
        b1.debit(1000,1234);
        b1.checkbalance(1234);
        b1.changepin(1234,4321);
        b1.checkbalance(4321);
        
        return 0;
    }  
