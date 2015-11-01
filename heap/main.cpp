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
    Heap<int>* heap = new BinomialHeap<int>();   
    for (int i = atoi(argv[1]); i > 0; i--) {
        val = rand() % 1000 + 1;
        std::cout << "I: " << val << std::endl; 
        heap->insert(val); 
    }
    for (int i = atoi(argv[1]); i > 0; i--) {
        val = rand() % 1000 + 1;
        if (rand() % 2) {
            std::cout << "R: " <<  heap->getMin() << std::endl;
            heap->deleteMin();
        } else {
            std::cout << "I: " << val << std::endl;
            heap->insert(val);
        }
    }
    delete heap;
    return 0;
}
