//CornerGrocer.cpp
/***************
 *  CS-210 7-3 Project Three
 *  CornerGrocer.cpp
 *
 *  Nicholas Shaner
 *  SNHU
 *  CS-210-R4727
 *  Prof. Cory Thoma
 *  April 24, 2024
 * 
 ***************/

#include "CornerGrocer.h"  // inheritance of header file and program declarations

// default constructor
GroceryItems::GroceryItems() {
    string name = "NULL";
    int quantity = -1;
}


/*
* displayMenu function to output available menu options and descriptions to user
*/
void GroceryItems::displayMenu() {
    cout << "Please Make a Selection (1, 2, 3, 4): \n";
    cout << "Option 1: Check frequency of item in list\n";
    cout << "Option 2: Print list and numerical frequency each item\n";
    cout << "Option 3: Print list and frequency of each item as histogram\n";
    cout << "Option 4: Exit program\n";
}


/*
* userSelect function definition with character parameter. used to validate and handle 
* user input of selected menu option
*/
void GroceryItems::userSelect(char menuSelect) {

    // switch statement to handle users menu selection
    switch (menuSelect)
    {
    case '1':
        cout << "Please enter an item to search: \n";
        cin.ignore(256, '\n');
        getline(cin, searchItem);
        findMatch(searchItem);
        break;
    case '2':
        mapList();
        break;
    case '3':
        histogramList();
        break;
    }
    // case 4 and default ommitted. input validation, exit strategy and handling performed in main.cpp
}


/*
* findMatch function definition and string parameter. Rebuilds GroceryItem list after each menu call
* to handle any changes to Grocerylist.txt prior to searching Map keys for matching user value
*/
void GroceryItems::findMatch(string searchItem) {

    string nextLine;  // declared variable for reading from file
    map <string, int> GrocerList;  // declared map GrocerList

    listIn.open("GroceryList.txt");  // txt file opened from directory

    if (listIn.fail()) {  // error handling in case the file has been moved or an error getting input
        cout << "There seems to be an issue with the datafile, please restart the program\n";
        exit(0);
    }
    // while loop to iterate until there is nothing left to iterate over
    while (listIn >> nextLine) {

            if (GrocerList.count(nextLine)) {  // if the next item key is already in the Map
                GrocerList[nextLine]++;  // increment 1 to the current key value
            }
            else {
                GrocerList.emplace(nextLine, 1);  // else the next item it not in the map and new item created and initilized to key of 1
            }        
    }
    if (GrocerList.count(searchItem)) {  // if the user entered item is in the Map keys
        cout << "Number of " << searchItem << ": " << GrocerList.at(searchItem) << endl;
    }
    else {  // input validation for items searched that are not in the Map
        cout << "I'm sorry, it does not seem that we have record of that item \n";
    }
    
    cout << endl;

    listIn.close();  // close the input stream
}


/*
* mapList function definition. Rebuilds GroceryItem list after each menu call
* to handle any changes to Grocerylist.txt prior to outputting Key : Value pairs 
*/
void GroceryItems::mapList() {
    string nextLine;  // declared variable for reading from file
    map <string, int> GrocerList;  // declared map GrocerList

    freqOut.open("frequency.dat");
    listIn.open("GroceryList.txt");  // txt file opened from directory

    if (listIn.fail()) {  // error handling in case the file has been moved or an error getting input
        cout << "Could not open file GraceryList.txt\n";
        exit(0);
    }
    // while loop to iterate until there is nothing left to iterate over
    while (listIn >> nextLine) {

            if (GrocerList.count(nextLine)) {  // if the next item key is already in the Map
                GrocerList[nextLine]++;  // increment 1 to the current key value
            }
            else {
                GrocerList.emplace(nextLine, 1);  // else the next item it not in the map and new item created and initilized to key of 1
            }        
    }

    for (auto GroceryItems : GrocerList) {  // for loop to iterate through each Key : Value pair
        cout << GroceryItems.first << " " << GroceryItems.second << endl;  // print statement to display Key : Value pair
        freqOut << GroceryItems.first << " " << GroceryItems.second << endl;  // output stream to backup Key : Value pairs to output file frequency.dat
    }
    cout << endl;

    listIn.close();  // close input stream
    freqOut.close();  // close output stream
}


/*
* histogramList function definition. Rebuilds GrocerList after each menu call 
* to handle any changes potentially made to GroceryList.txt prior to outputting Key : Value pairs.
* Values represented in histogram with Values depicted at '*'.
*/
void GroceryItems::histogramList(){
    string nextLine;  // declared variable for reading from file
    map <string, int> GrocerList;  // declared map GrocerList

    listIn.open("GroceryList.txt");  // txt file opened from directory

    if (listIn.fail()) {  // error handling in case the file has been moved or an error getting input
        cout << "Could not open file GraceryList.txt\n";
        exit(0);
    }
    // while loop to iterate until there is nothing left to iterate over
    while (listIn >> nextLine) {

        if (GrocerList.count(nextLine)) {  // if the next item key is already in the Map
            GrocerList[nextLine]++;  // increment 1 to the current key value
        }
        else {
            GrocerList.emplace(nextLine, 1);  // else the next item it not in the map and new item created and initilized to key of 1
        }        
    }

    for (auto GroceryItems : GrocerList) {  // for loop to iterate through each Key : Value pair
        int value = GroceryItems.second;  // declare integer variable initialized to value of current map Key
        cout << GroceryItems.first << " ";  // print statement to display key
        // for loop to iterate over the number of occurances of each item and display histogram of key values as '*'
        for (int i = 0; i < value; i++) {  
            cout << '*';
        }
        cout << endl;
        value = 0;  // resets value of variable for next map Key iteration
    }
    cout << endl;

    listIn.close();  // closes input stream
}
