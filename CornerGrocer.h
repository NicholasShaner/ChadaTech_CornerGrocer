//CornerGrocer.h
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

#ifndef CORNER_GROCER_H
#define CORNER_GROCER_H

#include <iostream>  // required definition for handling user intput and output
#include <fstream>  // required definition for reading/writing to file
#include <string>  // required definition for receiving strings
#include <map>  // required definition for creating and manipulating maps

using namespace std;

// global variables for menu selection and handling
char menuSelect;  // character variable declared for user input of menu selection
string searchItem;  // string variable declared for user input of search term within menu option 1

/*
* class GroceryItems declaration*/
class GroceryItems {
    public:
        // default constructor declaration
        GroceryItems();

        // program declarations
        ifstream listIn;  // create input stream object for reading from file
        ofstream freqOut;  // create output stream object for writing to file

        // function declarations
        void displayMenu();  // function declaration for displayMenu
        void userSelect(char);  // function declaration for userSelect
        void findMatch(string);  // function declaration and parameter for findMatch
        void mapList();  // function  declaration for mapList
        void histogramList();  // function declaration for histogramList

    //private values used only within class
    private:
        string name;
        int quantity;
};



#endif