#include "BinaryHeap.cpp"
#include "BinomialHeap.cpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./test #numElements" << std::endl;
        return 1;
    }
    clock_t t1,t2;
    srand(time(NULL));
    int val;
    Heap<int>* binaryHeap = new BinaryHeap<int>();
    Heap<int>* binomialHeap = new BinomialHeap<int>(); 
    int n = atoi(argv[1]);
    std::cout << "Insertion Test: n = " << n << std::endl;
    t1 = clock();
    for (int i = 0; i < n; i++) {
        val = n-i+1;
        binomialHeap->insert(val);
    }  
    t2 = clock();
    std::cout << "Binomial Heap Insertion: " << ((float)t2 - (float)t1)/CLOCKS_PER_SEC << std::endl;
    t1 = clock();
    for (int i = 0; i < n; i++) {
        val = n-i+1;
        binaryHeap->insert(val);
    }  
    t2 = clock();
    std::cout << "Binary Heap Insertion: " << ((float)t2 - (float)t1)/CLOCKS_PER_SEC << std::endl;
    t1 = clock();
    for (int i = 0; i < n; i++) {
        binomialHeap->deleteMin();
    }  
    t2 = clock();
    std::cout << "Binomial Heap Delete: " << ((float)t2 - (float)t1)/CLOCKS_PER_SEC << std::endl;
    t1 = clock();
    for (int i = 0; i < n; i++) {
        binaryHeap->deleteMin();
    }  
    t2 = clock();
    std::cout << "Binary Heap Delete: " << ((float)t2 - (float)t1)/CLOCKS_PER_SEC << std::endl;
    delete binomialHeap;
    delete binaryHeap;
    return 0;
}
