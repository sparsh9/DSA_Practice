// Question : Change a BT such that it stores the sum of all the left nodes


#include<bits/stdc++.h>
 
using namespace std;
 
// A tree node
class node
{
    public:
    int data;
    node* left, *right;
     
    /* Constructor that allocates a new node with the
    given data and NULL left and right pointers. */
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


// function to update tree
void updatetree(node* root){
    if(root == NULL)return;

    // if root is a leaf node then return
    if(root->left == NULL && root->right == NULL)
        return;

    // if root has a left child then update the left child
    if(root->left){
        updatetree(root->left);
        root->data += root->left->data;
    }

    // if root has a right child then update the right child
    if(root->right){
        updatetree(root->right);
    }
}



// Driver code
int main()
{
    /* Let us construct below tree
                1
            / \
            2 3
            / \ \
            4 5 6 */
    struct node *root = new node(1);
    root->left     = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
 
    updatetree(root);
 
    cout << "Inorder traversal of the modified tree is: \n";
    inorder(root);
    return 0;
}