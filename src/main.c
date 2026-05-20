#include "custom_printf.h"

int main(){
    // Create an array of function pointers to the test functions
    void (*menuFunctions[])() = {
        testChar,
        testString,
        testInt,
        testFloat,
        testBinary,
        testMultipleSpecifiers};

    int choice; // Holds menu choice

    // Display menu
    do{
        customPrintf("\n====== Custom Printf Test Menu ======\n");
        customPrintf("1. Test customPrintf w/ char.\n");
        customPrintf("2. Test customPrintf w/ string.\n");
        customPrintf("3. Test customPrintf w/ int.\n");
        customPrintf("4. Test customPrintf w/ float.\n");
        customPrintf("5. Test customPrintf w/ binary.\n");
        customPrintf("6. Test customPrintf w/ multiple specifiers.\n");
        customPrintf("7. Quit.\n");

        customPrintf("Choose from the above options: ");
        scanf("%d", &choice);

        // If menu choice is valid call the function at that index in menuFunctions
        if (choice >= 1 && choice <= 6){
            menuFunctions[choice - 1]();
        }
        else {
            customPrintf("Invalid option.\n");
        }
    } while (choice != 7);

    customPrintf("GoodBye!!!\n");

    return 0;
}