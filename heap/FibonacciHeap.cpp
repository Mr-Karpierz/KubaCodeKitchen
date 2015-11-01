#include "BinomialHeap.h"
#include <cstdlib>
#include <iostream>

template <class T>
BinomialHeap<T>::BinomialHeap() {
    count = 0;
    head = NULL;
    min = NULL;
}

template <class T>
void deleteNode(BinomialNode<T>* node) {
    if (node) {
        deleteNode(node->child);
        deleteNode(node->next);
        delete node;
    }
}

template <class T>
BinomialHeap<T>::~BinomialHeap() {
    deleteNode(head);
}

template <class T> 
T BinomialHeap<T>::getMin() {
    return min->value;
}

template <class T>
void BinomialHeap<T>::mergeHeap(BinomialNode<T>*& head, BinomialNode<T>* merge) {
    if (merge) {
        BinomialNode<T>* next;
        if (!min || min->value > merge->value)
            min = merge;
        if (!head) {
            head = merge;
            return;
        }
        if (head->order < merge->order) 
            return mergeHeap(head->next,merge);
        if (head->order == merge->order) {
            next = merge->next;
            BinomialNode<T>* tempHead = head;
            if (head->value < merge->value) {
                head->order += 1;
                if (head->maxChild) 
                    head->maxChild->next = merge;
                else
                    head->child = merge;
                head->maxChild = merge;
                merge->next = NULL;
                head = head->next;
                tempHead->next = NULL;
                mergeHeap(head, tempHead);
            } else {
                merge->order += 1;
                if (merge->maxChild)
                    merge->maxChild->next = head;
                else
                    merge->child = head;
                merge->maxChild = head;
                merge->next = NULL;
                head = head->next;
                tempHead->next = NULL;
                mergeHeap(head,merge);         
            }
            return mergeHeap(head, next);
        }
        next = merge->next;
        merge->next = head;
        head = merge;
        return mergeHeap(head->next,next);
    }    
}

template <class T>
void BinomialHeap<T>::deleteMin() {
    BinomialNode<T>* curr = head;
    if (curr == min)
        head = head->next;
    else {
        while (curr->next != min) 
            curr = curr->next;
        curr->next = min->next;
    }
    BinomialNode<T>* child = min->child;
    if (child)
        mergeHeap(head,child);
    delete min;
    min = head;
    curr = head;
    while (curr) {
        if (curr->value < min->value)
            min = curr;
        curr = curr->next;
    }
    count--;
}

template <class T>
void BinomialHeap<T>::insert(T key) {
    BinomialNode<T>* elem = new BinomialNode<T>;
    *elem = {NULL, NULL, NULL, key, 0};
    if (!min || min->value > key)
        min = elem;
    mergeHeap(head,elem);
    count++;
}

template <class T>
int BinomialHeap<T>::getSize() {
    return count;
}

template <class T>
bool BinomialHeap<T>::isEmpty() {
    return count == 0;
}
