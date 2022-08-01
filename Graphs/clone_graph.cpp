// Definition for a Node.
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
    void dfs(Node*node,Node*clone,vector<Node*>& vis){
        vis[clone->val] = clone;     // updating the visited array
        for(auto x:node->neighbors){
            if(vis[x->val] != NULL){
                Node* newNode = new Node(x->val);
                (clone->neighbors).push_back(newNode);
                dfs(x,newNode,vis);
            }
            else
                (clone->neighbors).push_back(vis[x->val]);
        }
    }
    
    
    Node* cloneGraph(Node* node) {
        if(node == NULL)   // Checking if the node is NULL and if it is then we will return NULL.
            return NULL;
        Node* clone = new Node(node->val); // Here we are mentioning that clone is a Node type and its value resembles with the value of the node.
        vector<Node*> vis(1000,NULL);    // Initializing the vector to store the visited nodes and initializing it to NULL initially.
        dfs(node,clone,vis);  // traversing the node using the dfs traversal
        return clone;
    }
};


// Basic Algorithm 

// Basically here we were given a reference to the node 
// and we are creating a new node and then we are traversing the node 
// and creating a new node for each node and then we are updating the visited array 
// and then we are doing the same thing for each node 
// and then we are returning the clone node.