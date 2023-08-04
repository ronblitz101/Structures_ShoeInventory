int changeprice(struct shoe *inventory, int index) {
    float newPrice;

    int stockNo, styleNo, size;
    int recfound = 0;

    displayRecord(inventory, index);

    do {
    printf("\n---------------------------------------------------------------------------------------------------------");
    printf(BWHT"\n\nInput new shoe price\n\n"COLOR_RESET);

    printf("Stock No\t:\t");
    scanf("%d", &stockNo);

    printf("Style No (0-50 only)\t:\t");
    scanf("%d", &styleNo);

    printf("Size (3-14 only)\t:\t");
    scanf("%d", &size);

    int i;
    for (i = 0; i <= index; i++) {
        if (inventory[i].stockNo == stockNo && inventory[i].styleNo == styleNo && inventory[i].size == size) {
            printf(HGRN"\nRecord found:\n"COLOR_RESET);
            displayRecord(inventory, i + 1);

            printf("\nEnter the new price: ");
            scanf("%f", &newPrice);

            inventory[i].price = newPrice;
            printf(BGRN"\n\t\tPrice updated successfully!\n"COLOR_RESET);
            displayRecord(inventory, i + 1);

            recfound = 1;
            break;
        }
    }

    if(!recfound) {
        printf(BHRED"\n\tRecord not found or input does not match the previous record.\n");
        printf("\t\t\t     Please try again.\n"COLOR_RESET);
    }

    } while(!recfound);

    return 1;
}