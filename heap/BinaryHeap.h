#include "Heap.h"

template <class T>
class BinaryHeap : virtual public Heap<T> {
    public: 
        BinaryHeap<T>();
        ~BinaryHeap<T>();
        void insert(T key);
        T getMin();
        void deleteMin();
        int getSize();
        bool isEmpty();
    private:
        int size;
        int count;
        T* array;
        void swapUp(int index);
        void swapDown(int index);
        void ensureCapacity();
};
