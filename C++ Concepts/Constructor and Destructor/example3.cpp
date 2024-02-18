// Dynamic Initialization of Constructors
// Long term Fixed deposit system

#include <iostream>
using namespace std;

class fixed_deposit
{
private:
    long int p_amt;
    int years;
    float rate;
    float r_val;

public:
    fixed_deposit() {}
    fixed_deposit(long int p, int y, float r = 0.12);
    fixed_deposit(long int p, int y, int r);
    void display();
};

fixed_deposit::fixed_deposit(long int p, int y, float r)
{
    p_amt = p;
    years = y;
    rate = r;
    r_val = p_amt;
    for (int i = 1; i <= y; i++)
        r_val = r_val * (1.0 + r);
}

fixed_deposit::fixed_deposit(long int p, int y, int r)
{
    p_amt = p;
    years = y;
    rate = r;
    r_val = p_amt;
    for (int i = 1; i <= y; i++)
        r_val = r_val * (1.0 + float(r) / 100);
}

void fixed_deposit ::display()
{
    cout << "\n"
         << "Principal Amount: " << p_amt << "\n"
         << "Return value: " << r_val << "\n";
}

int main()
{
    fixed_deposit fd1, fd2, fd3;
    long int p;
    int y;
    float r;
    int R;

    cout << "Enter amount, period, interest rate(in percent): ";
    cin >> p >> y >> R;
    fd1 = fixed_deposit(p, y, R);

    cout << "Enter amount, period, interest rate(in decimal): ";
    cin >> p >> y >> r;
    fd2 = fixed_deposit(p, y, r);

    cout << "Enter amount, period: ";
    cin >> p >> y;
    fd3 = fixed_deposit(p, y);

    cout << "\nDeposit 1: ";
    fd1.display();
    cout << "\nDeposit 2: ";
    fd2.display();
    cout << "\nDeposit 3: ";
    fd3.display();
    return 0;
}