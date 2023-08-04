#include <stdio.h>
#include <malloc.h>
#include <conio.h>

#define MAX_STOCK 100
#define MAX_SIZE 14
#define MIN_SIZE 3
#define MAX_STYLE 50
#define MIN_STYLE 1

struct shoe {
    int stockNo;
    int styleNo;
    float size;
    int quantity;
    float price;
};

void menu();
void displayRecord(struct shoe *inventory, int count);
int changestock(struct shoe *inventory, int count);
int changeprice(struct shoe *inventory, int count);
int enterNewRecord(struct shoe *inventory, int count);

#include <D:\New folder\2nd Semester\COMP 003 - Computer Programming 2\Activities\8_StructuresPt2\ANSI-color-codes.h>
#include <D:\New folder\2nd Semester\COMP 003 - Computer Programming 2\Activities\8_StructuresPt2\functions\displayrecord.c>
#include <D:\New folder\2nd Semester\COMP 003 - Computer Programming 2\Activities\8_StructuresPt2\functions\changestock.c>
#include <D:\New folder\2nd Semester\COMP 003 - Computer Programming 2\Activities\8_StructuresPt2\functions\changeprice.c>
#include <D:\New folder\2nd Semester\COMP 003 - Computer Programming 2\Activities\8_StructuresPt2\functions\menu.c>
#include <D:\New folder\2nd Semester\COMP 003 - Computer Programming 2\Activities\8_StructuresPt2\functions\enterNewRecord.c>

int main (int argc, char *argv[]) {

    struct shoe *inventory = (struct shoe *)malloc(MAX_STOCK * sizeof(struct shoe));
    
    int count = 0;
    int choice;
    int exitConfirmation = 0;

    while (choice != 5 || exitConfirmation == 0) {
        printf("\n=========================================================================================================\n");
        printf(BWHT"\t\t\t\t     Shoe Inventory Management\n"COLOR_RESET);
        printf("=========================================================================================================\n\n");
        
        menu();

        do {
            printf(UWHT"Please select:"COLOR_RESET" ");
            scanf(" %d", &choice);

            if(choice >= 1 && choice <= 5) {
                switch (choice)
                {
                case 1:
                    count = enterNewRecord(inventory, count);
                    break;
                case 2:
                    displayRecord(inventory, count);
                    break;
                case 3:
                    changeprice(inventory, count);
                    break;
                case 4:
                    changestock(inventory, count);
                    break;
                case 5:
                    printf(BHRED"\n\tAre you sure you want to exit?"COLOR_RESET);
                    printf("\t[1] Yes\t[0] No\t:\t");
                    scanf("%d", &exitConfirmation);
                    printf("\n");
                    if (exitConfirmation == 1) {
                        printf(WHTHB"\t\t\t\t Exiting the program... "COLOR_RESET"\n\n");
                        break;
                    }
                    printf(WHTHB"\t\t\t\t Returning to menu... "COLOR_RESET"\n\n");
                    continue;
                }
            }
            else {
                printf("\t\tInvalid input. Please enter again.\n");
            }
        } while(!(choice >= 1 && choice <= 5));

        getch();
    }

    free(inventory); // free dynamically allocated memory
    return 0;
}