/*
 *            PROGRAMMER: Caleb Riggs
 *         PROBLEM TITLE: Rain or Shine
 *    PROBLEM DEFINITION: Write a program that store info in a 3x30 array of characters to keep track,
 *                        of weather conditions. 
 *                  DATE: 6/21/2019
 *     SYSTEM - HARDWARE: Intel i7
 *            - SOFTWARE: MS Windows 10, Netbeans IDE 8.0.2
 *         Input Devices: Keyboard
 *        Output Devices: Terminal screen                                                            
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// GLobal constants
const int MONTHS = 3;
const int DAYS = 30;

// Function prototypes
void getRainData(char[][DAYS]);
void getCount(const char rainOrShine[][DAYS]);
void display(const int[], const int, const int[], const int, const int[], const int, const int);
int getMostRain(const int[]);

int main()
{
    char rainOrShine[MONTHS][DAYS] = {};
    getRainData(rainOrShine);
    
    return 0;
}

// getRainData function main
void getRainData(char rainOrShine[][DAYS])
{
    ifstream rainData;
    int months = 0,
        days = 0;
    
    rainData.open("RainOrShine.txt");
    
    if(rainData)
    {
        for (months = 0; months < MONTHS; months++)
        {
            for (days = 0; days < DAYS; days++)
            {
                rainData >> rainOrShine[months][days];
            }
        }
        getCount(rainOrShine);
    }
    else
    {
        cout << "Error! The file could not be opened.";
    }
    rainData.close();
}

// getCount function main
void getCount(const char rainOrShine[][DAYS])
{
    int frequencySun[MONTHS]   = {},
        frequencyRain[MONTHS]  = {},
        frequencyCloud[MONTHS] = {};
    
    int totalSun   = 0,
        totalRain  = 0,
        totalCloud = 0,
        days       = 0,    
        months     = 0,
        monthName  = 0;

    for (months = 0; months < MONTHS; months++)
    {
        for (days = 0; days < DAYS; days ++)
        {
            rainOrShine[months][days] == 'S' ? frequencySun[months] +=1:
                rainOrShine[months][days];
            
            rainOrShine[months][days] == 'R' ? frequencyRain[months] +=1:
                rainOrShine[months][days];
            
            rainOrShine[months][days] == 'C' ? frequencyCloud[months] +=1:
                rainOrShine[months][days];
        }
        
        totalSun += frequencySun[months];
        totalRain += frequencyRain[months];
        totalCloud += frequencyCloud[months];
    }
    monthName = getMostRain(frequencyRain);
    display(frequencySun, totalSun, frequencyRain, totalRain, frequencyCloud, totalCloud, monthName);
}

//getMostRain function main
int getMostRain(const int frequencyRain[])
{
    int monthName = 0,
        largest   = 0,
        months    = 0;
    
    for (months = 0; months < MONTHS; months++)
    {
        if(frequencyRain[months] > largest)
        {
            largest = frequencyRain[months];
            monthName = months;
        }
    }
    return monthName;
}

// display function main
void display(const int frequencySun[], const int totalSun,
             const int frequencyRain[], const int totalRain,
             const int frequencyCloud[], const int totalCloud,
             const int monthName)
{
    const int CHAR_NAME = 3;
    const string mName[MONTHS] = {"June", "July", "August"};
    char charName[CHAR_NAME] = {'S', 'R', 'C'};
    
    int months = 0,
        count = 0;
    
    // Display results
    cout << "     RAIN DATA\n";
    cout << "-------------------\n\n";
    cout << "Monthly Summary: \n";
    
    for (months = 0; months < MONTHS; months++)
    {
        cout << "\n" << mName[months] << ":\n";
        cout << "\n-------------------------------------------------\n";
        cout << "Sunny Days: " << setw(3); 
        cout << frequencySun[months] << "\t";
        
        for (count = 0; count < frequencySun[months]; count++)
        {
           cout << " " << charName[0];
        }
        cout << "\n-------------------------------------------------\n";

        cout << "Rainy Days: " << setw(3); 
        cout << frequencyRain[months] << "\t";
        
        for (count = 0; count < frequencyRain[months]; count++)
        {
           cout << " " << charName[1]; 
        }
        cout << "\n-------------------------------------------------\n";
   
        cout << "Cloudy Days: " << setw(2); 
        cout << frequencyCloud[months] << "\t";
        for (count = 0; count < frequencyCloud[months]; count++)
        {
           cout << " " << charName[2]; 
        }
        cout << "\n-------------------------------------------------\n";
    }
    
    cout << "\n\nTHREE MONTH SUMMARY:\n";
    cout << "\n-------------------------------------------------";
    cout << "--------------------------------------------\n";

    cout << "Sunny Days: " << setw(3) << totalSun << "\t";
    for (count = 0; count < totalSun; count++)
      {
         cout << " " << charName[0];
      }
    
    cout << "\n-------------------------------------------------";
    cout << "--------------------------------------------\n";

    cout << "Rainy Days: " << setw(3) << totalRain << "\t";
      for (count = 0; count < totalRain; count++)
      {
         cout << " " << charName[1];
      }
    cout << "\n-------------------------------------------------";
    cout << "--------------------------------------------\n";

    cout << "Cloudy Days: " << totalCloud << "\t";
    for (count = 0; count < totalCloud; count++)
    {
        cout << " " <<  charName[2];
    }
    cout << "\n-------------------------------------------------";
    cout << "--------------------------------------------\n\n";
      
    cout << "\nMONTH WITH MOST RAIN:\n\n" << mName[monthName] << "\n";
    cout << "-------------------------------------------------\n";
    for (months = 0; months < 1; months++)
    {
        cout << "Rainy Days: " << frequencyRain[monthName] << "\t";
        for (count = 0; count < frequencyRain[monthName]; count++)
         {
            cout << " " << charName[1];
         }
         cout << "\n-------------------------------------------------\n";
    }
}
