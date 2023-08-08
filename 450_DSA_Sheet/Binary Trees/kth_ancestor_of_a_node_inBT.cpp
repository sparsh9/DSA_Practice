// Approach 1 (Using Recursion)

Node* solve(Node* root, int &k, int node) {
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == node) 
    {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);


    //wapas aate waqt k-- karenge

    // if leftAns is not null, then we have found the node
    // also agar dono side node hua toh left side ko pehle priority denge
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock karenge agar kth ancestor mil gaya hai and k uske baad bhi 0 se kam hai
            k = INT_MAX; // isko max value de denge taki koi aur node na mil paye
            return root;
        }
        return leftAns; // return the node so that iske pehle wale backtracking nodes mein patah rahe ki 
                        // kahan se aaya hai and node mila hai ki nahi
    }
    
    // agar right side se node mila toh usko same left jaisa karenge
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    // agar dono side se node nahi mila toh NULL return karenge
    return NULL;
    

}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}