#ifndef QUADTREE_H
#define QUADTREE_H

struct quadTreeNode
{
	quadTreeNode** children;
	bool isLeaf;
	long long x;
	long long y;
    int depth;
    long long x_square;
    long long y_square;
};

class QuadTree {
    public:
        virtual ~QuadTree() {};
        virtual void insert(long long x, long long y) = 0;
        virtual void constructTree(long long* x, long long* y, int size) = 0;
        quadTreeNode* head = 0;
}
#endif 
