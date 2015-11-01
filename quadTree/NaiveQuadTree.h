#include "QuadTree.h"

class NaiveQuadTree : virtual public QuadTree {
    public:
        NaiveQuadTree();
        NaiveQuadTree(double* x, double* y, int size);
        ~NaiveQuadTree();
        void insert(double x, double y);
        quadTreeNode* head;      
    private:
        void insert(double* x, double* y, int size, quadTreeNode*& parent);
}
