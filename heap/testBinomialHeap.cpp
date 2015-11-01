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
    srand(time(NULL));
    int val;
    Heap<int>* binaryHeap = new BinaryHeap<int>();
    Heap<int>* binomialHeap = new BinomialHeap<int>(); 
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++) {
        if (!(binomialHeap->isEmpty()) && rand() % 2) {   
            std::cout << "d " << std::endl;     
            binaryHeap->deleteMin();
            binomialHeap->deleteMin();
        } else {
            val = rand() % 100000 + 1;
            std::cout << val << " " << std::endl;
            binaryHeap->insert(val);
            binomialHeap->insert(val);
        }
        if ((binaryHeap->isEmpty() != binomialHeap->isEmpty()) || (!binaryHeap->isEmpty() && (binaryHeap->getMin() != binomialHeap->getMin()))) {
            std::cout << "ERROR!" << std::endl;
            break;
        }
    }  
    delete binomialHeap;
    delete binaryHeap;
    return 0;
}
