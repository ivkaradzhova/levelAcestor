
#ifndef LEVELANCESTOR_TREE_H
#define LEVELANCESTOR_TREE_H

#include <iostream>
#include <vector>
using namespace std;


class Tree {
    vector<int> parentFunction;
    int root;
    int nodes;
    vector<int> depth;
    vector<int> height;

    friend class levelAncestor2;
public:
    Tree();
    Tree(int root, int noods);
    Tree& operator= (Tree other);

    void addChild(int parent, int child); // O(1)
    void getHight(); // O(n)
    void printTree();

    void levelAncestor1(vector<vector<int> >& queryTable);

};


#endif //LEVELANCESTOR_TREE_H
