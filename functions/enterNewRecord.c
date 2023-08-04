int enterNewRecord(struct shoe *inventory, int count) {
    if (count == MAX_STOCK) {
        printf(BRED"\nInventory is full. Cannot add new stock.\n"COLOR_RESET);
        return count;
    }

    printf("\n---------------------------------------------------------------------------------------------------------");
    printf(BWHT"\n\nAdd New Stock\n\n"COLOR_RESET);

    printf("Stock number\t:\t");
    scanf("%d", &(inventory + count)->stockNo);

    printf("Style number (0-50 only)\t:\t");
    scanf("%d", &(inventory + count)->styleNo);

    while((inventory + count)->styleNo < MIN_STYLE || (inventory + count)->styleNo > MAX_STYLE) {
        printf("\n\tInvalid style number.\n\nEnter style number (0 - 50 only)\t:\t");
        scanf("%d", &(inventory + count)->styleNo);
    }

    printf("Size (3-14 only)\t:\t");
    scanf("%f", &(inventory + count)->size);

    while((inventory + count)->size < MIN_SIZE || (inventory + count)->size > MAX_SIZE) {
        printf("\n\tInvalid size number.\n\nEnter size (3-14 only)\t:\t");
        scanf("%f", &(inventory + count)->size);
    }

    printf("No. of Pairs in size %.1f\t:\t", (inventory + count)->size);
    scanf("%d", &(inventory + count)->quantity);

    printf("Price\t:\t");
    scanf("%f", &(inventory + count)->price);

    printf(HGRN"\n\tRecord added successfully.\n"COLOR_RESET);

    displayRecord(inventory, count + 1);

    return count + 1;
}