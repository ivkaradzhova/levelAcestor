

#ifndef LEVELANCESTOR_LEVELANCESTOR2_H
#define LEVELANCESTOR_LEVELANCESTOR2_H

#include "Tree.h"

class levelAncestor2 {
private:
    Tree tree;
    vector<int> leaves;
    vector<vector<int> > paths;
    vector<int> p;
    vector<int> index;

public:
    levelAncestor2(Tree T);
    void sortLeaves();
    void createMaxPaths();
    int acceptQuery(int node, int depth);

};


#endif //LEVELANCESTOR_LEVELANCESTOR2_H
