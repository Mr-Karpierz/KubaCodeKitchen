#include <stdlib.h>
#include <time.h>

int getCircle(double* x, double* y, int size) {
    int x1, x2, y1, y2;
    x1 = medianSelect(x, size/3);
    x2 = medianSelect(x, (2*size)/3);
    y1 = medianSelect(y, size/3);
    y2 = medianSelect(y, (2*size)/3);
    size1 =     
}

int medianSelect(double* array, int size) {
    return medianSelectHelper(array, 0, size, size/2);      
}

int medianSelectHelper(double* array, int low, int high, int target) {
int randPivot = rand() % (high - low) + low;
    swap(low,randPivot);
    randPivot = low;
    int max = high;
    while (randPivot < max) {
        if (array[randPivot] > array[randPivot+1]) {
            swap(randPivot, randPivot+1);
            randPivot++;
        } else {
            max--;
            swap(randPivot+1,max);
        }
    }
    if (randPivot == target) {
        return randPivot;
    } else if (randPivot > target) {
        return medianSelectHelper(array, low, randPivot, target);
    } else {
        return medianSelectHelper(array, randPivot+1, high, target);
    }
}

void swap(double* array, int a, int b) {
    double temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}
