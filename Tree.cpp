
#include "Tree.h"

Tree& Tree::operator= (Tree other) {
    if(this != &other) {
        this->root = other.root;
        this->nodes = other.nodes;
        this->parentFunction.resize(this->nodes);
        this->depth.resize(this->nodes);
        this->height.resize(this->nodes);

        for(int i = 0; i < this->nodes; i++) {
            this->parentFunction[i] = other.parentFunction[i];
            this->depth[i] = other.depth[i];
            this->height[i] = other.height[i];
        }
    }
    return *this;
}

Tree::Tree() {
    parentFunction.resize(1);
    root = 0;
    nodes = 1;
}

Tree::Tree(int root, int nodes) {
    this->parentFunction.resize(nodes);
    this->depth.resize(nodes, 0);
    this->height.resize(nodes, -1);

    this->parentFunction[root] = root;
    this->depth[root] = 0;
    this->nodes = nodes;
    this->root = root;
}

void Tree::addChild(int parent, int child) {
    parentFunction[child] = parent;
    depth[child] = depth[parent] + 1;
}

void Tree::printTree() {
    for(int i = 0; i < nodes; i++)
    {
        cout << "Node: " << i << ", depth " << this->depth[i] << ", height: " <<
        this->height[i] << ", parent: " << this->parentFunction[i] << endl;
    }
}

//this algorithm is done
void Tree::levelAncestor1(vector<vector<int> >& queryTable) {
    queryTable.resize(this->nodes);
     for(int i = 0; i < this->nodes; i++) {
         queryTable[i].resize(this->nodes, -1);
         queryTable[i][0] = i;
     }
     for(int i = 0; i < this->nodes; i++) {
         for(int j = 1; j < this->nodes; j++) {
             if(j <= depth[i])
                queryTable[i][j] = parentFunction[queryTable[i][j - 1]];
             else
                 queryTable[i][j] = -1;
         }
     }
}

void Tree::getHight() {
    vector<bool> areParents(this->nodes);
    vector<int> leaves;

    for(int i = 0; i < this->nodes; i++){
        areParents[this->parentFunction[i]] = 1;
    }
    for(int i = 0; i < this->nodes; i++) {
        if(!areParents[i])
            leaves.push_back(i);
    }
    this->height.resize(nodes, -1);
    for(int i = 0; i < leaves.size(); i++) {
        this->height[leaves[i]] = 0;
        int currNode = leaves[i];
        int parent = parentFunction[currNode];
        while(currNode != this->root && (this->height[parent] == -1 || this->height[currNode] + 1 > this->height[parent])) {
            this->height[parent] = this->height[currNode] + 1;
            currNode = parentFunction[currNode];
            parent = parentFunction[currNode];
        }
    }
}