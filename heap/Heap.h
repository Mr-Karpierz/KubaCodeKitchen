#ifndef HEAP_H
#define HEAP_H

template <class T>
class Heap {
    public:
        virtual ~Heap() {};
        virtual void insert(T key) = 0;
        virtual T getMin() = 0;
        virtual void deleteMin() = 0;
        virtual int getSize() = 0;
        virtual bool isEmpty() = 0;
};

#endif 
