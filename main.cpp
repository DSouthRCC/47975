/* 
 * File:   main.cpp
 * Author: D
 *
 * Created on November 22, 2013, 7:33 PM
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

//header includes
#include "IntArray.h"
#include "TestScores.h"
#include "SimpleVector.h"
#include "SearchableVector.h"

using namespace std;

//program functions
void program1();
void program2();
void program3();
void program4();

//program function prototypes
//templates go above main

template <class T>
T totals(T size) {
    float number = 0; //user entered number to add
    float total = 1; //total of all user entered numbers
    int i = 0; //used to display entered number

    //loop to get numbers
    cout << "Enter as many numbers as you would like. Enter \"-1\" for your total" << endl;
    while (number != -1) {
        cout << "number " << i + 1 << ": ";
        cin >> number;
        //make total
        total = total + number;
        //increment entered number value
        i++;
    }
    //return total
    return total;
}

int main(int argc, char** argv) {

    //declare variables

    //program variables
    short menu = 0; //var to run menu
    char repeat; //var to repeat programs

    //set precision to 2 decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //welcome message
    cout << "David South - Assignment 5\n This assignment uses several examples taken from the class textbook per assignment requirements\nand have been modified to complete the challenges."
            << endl << endl;

    //begin menu loop
    do {
        //menu options
        cout << "Select which problem to view:\n";
        cout << endl
                << "1: 16.6 IntArray Class Exception\n"
                << "2: 16.7 TestScores Class\n"
                << "3: 16.5 Total Template\n"
                << "4: 16.9 SearchableVector Modification\n"
                << "Choose 5 to exit\n"
                << endl
                << "Enter your choice and press Return: ";
        cin >> menu;

        cout << endl;

        //process choices	
        switch (menu) {
            case 1:
                //problem description

                //begin do loop
                do {
                    //program
                    program1();

                    //prompt for loop escape
                    cout << "Would you like to repeat this program? (y or n)";
                    cin >> repeat;
                    cout << endl;

                }//end do loop
                while (repeat == 'y');
                break;

            case 2:
                //problem description

                //begin do loop
                do {
                    //program
                    program2();

                    //prompt for loop escape
                    cout << "Would you like to repeat this program? (y or n)";
                    cin >> repeat;
                    cout << endl;

                }//end do loop
                while (repeat == 'y');
                break;

            case 3:
                //problem description

                //begin do loop
                do {
                    //program
                    program3();

                    //prompt for loop escape
                    cout << "Would you like to repeat this program? (y or n)";
                    cin >> repeat;
                    cout << endl;

                }//end do loop
                while (repeat == 'y');
                break;

            case 4:
                //problem description

                //begin do loop
                do {
                    //program
                    program4();

                    //prompt for loop escape
                    cout << "Would you like to repeat this program? (y or n)";
                    cin >> repeat;
                    cout << endl;

                }//end do loop
                while (repeat == 'y');
                break;

            case 5:
                //exit message
                cout << endl << "This concludes \"Assignment 5\"\n" << endl;
                //closes program
                exit(1);
                break;
        }

        //provide output for incorrect choice
        if (menu < 1 || menu > 5) {
            cout << endl << "You have selected an invalid input.  Please select again:";
        }

    }//end menu loop
    while (menu != 5);

    return 0;
}

void program1() {
    const int SIZE = 10; // Array size

    // Define an IntArray with 10 elements.
    IntArray table(SIZE);

    // Store values in the array.
    for (int x = 0; x < SIZE; x++)
        table[x] = x;

    // Display the values in the array.
    for (int x = 0; x < SIZE; x++)
        cout << table[x] << " ";
    cout << endl;

    try {
        //test for invalid (uses actual invalid value)
        cout << "Now attempting to use an invalid subscript.\n";
        table[SIZE + 1] = 0;
    } catch (string subscriptError) {
        cout << subscriptError;
    }
}

void program2() {

    TestScores tests; //creates class object 
    int numScores = 0; //user provided number od scores
    int *score = new int[numScores]; //creates a new score array
    int total = 0; //holds total
    float avg = 0.0; //holds average

    //get user input
    cout << "enter number of scores: ";
    cin >> numScores;
    //set the number os scores
    tests.setNumScores(numScores);
    //user input for scores
    cout << "num scores: " << tests.getNumScores() << endl;
    cout << endl;
    cout << "Enter scores: " << endl;
    //get scores
    for (int i = 0; i < numScores; i++) {
        cout << "Score " << i + 1 << ": ";
        //record score
        cin >> *(score + i);
    }
    cout << endl;
    //display created array
    cout << "entered scores: " << endl;
    //show array
    for (int i = 0; i < numScores; i++) {
        cout << *(score + i) << " ";
    }
    cout << endl;
    for (int i = 0; i < numScores; i++) {
        //check for incorrect values
        try {
            tests.setScores(*(score + i), i);
            total = total + (*score + i);
        }        //exit if found
        catch (TestScores::Error) {
            cout << "Error - you have entered a negative value for score " << i + 1 << endl;
            cout << "Program will now exit";
            exit(1);
        }
    }
    //create average
    avg = total / numScores;
    //show total and average
    cout << endl;
    cout << "total: " << total << endl;
    cout << "average: " << avg;
    cout << endl;
}

void program3() {

    float size = 0; //user input size
    setprecision(3); // sets precision for float to 3
    //run template and show
    cout << "Your total is: " << totals(size) << endl;
}

void program4() {
    const int SIZE = 10; // Number of elements
    int count; // Loop counter
    int result; //predefined results check
    int intRes; //integer results
    int fltRes; //float results
    int userInt; //user provided search number
    float userFlt; //user provided search number(float)
    char ans; //to run predefined script if wanted


    // Create two SearchableVector objects.
    SearchableVector<int> intTable(SIZE);
    SearchableVector<float> floatTable(SIZE);

    cout << "Enter an integer you would like to search for: ";
    cin >> userInt;
    cout << endl << "Enter a floating point number you would like to search for: ";
    cin >> userFlt;
    cout << endl;
    // Store values in the objects.
    for (count = 0; count < SIZE; count++) {
        intTable[count] = (count * 2);
        floatTable[count] = (count * 2.14);
    }

    // Display the values in the objects.
    cout << "These values are in intTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << intTable[count] << " ";
    cout << endl << endl;
    cout << "These values are in floatTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << floatTable[count] << " ";
    cout << endl;

    // Search for the value 6 in intTable.
    cout << "\nSearching for " << userInt << " in intTable.\n";
    intRes = intTable.findItem(SIZE, userInt);
    if (intRes == -1)
        cout << userInt << " was not found in intTable.\n";
    else
        cout << "6 was found at subscript " << result << endl;

    // Search for the value 12.84 in floatTable.
    cout << "\nSearching for " << userFlt << " in floatTable.\n";
    fltRes = floatTable.findItem(SIZE, userFlt);
    if (fltRes == -1)
        cout << userFlt << " was not found in floatTable.\n";
    else
        cout << "12.84 was found at subscript " << result << endl;
    cout << endl;
    if (intRes == -1 || fltRes == -1) {
        cout << "Would you like to run the default search?(y or n)";
        cin >> ans;
        if (ans == 'y') {
            // Search for the value 6 in intTable.
            cout << "\nSearching for 6 in intTable.\n";
            result = intTable.findItem(SIZE, 6);
            if (result == -1) {
                cout << "6 was not found in intTable.\n";
            } else {
                cout << "6 was found at subscript " << result << endl;
            }

            // Search for the value 12.84 in floatTable.
            cout << "\nSearching for 12.84 in floatTable.\n";
            result = floatTable.findItem(SIZE, 12.84);
            if (result == -1) {
                cout << "12.84 was not found in floatTable.\n";
            } else {
                cout << "12.84 was found at subscript " << result << endl;
            }
        }
        cout << endl;
    } else {
        cout << endl << "defaults not running";
        cout << endl;
    }
}