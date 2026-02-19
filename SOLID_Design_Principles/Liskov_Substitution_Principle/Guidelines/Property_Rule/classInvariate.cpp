#include <bits/stdc++.h>
using namespace std;

// Invariant : Balance cannot be negative;
class BankAccount
{
protected:
    double balance;

public:
    BankAccount(double amount)
    {
        if (amount < 0)
            throw invalid_argument("Amount cannot be negative: \n");
        balance = amount;
    }
    virtual void withdraw(double amount)
    {
        if (balance - amount < 0)
            throw runtime_error("Insufficient balance");
        balance -= amount;
        cout << "Remaining balance is: " << balance << endl;
    }
};
// Breaks Invariant : Should not be allowed;
class CheatAccount : public BankAccount
{
public:
    CheatAccount(double b) : BankAccount(b) {};
    void withdraw(double amount) // if we want not to break this rule then this method also must follow the balance rule of Parent class
    {
        balance -= amount;
        cout << "Remaining balance is : " << balance << endl;
    }
};

int main()
{
    // BankAccount *bankaccount = new BankAccount(1000);
    //  bankaccount->withdraw(1500);
    BankAccount *bankaccount = new CheatAccount(1000);
    bankaccount->withdraw(1500);
}