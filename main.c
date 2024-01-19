#include "data_structure.c"
#include "data_io.c"
#include <windows.h>

int main() {
    // pStaffList staffList;
    pStaffTree staffTree = NULL;

    SetConsoleTitle("Sale Bonus Calculation System");
    printf("\n"
           " _____      _                       _            _____           _                 \n"
           "|  ___|    | |                     (_)          /  ___|         | |                \n"
           "| |__ _ __ | |_ ___ _ __ _ __  _ __ _ ___  ___  \\ `--. _   _ ___| |_ ___ _ __ ___  \n"
           "|  __| '_ \\| __/ _ \\ '__|  _ \\| '__| / __|/ _ \\  `--. \\ | | / __| __/ _ \\ ' _ ` _ \\ \n"
           "| |__| | | | ||  __/ |  | |_) | |  | \\__ \\  __/ /\\__/ / |_| \\__ \\  \\  __/ | | | | |\n"
           "\\____/_| |_|\\__\\___|_|  | .__/|_|  |_|___/\\___| \\____/ \\__, |___/\\__\\___|_| |_| |_|\n"
           "                        | |                             __/ |                      \n"
           "                        |_|                            |___/                       \n");
    printf("\nWelcome to use Sale Bonus Calculation System for enterprises\n");

    int action;
    do {
        // show menu
        printf("You can perform the following operations:\n");
        printf("0. Exit\n");
        printf("1. System Initialization\n");
        printf("2. Data Modification\n");
        printf("3. Bonus Calculation\n");
        printf("4. Stats Display\n");
        printf("5. Search\n");
        printf("6. Data Output\n");

        // read input
        while (1) {
            printf("Please enter the number of your option\n>");
            if (scanf("%d", &action) == 1) {  // Use the return value of scanf() to check the validation of input
                break;
            } else {
                getchar();  // clear the buffer to avoid that scanf() reads invalid character
                printf("Invalid input, please enter an integer.\n>");
            }

        }

        // process
        switch (action) {
            case 0:
                if (staffTree) {
                    destroyTree(staffTree->root);
                }
                exit(0);
            case 1:
                dataInit(&staffTree);
                printf("The data are initialized successfully.\n");
                break;
            case 2:
                modify(staffTree);
                break;
            case 3:
                doBonusCalculation(staffTree);
                printf("Bonuses are calculated successfully.\n");
                break;
            case 4:
                statsDisplay(staffTree);
                break;
            case 5:
                search(staffTree);
                break;
            case 6:
                dataOutput(staffTree);
                break;
            default:
                printf("Invalid input, please enter the choice between 0-4.\n>");
                break;
        }

    } while (action != 0);
}






