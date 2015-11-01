#include "NaiveQuadTree.h"

NaiveQuadTree::NaiveQuadTree() {
	head = NULL;
}

NaiveQuadTree::NaiveQuadTree(double* x, double* y, int size); {
    int x_temp[size];
    int y_temp[size];
    for (int i = 0; i < size; i++) {
        x_temp[i] = x[i];
        y_temp[i] = y[i];
    }
    insert(x_temp,y_temp,size,head);	
}

void NaiveQuadTree::insert(double* x, double *y, double bound_x, double bound_y, int size, quadTreeNode*& parent) {
    if (!size) {
        parent = NULL;
        return;
    }
    if (size == 1) {
        
    }
}
 {
    public:
        NaiveQuadTree();
        NaiveQuadTree(double* x, double* y, int size);
        ~NaiveQuadTree();
        void insert(double x, double y);
        quadTreeNode* head;      
}
