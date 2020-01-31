#include <iostream>

using namespace std;

class BankAccount{
    private:
        int dollars;
        int coins;

    public:
        BankAccount(){
            dollars = 0;
            coins = 0;
        }
        int getDollars(){
            return dollars;
        }
        int getCoins(){
            return coins;
        }
        void setCoins(int x){
            coins = x;
        }
        void setDollars(int x){
            dollars = x;
        }

        void deposit(int dollar, int coin);
        void withdraw(int dollar, int coin);
        void Balance(){
            cout << dollars << " dollars " << coins << " cents" << endl;
        }
};

void BankAccount::deposit(int dollar, int coin){
    dollars += dollar;
    coins += coin;
    if (coins >= 100){
        dollars ++;
        coins -= 100;
    }
}

void BankAccount::withdraw(int dollar, int coin){
    if (dollar > dollars){
        cout << "You don't have that much money in your account." << endl;
    }
    else if(coin > coins && dollars - dollar < 1){
        cout << "You don't have that much money in your account." << endl;
    }
    else if(coin > coins){
        dollars = dollars - dollar - 1;
        coins = coins + 100 - coin;
    }
    else{
        dollars -= dollar;
        coins -= coin;
    }
}

int main()
{
    BankAccount a;
    
    int b,c;

    cout << "How much do you want to deposit? : ";
    cin >> b >> c;
    a.deposit(b, c);
    a.Balance();

    cout << "How much do you want to withdraw? : ";
    cin >> b >>c;
    a.withdraw(b, c);
    a.Balance();

    return 0;
}