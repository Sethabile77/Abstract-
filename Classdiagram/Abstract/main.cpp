#include <iostream>
#include <string>
using namespace std;

class Account
{

protected:
    string pin;
    float balance;
    string owner;

public:
    bool checkPin(string pin)
    {
        if (this->pin == pin)
        {
            return true;
        }
        cout << "INVALID" << endl;
        return false;
    }
    Account(string pin, float amount, string owner) : pin(pin), balance(amount), owner(owner)
    {
    }
    float getBalance() const
    {
        cout << "Balance: " << balance << endl;
        return balance;
    }
    virtual bool spendCredit(string pin, float amount) = 0;
    virtual bool increaseOverdraft(string pin, float amount) = 0;
    virtual bool withdrawCash(string pin, float amount) = 0;
};

class CreditAccount : public Account
{
private:
    float creditLimit;

public:
    CreditAccount(string pin, float balance, string owner, float credit) : Account(pin, balance, owner), creditLimit(credit)
    {
    }
    bool increaseOverdraft(string pin, float amount)
    {
        if (!checkPin(pin))
        {
            return false;
        }
        else
        {
            balance += amount;
            return true;
        }
    }
    bool withdrawCash(string pin, float amount)
    {
        if (!checkPin(pin))
        {

            return false;
        }
        if (amount <= balance)
        {
            balance -= amount;
            return true;
        }
        return false;
    }
    bool spendCredit(string pin, float amount)
    {
        if (!checkPin(pin))
        {
            return false;
        }
        if (amount < creditLimit && balance >= amount)
        {
            balance -= amount;
            cout << "Transaction sucessful." << endl;
            return true;
        }
        return false;
    }
};

int main()
{
    CreditAccount ca("2345", 1000.00f, "John", 500.00f);
    ca.spendCredit("9999", 200.00f);
    ca.spendCredit("2345", 200.00f);
    ca.getBalance();
}