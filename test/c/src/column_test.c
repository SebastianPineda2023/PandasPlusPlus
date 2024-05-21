#include <stdio.h>

#include "common_defs.h"
#include "ppp_column.h"

int TestConstruction(void) {
    float nums[3] = {3.0f, 2.0f, 6.7f};
    const char key[] = "Column";

    FColumnHandle col = NewFColumn(nums, 3, key);

    if (col) {
        DeleteFColumn(col);
        SUCCESS_PRINT("TestConstruction");
        return 1;
    } else {
        FAILURE_PRINT("TestConstruction");
        return 0;
    }
}

int TestPrint(void) {
    float nums[3] = {3.0f, 2.0f, 6.7f};
    const char key[] = "Column";

    FColumnHandle col = NewFColumn(nums, 3, key);
    printf("Visually confirm column is {3.0, 2.0, 6.7}\n");
    PrintFColumn(col);

    DeleteFColumn(col);
    SUCCESS_PRINT("TestPrint");

    return 1;
}

int TestAddition(void) {
    float nums[3] = {3.0f, 2.0f, 6.7f};
    const char key[] = "Column";

    FColumnHandle col = NewFColumn(nums, 3, key);
    FColumnHandle col2 = NewFColumn(nums, 3, key);

    FColumnHandle col3 = AddFColumns(col, col2);

    if (!col3) {
        DeleteFColumn(col);
        DeleteFColumn(col2);
        FAILURE_PRINT("TestAddition");
        return 0;
    } else {
        printf("Visually confirm column is {6.0, 4.0, 13.4}\n");
        PrintFColumn(col3);

        DeleteFColumn(col);
        DeleteFColumn(col2);
        DeleteFColumn(col3);

        SUCCESS_PRINT("TestAddition");
        return 1;
    }
}
