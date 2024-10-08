#ifndef CS25_A18_H
#define CS25_A18_H

// Sorts nums numerically from least to greatest
void numSort(int nums[], int SIZE) {
    bool swap = true;
    while (swap) {
        swap = false;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE - 1 - i; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    swap = true;
                }
            }
        }
    }
}


#endif