/*
 *            PROGRAMMER: Caleb Riggs
 *         PROBLEM TITLE: Currency
 *    PROBLEM DEFINITION: Program to convert USD to JPY and Euros
 *                  DATE: 6/18/2019
 *     SYSTEM - HARDWARE: Intel i7
 *            - SOFTWARE: MS Windows 10, Netbeans IDE 8.0.2
 *         Input Devices: Keyboard
 *        Output Devices: Terminal screen                                                            
 */

#include <iostream>
#include <iomanip>

using namespace std;

// main function here
int main()
{
    //Named constants for conversion rates
    const double YEN_PER_DOLLAR = 108.48;
    const double EUROS_PER_DOLLAR = 0.89;
    
    double USD,
           JPY,
           EURO;
    
    // Display program purpose.
    cout << "This program is designed to convert U.S. dollar amounts to Japanese yen and to euros.\n";
    
    // Prompt the user to enter a value for amount of USD.
    cout << "Please enter the amount of U.S. dollars: ";
    cin >> USD;
    
    //Convert to Yen
    JPY = USD * YEN_PER_DOLLAR;
    //Convert to euro
    EURO = USD * EUROS_PER_DOLLAR;
    
    //Display in fixed point notation
    cout << setprecision(2) << fixed;
    cout << "The value in Japanese yen is: " << JPY << " yen" << endl;
    cout << "The value in Euros is: " << EURO << " euros" << endl;
		
    return 0;
}
