#include <bits/stdc++.h>
using namespace std;

class Account
{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdrawn(double amount) = 0;
};

class SavingAccount : public Account
{
private:
    double balance;

public:
    SavingAccount()
    {
        this->balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited " << amount << " in saving account New balance is : " << balance << endl;
    }
    void withdrawn(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn " << amount << " in saving account New balance is : " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance in saving account\n";
        }
    }
};
class CurrentAccount : public Account
{
private:
    double balance;

public:
    CurrentAccount()
    {
        balance = 0;
    }
    void deposit(double amount)
    {
        balance += amount;
    }
    void withdrawn(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Deposited " << amount << " in Current account New balance is : " << balance << endl;
        }
        else
        {
            cout << "Insufficient fund in current account\n";
        }
    }
};
class FixDepositAccount : public Account
{
private:
    double balance;

public:
    FixDepositAccount()
    {
        balance = 0;
    }
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited " << amount << " in FixTerm account New balance is : " << balance << endl;
    }
    void withdrawn(double amount)
    {
        throw logic_error("Withdrawn is not allowed in fix term account\n");
    }
};
class BankClient
{
private:
    vector<Account *> accounts;

public:
    BankClient(vector<Account *> accounts)
    {
        this->accounts = accounts;
    }
    void processTransactions()
    {
        for (auto acc : accounts)
        {
            acc->deposit(1000);

            try
            {
                acc->withdrawn(500);
            }
            catch (const logic_error &e)
            {
                cout << "Exception " << e.what() << endl;
            }
        }
    }
};

int main()
{
    vector<Account *> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixDepositAccount());

    BankClient *client = new BankClient(accounts);

    client->processTransactions();
    return 0;
}