#include <iostream>
// #include <bits/stdc++.h>
using namespace std;
template <typename A>
A swap_no(A x, A y)
{
    A t;
    t = x;
    x = y;
    y = t;
    cout << endl;
    return x, y;
    cout << endl;
};

class Atm
{
private:
    string name;
    int ac_no, c_n, pin, balance;

public:
    Atm(string name, int ac_no, int c_n, int pin, int balance)
    {
        this->name = name;
        this->ac_no = ac_no;
        this->c_n = c_n;
        this->pin = pin;
        this->balance = balance;
    }
    void get()
    {

        cout << "name" << name << endl;
        cout << "Account no:" << ac_no << endl;
        cout << "Contact no:" << c_n << endl;
        cout << "Balance:" << balance << endl;
    }
    void deposit(int b, int p)
    {
        try
        {
            if (p == pin)
                cout << char(251) << endl;
            else
            {
                throw(p);
            }
        }
        catch (int d)
        {
            cout << "entered wrong pin!    X" << endl;
        }

        balance += b;
    }
    void withdraw(int w, int p)
    {
        try
        {
            if (p == pin)
                cout << char(251) << endl;

            else
            {
                throw(p);
            }
        }

        catch (int d)
        {
            cout << "entered wrong pin!    X" << endl;
        }

        balance -= w;
    }
    void enquiry(int p)

    {
        try
        {
            if (p == pin)
            {
                cout << char(251) << endl;
                cout << "Balance:" << balance << endl;
            }
            else
            {
                throw(p);
            }
        }
        catch (int d)
        {
            cout << "entered wrong pin!    X" << endl;
        }
    }
};

int main()
{
    string name;
    int ac_no = 0, c_n = 0, p, balance = 0;
    cout << "ENTER CREDENTIALS:\n";
    cout << "\nENTER NAME:\n";
    cin >> name;
    cout << "\nENTER ACCOUNT NO:\n";
    cin >> ac_no;
    cout << "\n ENTER 4 PIN \n(REMEMBER IT):\n";
    cin >> p;
    cout << "\nENTER CONTACT NO:\n";

    cin >> c_n;

    cout << "\nENTER BALANCE:\n";
    cin >> balance;
    Atm a(name, ac_no, c_n, p, balance);

    a.get();

    int c = 0;

    cout << "\n1. SHOW DATA\n2.Deposit\n3.Balance Enquiry\n4. Withdrwal\n5.Template\n6.Cancel\n";

    c = -1;
    while (c != 6)
    {
        cout << "\nENTER CHOICE:\n"
             << endl;
        cout << "\n1. SHOW DATA\n2.Deposit\n3.Balance Enquiry\n4. Withdrwal\n5.Template\n6.Cancel\n";
        cin >> c;
        switch (c)
        {
        case 1:

            a.get();
            break;
        case 2:
            int pin;
            cout << "ENTER 4 digit PIN" << endl;
            cin >> pin;
            int b, w;
            cout << "\nenter amount to deposit: \n"
                 << endl;
            cin >> b;

            // d1 = deposit(b); //    a1 ++;
            a.deposit(b, pin);

            break;
        case 3:
            cout << "ENTER 4 digit PIN" << endl;
            cin >> pin;
            a.enquiry(pin);
            break;
        case 4:
            

            cout << "ENTER 4 digit PIN" << endl;
            cin >> pin;
            a.enquiry(pin);
            cout << "\nenter amount to withdraw: \n"
                 << endl;
            cin >> w;
            a.withdraw(w, pin);
            break;

        case 5:
            cout << swap_no<int>(4, 5);
            break;

        case 6:
            exit(0);
            break;
        default:
            cout << "enter valid:" << endl;
            break;
        }
    }
}
