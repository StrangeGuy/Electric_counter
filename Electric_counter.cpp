// Electric_counter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cin;
using std::cout;

const double RATE[]{ .456,.789,1.479 };
const double NIGHT_COEFFICIENT{ .5 };

double calculate_pay(double day, double night);


int main()
{
    
    double day_use{ 0 }, night_use{ 0 }, day_curr{ 0 }, night_curr{ 0 }, tmp_day{ 0 }, tmp_night{ 0 }, pay_curr{ 0 }, pay_total{0};
    cout << "Hello! I'm your smart electric counter. Let's collect some information. \n Please give me two numbers: one for the day use of electricity< the other for the night use. \n";
    while (cin >> tmp_day >> tmp_night)
    {
        if (tmp_day >= day_use && tmp_night >= night_use)
        {
            day_curr = tmp_day - day_use;
            night_curr = tmp_night - night_use;
            day_use = tmp_day;
            night_use = tmp_night;
            pay_curr = calculate_pay(day_curr, night_curr);
            pay_total += pay_curr;
            cout << "Your bill for the last month is: " << pay_curr << " tugriks.\n";
            pay_total += pay_curr;
        }
        else cout << "Hmmm... are you sure? Please, check your input, and try again. \n";
    }
    cout<<"The total sum you have paid is: "<<pay_total<<" tugriks.\n"
}


double calculate_pay(double day, double night)
{
    double sum{ 0 };
    if (day <= 100) sum += day * RATE[0];
    else if (day <= 600) sum += (100 * RATE[0] + (day - 100) * RATE[1]);
    else sum += (100 * RATE[0] + 500 * RATE[1] + (day - 600)*RATE[2]);
    if(night <= 100) sum += (night * RATE[0])* NIGHT_COEFFICIENT;
    else if (night <= 600) sum += (100 * RATE[0] + (night - 100) * RATE[1])*NIGHT_COEFFICIENT;
    else sum += (100 * RATE[0] + 500 * RATE[1] + (night - 600) * RATE[2])* NIGHT_COEFFICIENT;
    return sum;
}

