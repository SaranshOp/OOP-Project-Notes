#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <stdexcept>

using namespace std;
typedef long long ll;

class BalanceException : public exception
{
    string errorMessage;

public:
    BalanceException(const string &message) : errorMessage(message) { cout << "BalanceException: " << errorMessage << endl; }
};

class Account
{
public:
    float Balance;
    string name;
    int accid;
    Account() {} // Default constructor
    Account(string name, int accid, float balance)
    {
        this->name = name;
        this->accid = accid;
        this->Balance = balance;
    }

    void getBalance()
    {
        cout << "Account ID: " << accid
             << ", Name: " << name
             << ", Balance: $" << fixed << setprecision(2) << Balance
             << endl;
    }
    virtual void deposit(float num)
    {
        Balance += num;
        cout << "Deposited $" << num << " to " << name << "'s account" << endl;
        this->getBalance();
    };
    void verifyTransfer(float num)
    {
        if (num <= this->Balance)
            return;
        else
        {
            throw BalanceException(string("Insufficient balance for withdrawal."));
        }
    };
    virtual void withdraw(float num)
    {
        try
        {
            this->verifyTransfer(num);
            Balance -= num;
            cout << "Money withdrawn $" << num << endl;
            getBalance();
        }
        catch (BalanceException &e)
        {
            cout << "Withdraw failed: " << e.what() << endl;
        }
    };

    void transfer(float num, Account &acc)
    {
        try
        {
            cout << "*********** Transfer Started : ╰(*°▽°*)╯ ********** \n";
            this->verifyTransfer(num);
            this->withdraw(num);
            acc.deposit(num);
            cout << "*********** Transfer  Completed : q(≧▽≦q) *********** \n";
        }
        catch (BalanceException &e)
        {
            cout << "*********** Transfer failed: {{{(>_<)}}}  *********** " << e.what() << endl;
        }
    };
};

class InterestRewardsAccount : public Account
{
public:
    float interestRate;
    InterestRewardsAccount(string name, int accid, float balance, float interestRate) : Account(name, accid, balance), interestRate(interestRate) {}

    int applyInterest(int num)
    {
        num += num * (interestRate / 100);
        cout << "Interest applied : $" << fixed << setprecision(2) << num << endl;
        return num;
    }
    void deposit(float num) override
    {
        num = applyInterest(num);
        Balance += num;
        cout << "Deposited $" << num << " to " << name << "'s account" << endl;
        this->getBalance();
    };
};

class SavingsAccount : public Account
{
public:
    int fee = 5;
    SavingsAccount(string name, int accid, float balance) : Account(name, accid, balance) {}
    void withdraw(float num) override
    {
        try
        {
            this->verifyTransfer(num + fee);
            Balance -= (num + fee);
            cout << "Money withdrawn with intrest $" << num + fee << endl;
            getBalance();
        }
        catch (BalanceException &e)
        {
            cout << "Withdraw failed: " << e.what() << endl;
        }
    };
};