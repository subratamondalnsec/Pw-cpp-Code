/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/clone-graph/
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    vector<Node*>resister;
    void dfs(Node* actual,Node*clone){
        for(auto neibr : actual->neighbors){
            if(!resister[neibr->val]) {//create the neighbor for the first time
                Node* newnode=new Node(neibr->val);
                resister[newnode->val]=newnode;
                clone->neighbors.push_back(newnode);
                dfs(neibr,newnode);
            }
            else{
                clone->neighbors.push_back(resister[neibr->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* clone=new Node(node->val);
        resister.resize(105,NULL);//this array contains ref to the created nodes
        resister[clone->val]=clone;
        dfs(node,clone);
        return clone;
    }
};

int main() {
    // Example: Construct a simple graph
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    // Connect nodes to form the graph: 1--2, 2--3, 3--4, 4--1
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Solution solution;
    Node* clonedGraph = solution.cloneGraph(node1);

    // Output verification - e.g., print values and neighbors of cloned graph
    cout << "Cloned Node Value: " << clonedGraph->val << endl;
    cout << "Neighbors of Cloned Node 1: ";
    for (auto neighbor : clonedGraph->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    // Clean up memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
