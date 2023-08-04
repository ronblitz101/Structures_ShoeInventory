void displayRecord(struct shoe *inventory, int count) {
    if (count == 0) {
        printf(BHRED"\n\tNo records found.\n\n"COLOR_RESET);
        return;
    }
    printf("\n---------------------------------------------------------------------------------------------------------");
    printf(BWHT"\n|\tStock No.\t|\tStyle No.\t|\tSize\t|\tQuantity\t|\tPrice\t|"COLOR_RESET);
    printf("\n---------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < count; i++) {
        printf("\n\t   %d\t\t\t   %d\t\t\t%.1f\t\t  %d\t\t     %.2f", inventory[i].stockNo, inventory[i].styleNo, inventory[i].size, inventory[i].quantity, inventory[i].price);
    }
    printf("\n---------------------------------------------------------------------------------------------------------\n");
}