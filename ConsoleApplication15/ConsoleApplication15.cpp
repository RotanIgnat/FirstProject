#include <iostream>
#include <ctime>
#include <string>
using namespace std;
class BranchFinances {
private:
    int profit;
    int revenue;
    const int percent_of_rental_income = 7;
    const int employee_salary = 35;
    const int Auror_services = 15;
    const int initial_rent_price = 50;
    const int increase_in_rental_price = 270;
    int rent_price;
    int expenses;
public:
    BranchFinances(){
        f_rent_price();
    }
    void f_rent_price() {
        if (profit > increase_in_rental_price) {
            rent_price = initial_rent_price + (profit-increase_in_rental_price)* rand() * percent_of_rental_income / 100;
        }
        else {
            rent_price = initial_rent_price;
        }
    }
    void all_expenses() {
        expenses = 3 * employee_salary + rent_price + Auror_services;
    }
    void print_all_expenses() {
        cout << "sum all expenses - " << expenses << endl;
        cout << "rent_price - " << rent_price << endl;
        cout << "x3 employee_salary - " << 3*employee_salary << endl;
        cout << "Auror_services - " << Auror_services << endl;
    }
    void revenue_calculation(){
        revenue = rand() % 250 + 250;
    }
    int profit_calculation() {
        profit = revenue - expenses;
        return profit;
    }
};
class NewBranch : public BranchFinances {
private:
    string branch_name;
public:
    NewBranch(string x) {
        branch_name = x;
    }
    string print_NameBranch(){
        return branch_name;
    }
};
int main()
{
    string NameBranch;
    cout << "Please, print name branch: " << endl;
    cin >> NameBranch;
    NewBranch MyBranch(NameBranch);
    cout << "In branch " << MyBranch.print_NameBranch() << ": " << endl;
    MyBranch.revenue_calculation();
    MyBranch.all_expenses();
    MyBranch.print_all_expenses();
    cout << "profit - " << MyBranch.profit_calculation();
}