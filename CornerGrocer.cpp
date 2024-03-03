#include "CornerGrocer.h"
#include <fstream>
#include <iostream>

using namespace std;

void CornerGrocer::readInputFile() { 
    ifstream inFS("CS210_Project_Three_Input_File.txt"); //Here I am opening the input file.
    string item;

    cout << "Opening file CS210_Project_Three_Input_File.txt" << endl;

    if (!inFS.is_open()) { //Here I am confirming that the file opened successfully.
        cout << "Could not open file CS210_Project_Three_Input_File.txt" << endl;
        return;
    }

    cout << "Reading items." << endl;
    while (inFS >> item) { //This will read items from the input file and count the frequency in which they occur.
        itemFrequency[item]++;
    }

    cout << "Items read:" << endl;
    for (const auto& pair : itemFrequency) { //Here I am printing the frequency of each item from the input file.
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Closing the file" << endl;
    inFS.close(); //Once I am finished reading from the input file I close it.
}

void CornerGrocer::writeToFrequencyDataFile() {
    ofstream outFS("frequency.dat"); //Here I am opening the output file I created to begin writing to it.

    if (!outFS.is_open()) { //Confirmation the output file opened successfully.
        cout << "Could not open file frequency.dat" << endl;
        return;
    }

    for (const auto& pair : itemFrequency) { //Here I am writing what I previously read from the input file to the output file.
        outFS << pair.first << " " << pair.second << endl;
    }

    cout << "Closing the file frequency.dat" << endl;
    outFS.close(); //I finished writing to the output file so now I am closing it.
}

void CornerGrocer::userMenu() {
    int option;

    do { //Here I wrote the code that prints the user menu with 4 options.
        cout << "\nMenu:\n";
        cout << "1. Input an item to search for\n";
        cout << "2. Print a list of all items purchased and their frequencies\n";
        cout << "3. Print items purchased and their frequencies as a histogram\n";
        cout << "4. Exit\n";
        cin >> option;

        switch (option) {
        case 1: //In this section I used each of the functions I created previously for the menu options as well as an option to exit the program.
            itemSearch();
            break;
        case 2:
            printItemFrequency();
            break;
        case 3:
            printHistogram();
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "The number chosen is invalid." << endl;
        }
    } while (option != 4); //The menu will continue to loop after each option until the user decides to exit the program.
}

void CornerGrocer::itemSearch() {
    string itemSearched;
    cout << "Input an item to search for: ";
    cin >> itemSearched;

    if (itemFrequency.count(itemSearched) > 0) { //Here I am checking if the item appears in the data in the input file
        cout << "Frequency " << itemSearched << ": " << itemFrequency[itemSearched] << endl;
    }
    else {
        cout << "Item not found." << endl; //If the item does not appear this message will print and the user will be looped back through the menu.
    }
}

void CornerGrocer::printItemFrequency() {
    cout << "Print a list of all items purchased and their frequencies\n";
    cout << "Items in itemFrequency:" << endl;
    for (const auto& pair : itemFrequency) { //This will print menu option 2 which is a list of all items and their frequencies.
        cout << pair.first << ": " << pair.second << endl;
    }
}

void CornerGrocer::printHistogram() {
    cout << "Print items purchased and their frequencies as a histogram.\n";
    for (const auto& pair : itemFrequency) { //This will print the items and their frequencies in the form of a histogram.
        cout << pair.first << " " << string(pair.second, '*') << endl;
    }
}

