
#include "levelAncestor2.h"


levelAncestor2::levelAncestor2(Tree T) {
    this->tree = T;
   // this->leaves.resize(this->tree.nodes);
   // this->paths.resize(this->tree.nodes);
    this->p.resize(this->tree.nodes);
    this->index.resize(this->tree.nodes);

}

void levelAncestor2::sortLeaves() {
    this->tree.getHight();

    vector<vector <int> > L(this->tree.nodes);
    for(int i = 0; i < this->tree.nodes; i++) {
        if(this->tree.height[i] == 0) {   //if its a leaf
            int d = this->tree.depth[i];
            L[d].push_back(i);
        }
    }

    for(int i = L.size() - 1; i >= 0; i--) {
        while(!L[i].empty()) {
            this->leaves.push_back(L[i].back());
            L[i].pop_back();

        }
    }
}

void levelAncestor2::createMaxPaths() {
    this->sortLeaves();
    vector<bool> usedNodes(this->tree.nodes, 0);

    for(int i = 0; i < this->leaves.size(); i++) {
        this->paths.resize(this->leaves.size());
        int currNode = this->leaves[i];
        int parent = this->tree.parentFunction[currNode];
        usedNodes[this->leaves[i]] = 1;
        this->paths[i].push_back(currNode);

        this->p[currNode] = i;
        this->index[currNode] = 0;

        while(currNode != parent && usedNodes[parent] != 1) {
            usedNodes[parent] = 1;
            this->paths[i].push_back(parent);
            this->p[parent] = i;
            this->index[parent] = this->index[currNode] + 1;

            currNode = parent;
            parent = this->tree.parentFunction[parent];
        }
    }
    //flipping the paths so they end with the leaf
    for(int i = 0; i < this->paths.size(); i++) {
        for(int j = 0; j < this->paths[i].size() / 2 ; j++) {
            swap(this->paths[i][j], this->paths[i][this->paths.size() - j - 1]);
            swap(this->index[this->paths[i][j]], this->index[this->paths[i][this->paths.size() - j - 1]]);
        }
    }
}

int levelAncestor2::acceptQuery(int node, int depth) {
    this->createMaxPaths();
    int path = this->p[node];
    int ind = this->index[node];
    if(depth <= ind) {
        return this->paths[path][ind - depth];
    }
    else {
        int firstNodeInPath = this->paths[path][0];
        acceptQuery(this->tree.parentFunction[firstNodeInPath], depth - ind - 1);
    }
}