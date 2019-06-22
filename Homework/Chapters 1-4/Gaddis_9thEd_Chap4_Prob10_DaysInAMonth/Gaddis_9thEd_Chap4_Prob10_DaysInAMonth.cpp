/*
 *            PROGRAMMER: Caleb Riggs
 *         PROBLEM TITLE: Days in a month
 *    PROBLEM DEFINITION: Program that asks user to enter month and year and displays # of days in that month.
 *                  DATE: 6/18/2019
 *     SYSTEM - HARDWARE: Intel i7
 *            - SOFTWARE: MS Windows 10, Netbeans IDE 8.0.2
 *         Input Devices: Keyboard
 *        Output Devices: Terminal screen                                                            
 */

#include <iostream>
using namespace std;

int main()
{
    int year = 0;
    int month = 0;    
    int days;
    
    // Display program purpose.
    cout << "This program is designed to tell you how many days are in a specific month.\n";
    
    // Prompt the user to enter a month and year.
    cout << "Please enter the year: ";
    cin >> year;
    
    cout << "Please enter the month(1-12): ";
    cin >> month;
    
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        days = 30;
    }
    else if (month == 02)
    {
        bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        
        if (leapyear == 0)
        {
            days = 28;
        }
        else
        {
            days = 29;
        }
    }
    else
    {
        days = 31;
    }
    
    cout << "Month " << month << " in year " << year << " has: " << endl;
    cout << days << " days.";
    
    return 0;
}
    

