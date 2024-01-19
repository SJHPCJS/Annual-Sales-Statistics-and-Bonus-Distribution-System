#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data_structure.c"
#include "rbtree_impl.c"

#define MAXSIZE 100

// Declarations
void dataInit(pStaffTree* staffTree);

pStaff readStaff();

void modifyStaff(pStaff staff);

void dataOutput(pStaffTree staffTree);

double calcBonus(double sale);

void doBonusCalculation(pStaffTree staffTree);

void statsDisplay(pStaffTree staffTree);

pStaff searchStaff(pStaffTree staffTree, char *id);

void search(pStaffTree staffTree);

void modify(pStaffTree staffTree);

// Implementations
void dataInit(pStaffTree* staffTree) {
    *staffTree = (pStaffTree)malloc(sizeof(StaffTree));
    (*staffTree)->root = NULL;

    printf("Please enter the number of staff\n>");
    while (1) {
        if (scanf("%d", &((*staffTree)->size)) == 1 && ((*staffTree)->size)<=MAXSIZE) {  // Use the return value of scanf() to check the validation of input
            break;
        } else {
            getchar();  // clear the buffer to avoid that scanf() reads invalid character
            printf("Invalid input, please enter an integer within the maxsize.\n>");
        }
    }

    for (int i=0; i<(*staffTree)->size; i++) {
        printf("----- Staff%d Initialization -----\n",i+1);
        rbTreeInsert(*staffTree, readStaff());
    }

}
pStaff readStaff() {
    // memory allocation
    pStaff newStaff = (pStaff)malloc(sizeof(Staff));
    if (newStaff == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // read staff ID
    printf("Enter staff ID (4 digits [1000~9999])\n>");
    while (1) {
        if (scanf("%s", newStaff->id) == 1) {
            int idValue = (int)strtol(newStaff->id,NULL,10);
            if (idValue >= 1000 && idValue <= 9999) {
                break;
            }
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer
        printf("Invalid input. Please enter a valid 4-digit integer for staff ID.\n");
        printf("Enter staff ID (4 digits [1000~9999])\n>");
    }

    // read staff name
    printf("Enter staff name (up to 15 characters)\n>");
    while (scanf("%s", newStaff->name) != 1 || strlen(newStaff->name)>15) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
        printf("Invalid input. Please enter a valid staff name.\n");
        printf("Enter staff name\n>");
    }

    // read sales for each quarter
    printf("Enter sales for each quarter(10k):\n");
    printf("Quarter 1 >");
    while (scanf("%lf", &(newStaff->saleOf1stQuarter)) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
        printf("Invalid input. Please enter a valid floating-point number.\n");
        printf("Quarter 1 >");
    }
    printf("Quarter 2 >");
    while (scanf("%lf", &(newStaff->saleOf2ndQuarter)) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
        printf("Invalid input. Please enter a valid floating-point number.\n");
        printf("Quarter 2 >");
    }
    printf("Quarter 3 >");
    while (scanf("%lf", &(newStaff->saleOf3thQuarter)) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
        printf("Invalid input. Please enter a valid floating-point number.\n");
        printf("Quarter 3 >");
    }
    printf("Quarter 4 >");
    while (scanf("%lf", &(newStaff->saleOf4thQuarter)) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
        printf("Invalid input. Please enter a valid floating-point number.\n");
        printf("Quarter 4 >");
    }

    // Get the sum of sales
    newStaff->sumOfSales =
            newStaff->saleOf1stQuarter
            +newStaff->saleOf2ndQuarter
            +newStaff->saleOf3thQuarter
            +newStaff->saleOf4thQuarter;

    return newStaff;
}
void modifyStaff(pStaff staff) {
    int option;
    do {
        printf("You can modify the following information:\n");
        printf("0. Back to main menu\n");
        printf("1. Name\n");
        printf("2. Sale of the first quarter\n");
        printf("3. Sale of the second quarter\n");
        printf("4. Sale of the third quarter\n");
        printf("5. Sale of the forth quarter\n");
        while (1) {
            printf("Please enter the number of your option\n>");
            if (scanf("%d", &option) == 1) {  // Use the return value of scanf to check the validation of input
                break;
            } else {
                getchar();  // clear the buffer to avoid that scanf reads invalid character
                printf("Invalid input, please enter an integer.\n>");
            }

        }
        switch (option) {
            case 0:
                return;
            case 1:
                // read staff name
                printf("Enter new staff name (up to 15 characters)\n>");
                while (scanf("%s", staff->name) != 1 || strlen(staff->name)>15) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
                    printf("Invalid input. Please enter a valid staff name.\n");
                    printf("Enter staff name\n>");
                }
                break;
            case 2:
                printf("New sale for Quarter 1\n>");
                while (scanf("%lf", &(staff->saleOf1stQuarter)) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
                    printf("Invalid input. Please enter a valid floating-point number.\n");
                    printf("Quarter 1 >");
                }
                break;
            case 3:
                printf("New sale for Quarter 2\n>");
                while (scanf("%lf", &(staff->saleOf2ndQuarter)) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
                    printf("Invalid input. Please enter a valid floating-point number.\n");
                    printf("Quarter 2 >");
                }
                break;
            case 4:
                printf("New sale for Quarter 3\n>");
                while (scanf("%lf", &(staff->saleOf3thQuarter)) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
                    printf("Invalid input. Please enter a valid floating-point number.\n");
                    printf("Quarter 3 >");
                }
                break;
            case 5:
                printf("New sale for Quarter 4\n>");
                while (scanf("%lf", &(staff->saleOf4thQuarter)) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);  // Clear the input buffer
                    printf("Invalid input. Please enter a valid floating-point number.\n");
                    printf("Quarter 4 >");
                }
                break;
            default:
                printf("Invalid input, please enter the choice between 0-5.\n");
                break;
        }

    } while (option != 0);
}
void writeStaffIntoFile_sub(pStaffNode startFrom, FILE *fp) {
    if (startFrom) {
        pStaff staff = startFrom->Staff;
        writeStaffIntoFile_sub(startFrom->leftChild,fp);
        fprintf(fp, "%s\t%s\t\t%4.2lf\t%4.2lf\t%4.2lf\t%4.2lf\t%4.2lf\t%4.2lf\n",staff->id,staff->name,staff->saleOf1stQuarter,staff->saleOf2ndQuarter,staff->saleOf3thQuarter,staff->saleOf4thQuarter,staff->sumOfSales,staff->bonus);
        writeStaffIntoFile_sub(startFrom->rightChild,fp);
    }
}
void writeStaffIntoFile(pStaffTree staffTree, char *file) {
    FILE *fp = fopen(file,"w+");
    if (fp==NULL) {
        printf("File was opened unsuccessfully, please check if you have input a right path.\n");
        return;
    }
    fprintf(fp,"id\tname\t\tsaleQ1\tsaleQ2\tsaleQ3\tsaleQ4\tsaleSum\tbonus\n");
    writeStaffIntoFile_sub(staffTree->root,fp);
    printf("All the data are saved successfully.\n");
    fclose(fp);
}
void dataOutput(pStaffTree staffTree) {
    if (!staffTree) {
        printf("Please initialize the system first.\n");
        return;
    }

    // Check if bonus has been calculated
    if (staffTree->root->Staff->sumOfSales == 0) {
        printf("Invalid Operation. Please choose option 3 to calculate bonus first.\n");
        return;
    }

    char path[256];
    printf("Please give the path you want to write data into\n>");
    scanf("%14s",path);
    writeStaffIntoFile(staffTree,path);
}
double calcBonus(double sale) {
    double bonus;
    if(sale > 300) {
        bonus = sale*0.15;
    } else if (sale > 250) {
        bonus = sale*0.14;
    } else if (sale > 200) {
        bonus = sale*0.13;
    } else if (sale > 150) {
        bonus = sale*0.12;
    } else if (sale > 100) {
        bonus = sale*0.11;
    } else if (sale > 0) {
        bonus = sale*0.1;
    } else {
        bonus = -1;
    }
    return bonus;
}
void bonusCalculation(pStaffNode startFrom, pStaff annualSaleStars[], int *annualSaleStarsNum, double* maxSale) {
    if (startFrom) {
        double sale = startFrom->Staff->sumOfSales;
        startFrom->Staff->bonus = calcBonus(sale);
        if (sale > (*maxSale)) {
            *maxSale = sale;
            annualSaleStars[0] = startFrom->Staff;
            *annualSaleStarsNum = 1;
        } else if (sale == (*maxSale)) {
            annualSaleStars[(*annualSaleStarsNum)++] = startFrom->Staff;
        }
        bonusCalculation(startFrom->leftChild, annualSaleStars, annualSaleStarsNum, maxSale);
        bonusCalculation(startFrom->rightChild, annualSaleStars, annualSaleStarsNum, maxSale);
    }
}
void doBonusCalculation(pStaffTree staffTree) {
    if (!staffTree) {
        printf("Please initialize the system first.\n");
        return;
    }

    pStaff annualSaleStars[staffTree->size];
    int annualSaleStarsNum = 0;
    double maxSale = 0;

    // Calculate bonus recursively and record annual sale stars
    bonusCalculation(staffTree->root,annualSaleStars,&annualSaleStarsNum,&maxSale);

    // Give one more 10k bonus to annual sale stars
    for (int i=0; i<annualSaleStarsNum; i++) {
        annualSaleStars[i]->bonus += 1;
    }
}
void statsCalculation(pStaffNode startFrom, double *enterpriseAnnualSale, pStaff annualStars[], int *annualStarCount, pStaff firstQuarterStars[], pStaff secondQuarterStars[], pStaff thirdQuarterStars[], pStaff forthQuarterStars[], int quarterStarCount[]) {
    if (startFrom) {
        pStaff staff = startFrom->Staff;
        *enterpriseAnnualSale += staff->sumOfSales;

        // For Annual Star
        if (staff->sumOfSales > annualStars[0]->sumOfSales) {
            annualStars[0] = staff;
            *annualStarCount = 1;
        } else if (staff->sumOfSales == annualStars[0]->sumOfSales) {
            annualStars[(*annualStarCount)++] = staff;
        }

        // For Quarter Star
        if (staff->saleOf1stQuarter > firstQuarterStars[0]->saleOf1stQuarter) {
            firstQuarterStars[0] = staff;
            quarterStarCount[0] = 1;
        } else if (staff->saleOf1stQuarter == firstQuarterStars[0]->saleOf1stQuarter) {
            firstQuarterStars[quarterStarCount[0]++] = staff;
        }
        if (staff->saleOf2ndQuarter > secondQuarterStars[0]->saleOf2ndQuarter) {
            secondQuarterStars[0] = staff;
            quarterStarCount[1] = 1;
        } else if (staff->saleOf2ndQuarter == secondQuarterStars[0]->saleOf2ndQuarter) {
            secondQuarterStars[quarterStarCount[1]++] = staff;
        }
        if (staff->saleOf3thQuarter > thirdQuarterStars[0]->saleOf3thQuarter) {
            thirdQuarterStars[0] = staff;
            quarterStarCount[2] = 1;
        } else if (staff->saleOf3thQuarter == thirdQuarterStars[0]->saleOf3thQuarter) {
            thirdQuarterStars[quarterStarCount[2]++] = staff;
        }
        if (staff->saleOf4thQuarter > forthQuarterStars[0]->saleOf4thQuarter) {
            forthQuarterStars[0] = staff;
            quarterStarCount[3] = 1;
        } else if (staff->saleOf4thQuarter == forthQuarterStars[0]->saleOf4thQuarter) {
            forthQuarterStars[quarterStarCount[3]++] = staff;
        }

        statsCalculation(startFrom->leftChild,enterpriseAnnualSale,annualStars,annualStarCount,firstQuarterStars,secondQuarterStars,thirdQuarterStars,forthQuarterStars,quarterStarCount);
        statsCalculation(startFrom->rightChild,enterpriseAnnualSale,annualStars,annualStarCount,firstQuarterStars,secondQuarterStars,thirdQuarterStars,forthQuarterStars,quarterStarCount);
    }
}
void statsDisplay(pStaffTree staffTree) {
    if (!staffTree) {
        printf("Please initialize the system first.\n");
        return;
    }

    // Check if bonus has been calculated
    if (staffTree->root->Staff->sumOfSales == 0) {
        printf("Invalid Operation. Please choose option 3 to calculate bonus first.\n");
        return;
    }

    pStaff root = staffTree->root->Staff;
    int numOfStaff = staffTree->size;

    double enterpriseAnnualSale;
    pStaff AnnualStars[numOfStaff];  // Array to store indices of employees with the highest annual sales
    int AnnualStarCount = 0;    // Count of employees with the highest annual sales
    pStaff firstQuarterStars[numOfStaff], secondQuarterStars[numOfStaff], thirdQuarterStars[numOfStaff], forthQuarterStars[numOfStaff];  // Array to store indices of employees with the highest sales in each quarter
    int QuarterStarCount[4] = {0, 0, 0,0};  // Array to store counts of employees with the highest sales in each quarter

    // Initialize arrays
    AnnualStars[0] = root;
    firstQuarterStars[0] = root;
    secondQuarterStars[0] = root;
    thirdQuarterStars[0] = root;
    forthQuarterStars[0] = root;

    statsCalculation(staffTree->root, &enterpriseAnnualSale, AnnualStars, &AnnualStarCount, firstQuarterStars,
                     secondQuarterStars, thirdQuarterStars, forthQuarterStars, QuarterStarCount);

    // Display enterprise sale
    printf("\nTotal Annual Sales(10k): %.2f\n", enterpriseAnnualSale);

    // Sales Star (Highest Annual Sales)
    printf("\nAnnual Sales Star (Highest Annual Sales):\n");
    for (int i = 0; i < AnnualStarCount; i++) {
        printf("ID: %s, Name: %s, Sales(10k): %.2f\n",
               AnnualStars[i]->id,
               AnnualStars[i]->name,
               AnnualStars[i]->sumOfSales);
    }

    // Quarter Stars (Highest Sales in Each Quarter)
    printf("\nQuarter Stars (Highest Sales in Each Quarter):\n");
    printf("Quarter\t ID\tName\n");
    for (int i=0; i<QuarterStarCount[0]; i++) {
        printf("   %d   \t %s\t%s\n",1,firstQuarterStars[i]->id,firstQuarterStars[i]->name);
    }
    for (int i=0; i<QuarterStarCount[1]; i++) {
        printf("   %d   \t %s\t%s\n",1,secondQuarterStars[i]->id,secondQuarterStars[i]->name);
    }
    for (int i=0; i<QuarterStarCount[2]; i++) {
        printf("   %d   \t %s\t%s\n",1,thirdQuarterStars[i]->id,thirdQuarterStars[i]->name);
    }
    for (int i=0; i<QuarterStarCount[3]; i++) {
        printf("   %d   \t %s\t%s\n",1,forthQuarterStars[i]->id,forthQuarterStars[i]->name);
    }
}
pStaff searchStaff(pStaffTree tree, char* id) {
    pStaffNode current = tree->root;

    while(current != NULL) {
        int cmp = strcmp(current->Staff->id, id);

        if(cmp == 0) {
            return current->Staff;
        }
        else if(cmp > 0) {
            current = current->leftChild;
        }
        else {
            current = current->rightChild;
        }
    }

    return NULL;
}
void search(pStaffTree staffTree) {
    if (!staffTree) {
        printf("Please initialize the system first.\n");
        return;
    }
    char id[4];
    printf("Enter staff ID you want to search for (4 digits [1000~9999])\n>");
    while (1) {
        if (scanf("%s", id) == 1) {
            int idValue = (int)strtol(id,NULL,10);
            if (idValue >= 1000 && idValue <= 9999) {
                break;
            }
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer
        printf("Invalid input. Please enter a valid 4-digit integer for staff ID.\n");
        printf("Enter staff ID (4 digits [1000~9999])\n>");
    }

    pStaff result = searchStaff(staffTree,id);
    if (result) {
        printf("Staff %s was found\n",id);
        printf("ID: %s, Name: %s, Sales(10k): %.2f\n",
               result->id,
               result->name,
               result->sumOfSales);
    } else {
        printf("Staff %s was not found\n",id);
    }
}
void modify(pStaffTree staffTree) {
    if (!staffTree) {
        printf("Please initialize the system first.\n");
        return;
    }
    char id[4];
    printf("Enter staff ID you want to modify (4 digits [1000~9999])\n>");
    while (1) {
        if (scanf("%s", id) == 1) {
            int idValue = (int)strtol(id,NULL,10);
            if (idValue >= 1000 && idValue <= 9999) {
                break;
            }
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer
        printf("Invalid input. Please enter a valid 4-digit integer for staff ID.\n");
        printf("Enter staff ID (4 digits [1000~9999])\n>");
    }

    pStaff toBeModified = searchStaff(staffTree,id);
    if (toBeModified) {
        modifyStaff(toBeModified);
    } else {
        printf("Staff %s was not found\n",id);
    }
}
