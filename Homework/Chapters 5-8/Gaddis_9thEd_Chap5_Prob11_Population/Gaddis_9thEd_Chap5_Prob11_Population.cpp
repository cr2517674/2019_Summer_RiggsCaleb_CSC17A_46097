/*
 *            PROGRAMMER: Caleb Riggs
 *         PROBLEM TITLE: Population
 *    PROBLEM DEFINITION: Write a program that will predict the size of a population of organisms
 *                  DATE: 6/18/2019
 *     SYSTEM - HARDWARE: Intel i7
 *            - SOFTWARE: MS Windows 10, Netbeans IDE 8.0.2
 *         Input Devices: Keyboard
 *        Output Devices: Terminal screen                                                            
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float start_pop = 0.0f;
    int num_days = 0;
    float avg_increase = 0.0f;
    float daily_pop = 0.0f;
          

    
    cout << "This program will predict the size of a population after a specified number of days." << endl;
    
    cout << "Please enter the starting number of organisms: ";
    cin >> start_pop;
    
    while (start_pop < 2)
    {
       cout << "Please enter a number 2 or higher. Try again: ";
       cin >> start_pop; 
    }
   
    cout << "Please enter the number of days the population will multiply: ";
    cin >> num_days;
    
    while (num_days < 1)
    {
      cout << "Please enter a value grater than or equal to 1. Try again: ";
      cin >> num_days;
    }
    
    cout << "Please enter the average daily population increase(as a percentage):% ";
    cin >> avg_increase;
    
    while (avg_increase < 0)
    {
        cout << "Please enter a positive number. Try again: ";
        cin >> avg_increase;    
    }
    
    for (int i = 1; i <= num_days; i++)
    {
        daily_pop = ((avg_increase / 100) * start_pop) + start_pop;
        cout << "On day " << i << " the population will be: ";
        cout << daily_pop << endl;
        start_pop = daily_pop;
    }
    
return 0;    
}
    


