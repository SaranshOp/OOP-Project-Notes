
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#include "bank_accounts.cpp"

int main()
{
    Account Saransh = Account("Saransh K", 01, 1000);
    Account Chavi = Account("Charvi", 02, 2000);

    Saransh.getBalance();
    Chavi.getBalance();

    Saransh.deposit(500);

    Chavi.withdraw(10000);
    Chavi.withdraw(500);

    Saransh.transfer(10000, Chavi);
    Saransh.transfer(100, Chavi);

    Account *Sarthak = new InterestRewardsAccount("Sarthak", 03, 1000, 5);
    Sarthak->getBalance();
    Sarthak->deposit(500);

    InterestRewardsAccount Renu("Renu", 04, 2000, 10);
    Renu.getBalance();
    Renu.deposit(1000);
    Renu.withdraw(500);
    Renu.transfer(1000, Saransh);

    SavingsAccount Anisha("Anisha", 05, 1000);
    Anisha.getBalance();
    Anisha.deposit(500);
    Anisha.withdraw(1500);

    Anisha.transfer(1495, Saransh);
}
