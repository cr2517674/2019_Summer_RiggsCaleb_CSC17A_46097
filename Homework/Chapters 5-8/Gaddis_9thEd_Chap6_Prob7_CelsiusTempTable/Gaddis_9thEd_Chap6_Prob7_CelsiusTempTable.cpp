/*
 *            PROGRAMMER: Caleb Riggs
 *         PROBLEM TITLE: Celsius Temperature Table
 *    PROBLEM DEFINITION: Write a function that accepts a Fahrenheit temp as an argument,
 *                        returns the temp converted to Celsius and displays a table of,
 *                        the Fahrenheit temps(o - 20) and shows their Celsius equivalent.
 *                  DATE: 6/21/2019
 *     SYSTEM - HARDWARE: Intel i7
 *            - SOFTWARE: MS Windows 10, Netbeans IDE 8.0.2
 *         Input Devices: Keyboard
 *        Output Devices: Terminal screen                                                            
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototype
float celsius(float f); 
        
int main()
{  
    float c = 0.0f;
    
    cout << "This program displays the Celsius temperatures for 0 to 20 Fahrenheit." << endl;
    
    for (int i = 0; i < 21; i++)
    {
        c = celsius(i);
        cout << i << " Fahrenheit = " << setprecision(2) << c << " Celsius\n";
    }
}
    
float celsius (float f)
{
    float c = 0.0f;
    c = (5.0 / 9) * (f - 32);
    return c;
}


