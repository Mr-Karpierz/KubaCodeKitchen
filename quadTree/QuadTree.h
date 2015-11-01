#ifndef QUADTREE_H
#define QUADTREE_H

struct quadTreeNode
{
	quadTreeNode *tl;
	quadTreeNode *tr;
	quadTreeNode *bl;
	quadTreeNode *br;
	bool isLeaf;
	double x;
	double y;
};

class QuadTree {
    public:
        virtual ~QuadTree() {};
        virtual void insert(double x, double y) = 0;
        virtual void constructTree(double* x, double* y, int size) = 0;
        quadTreeNode* head = 0;
}
#endif 
