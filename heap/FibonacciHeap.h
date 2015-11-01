#include "Heap.h"

template <class T>
struct BinomialNode {
    BinomialNode* next;
    BinomialNode* child;
    BinomialNode* maxChild;
    T value;
    int order;
};

template <class T>
class BinomialHeap : virtual public Heap<T> {
    public: 
        BinomialHeap<T>();
        ~BinomialHeap<T>();
        void insert(T key);
        T getMin();
        void deleteMin();
        int getSize();
        bool isEmpty();
    private:
        int count;
        BinomialNode<T>* head;
        BinomialNode<T>* min;
        void mergeHeap(BinomialNode<T>*& head, BinomialNode<T>* merge);
};
