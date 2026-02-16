#include <bits/stdc++.h>
using namespace std;

class DepositOnlyAccount
{
public:
    virtual void deposit(double amount) = 0;
    // virtual void withdrawn(double amount) = 0;
};
class WithdrawableAccount : public DepositOnlyAccount
{
public:
    virtual void withdrawn(double amount) = 0;
};

class SavingAccount : public WithdrawableAccount
{
private:
    double balance;

public:
    SavingAccount()
    {
        balance = 0;
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
class CurrentAccount : public WithdrawableAccount
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
        cout << "Deposited " << amount << " in Current account New balance is : " << balance << endl;
    }
    void withdrawn(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn " << amount << " in Current account New balance is : " << balance << endl;
        }
        else
        {
            cout << "Insufficient fund in current account\n";
        }
    }
};
class FixDepositAccount : public DepositOnlyAccount
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
};
class BankClient
{
private:
    vector<WithdrawableAccount *> withdrawableAccount;
    vector<DepositOnlyAccount *> depositOnlyAccount;

public:
    BankClient(vector<WithdrawableAccount *> withdrawableAccount, vector<DepositOnlyAccount *> depositOnlyAccount)
    {
        this->withdrawableAccount = withdrawableAccount;
        this->depositOnlyAccount = depositOnlyAccount;
    }
    void processTransactions()
    {
        for (auto acc : withdrawableAccount)
        {
            acc->deposit(1000);

            acc->withdrawn(400);
        }
        for (auto acc : depositOnlyAccount)
        {
            acc->deposit(1200);
        }
    }
};

int main()
{
    vector<WithdrawableAccount *> withdrawableAccount;
    vector<DepositOnlyAccount *> depositOnlyAccount;
    withdrawableAccount.push_back(new SavingAccount());
    withdrawableAccount.push_back(new CurrentAccount());
    depositOnlyAccount.push_back(new FixDepositAccount());

    BankClient *client = new BankClient(withdrawableAccount, depositOnlyAccount);

    client->processTransactions();
    return 0;
}