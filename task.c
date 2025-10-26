#include "task.h"

void reverseArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}
