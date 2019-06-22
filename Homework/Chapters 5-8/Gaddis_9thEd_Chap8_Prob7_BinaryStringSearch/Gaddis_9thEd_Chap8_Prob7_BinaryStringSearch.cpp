/*
 *            PROGRAMMER: Caleb Riggs
 *         PROBLEM TITLE: Binary String Search
 *    PROBLEM DEFINITION: Modify the binarySearch function presented in this chapter
 *                        so it searches an array of strings instead of an array of ints. 
 *                  DATE: 6/21/2019
 *     SYSTEM - HARDWARE: Intel i7
 *            - SOFTWARE: MS Windows 10, Netbeans IDE 8.0.2
 *         Input Devices: Keyboard
 *        Output Devices: Terminal screen                                                            
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Function Prototypes
void sortArray(string [], int); 
int binarySearch(string [], int, string);
const int SIZE = 20;;

int main()
{
    const int NUM_NAMES = 20;                          
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri", 
                               "Taylor, Terri", "Johnson, Jill",
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                               "James, Jean", "Weaver, Jim", "Pore, Bob",
                               "Rutherford, Greg", "Javens, Renee",
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth"}; 
    
    // Insert your code to complete this program
    
    string searchValue;
    int position;
    
    //Sort array.
    sortArray(names, NUM_NAMES);
    
    // Display the sorted elements.
    cout << "here are the sorted names: \n";
    for ( auto element : names)
        cout << element << endl;
    cout << endl;
    
    //Ask for name to find
    cout << "Enter a name to search for: ";
    getline(cin, searchValue);
    
    //Search for name.
    position = binarySearch(names, NUM_NAMES, searchValue);
    
    //Display the results
    if (position != -1)
    {
        cout << "That Name if found at position " << position << endl;
    }
    else
    {
        cout << "That name is not found. \n";
    }
    return 0;
}

//**********************************************************************
// The sortArray function sorts a array in ascending order             *
//**********************************************************************
void sortArray(string names[], int size)
{
    int start,
        minIndex;    
    string minValue;
    
    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = names[start];
        for (int index = start +1; index < size; index++)
        {
            if (names[index] < minValue)
            {
                minValue = names[index];
                minIndex = index;
            }
        }
        names[minIndex] = names[start];
        names[start] = minValue;
    }
}


//***************************************************************
// The binarySearch function performs a binary search on a      *
// string vector. array, which has a maximum of size elements,  *
// is searched for the number stored in value. If the number is *
// found, its vector subscript is returned. otherwise, -1 is    *
// returned indicating the value was not in the vector.         *
//***************************************************************
int binarySearch(string names[], int size, string value)
{
    int first = 0,             // First array element
        last = size - 1,       // Last array element
        middle,                // Mid point of search
        position = -1;         // Position of search value
    bool found = false;        // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point
        if (names[middle] == value)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (names[middle] > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;           // If value is in upper half
    }
    return position;
}