// Here we see, there is some resemblance with the level order traversal
// Initially all the next pointers are set to NULL
// Isme hum har level ke second last node tak operation perform kar rahe hai in which
// the next will be the next node in the queue after the curr node 
// and in the las node of the level, the next will by default be NULL value
// then we move to the next level

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            if(size == 0)
                return root;
            
            while(size>0){
                Node*temp;
                // till second last element of the horizontal level
                if(size>1){
                    temp = q.front();
                    q.pop();
                    // next element ek level ka will be the next element for its previous one
                    Node* nextAdd = q.front();
                    temp->next = nextAdd;
                }
                // last element of level ka next to NULL hi hoga by default
                else{
                    temp = q.front();
                    q.pop();
                }

                // add next level nodes in the queue for level order traversal
                if(temp->left != NULL)
                    q.push(temp->left);
                
                if(temp->right != NULL)
                    q.push(temp->right);
                
                size--;
            }
        }
        return root;
    }
};