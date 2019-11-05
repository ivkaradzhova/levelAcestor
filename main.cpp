#include <iostream>
#include <vector>
#include <queue>
#include "Tree.h"
#include "levelAncestor2.h"
using namespace std;


int main() {
    //cout << "Test for first algorithm: " << endl;
    //testLA1(9, 3);
    Tree v(0, 10);
    v.addChild(0, 1);
    v.addChild(0, 2);
    v.addChild(1, 3);
    v.addChild(1, 4);
    v.addChild(2, 5);
    v.addChild(4, 6);
    v.addChild(4, 7);
    v.addChild(4, 8);
    v.addChild(7, 9);
    //vector<vector<int> > queryTable;
    //v.levelAncestor1(queryTable);
    //cout << queryTable[9][5] << endl;
   // v.printTree();
   // v.getHight();
   // v.printTree();
    levelAncestor2 treeForAlgo2(v);
    int answer = treeForAlgo2.acceptQuery(6, 2);
    cout << answer << endl;
    return 0;
}