int changestock(struct shoe *inventory, int index) {
    int stockNo, styleNo;
    int recfound = 0;
    int size;

    displayRecord(inventory, index);
    do {
    printf("\n---------------------------------------------------------------------------------------------------------");
    printf(BWHT"\n\nChange stock on hand\n\n"COLOR_RESET);

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

                if (size >= MIN_SIZE && size <= MAX_SIZE) {
                    int newQuantity;
                    printf("\nEnter new quantity\t:\t");
                    scanf("%d", &newQuantity);

                    inventory[i].quantity = newQuantity;
                    printf(BGRN"\n\t\tStock on hand for size %d updated successfully!\n"COLOR_RESET, size);
                    displayRecord(inventory, i + 1);
                } 
                else {
                    printf(BRED"\nInvalid size number.\n"COLOR_RESET);
                }

            recfound = 1;
            break;
        }
    }

    if (!recfound) {
        printf(BHRED"\n\tRecord not found or input does not match the previous record.\n");
        printf("\t\t\t     Please try again.\n"COLOR_RESET);
    }

    } while(!recfound);

    return 1;
}