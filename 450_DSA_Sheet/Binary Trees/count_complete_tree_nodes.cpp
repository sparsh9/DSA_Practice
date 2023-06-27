// Here we are calculating the height of both left and right subtrees,
// if they are equal, then it means we total nodes = 2^height - 1
// otherwise if they are not equal, then it means that there is disimilarity 
// which means we have to repeat this step recursively and again go for their further left and right subtrees
// we will repeat this until left subtree height = right subtree height
// this will reduce our time to calculate total nodes, as we know this property (total nodes = 2^height - 1)


// for pow function
// #include <cmath>

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        if(lh == rh) 
            return (1<<lh) - 1;
            // or use
            // return pow(2,lh) - 1; 
        
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
    int findHeightLeft(TreeNode* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->left; 
        }
        return hght; 
    }
    int findHeightRight(TreeNode* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->right; 
        }
        return hght; 
    }
};