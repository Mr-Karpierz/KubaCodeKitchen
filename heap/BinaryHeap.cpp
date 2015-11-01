#include "BinaryHeap.h"

template <class T>
BinaryHeap<T>::BinaryHeap() {
    size = 5;
    count = 0;
    array = new T[size];   
}

template <class T>
BinaryHeap<T>::~BinaryHeap() {
    delete[] array;
}

template <class T>
void BinaryHeap<T>::ensureCapacity() {
    if (count == size) {
        size *= 2;
        T* temp = new T[size];
        for (int i = 0; i < count; i++)
            temp[i] = array[i];  
        delete[] array;
        array = temp; 
    }
}

template <class T>
void BinaryHeap<T>::swapUp(int index) {
    if (index > 0) {
        int parent = (index-1)/2;
        if (array[index] < array[parent]) {
            T temp = array[index];
            array[index] = array[parent];
            array[parent] = temp;
            return swapUp(parent);
        }
    }
}

template <class T>
void BinaryHeap<T>::insert(T key) {
    ensureCapacity();
    array[count] = key;
    swapUp(count);      
    count++;
}

template <class T> 
T BinaryHeap<T>::getMin() {
    return array[0];
}

template <class T>
void BinaryHeap<T>::swapDown(int index) {
    int minIndex = index;
    if (2*index+1 < count && array[minIndex] > array[2*index+1])
        minIndex = 2*index+1;
    if (2*index+2 < count && array[minIndex] > array[2*index+2])
        minIndex = 2*index+2;
    T temp = array[index];
    array[index] = array[minIndex];
    array[minIndex] = temp;
    if (minIndex != index)
        return swapDown(minIndex);
}

template <class T>
void BinaryHeap<T>::deleteMin() {
    count--;
    array[0] = array[count];
    swapDown(0);    
}

template <class T>
int BinaryHeap<T>::getSize() {
    return count;
}

template <class T>
bool BinaryHeap<T>::isEmpty() {
    return count == 0;
}
