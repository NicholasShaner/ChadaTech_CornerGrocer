//main.cpp
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
#include "CornerGrocer.cpp"  // inheritance of CornerGrocer file and defined functions

int main() {

    menuSelect = 0;  // initialized menu selection out of range for validation
    
    /*
    * do while loop to continue program iteration until program exitted*/
    do {
        GroceryItems GroceryItems;  // class object initialization to obtain program within class scope

        bool runProgram = true;
        GroceryItems.displayMenu();  // function call to display menu options function
        cin >> menuSelect;  // user input of menu selection

        // while loop to handle and validate user input of menu selection
        while (runProgram) {
            // if menu selection is 1 - 3, menuSelect is passed as parameter in userSelect function call
            if (menuSelect == '1' || menuSelect == '2' || menuSelect == '3') { 
                GroceryItems.userSelect(menuSelect);
                break;
            }
            // if menu selection is 4, thank you message and program is exited
            else if (menuSelect == '4') {
                cout << "Thank you for using our program! \n";
                cout << "Please come back soon!\n";
                runProgram = false;
                exit(0);
            }
            // else, an invalid entry has been made and the user is promted again for input
            else {
                cout << "Invalid selection, please choose again from the menu options (1, 2, 3, 4)\n";
                cin >> menuSelect;
                continue;
            }
        }
    } while (menuSelect != 4);

    return 0;
}