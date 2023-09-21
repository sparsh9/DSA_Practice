// For Collision : +ve ke baad -ve hona chahiye
// sum of 2 is +ve -> right jaayega
// sum of 2 is -ve -> left jaayega 

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        // Otherwise vector ko bhi stack jaisa use kar sakte hai so that addtional vector space baad mein bach jaaye
        for(auto &a : ast){

            // All the below operations run for every element in the vector


            // kab collision tab hoga jab bhara ho and top wala +ve ho
            while(!st.empty() and st.top() > 0 and a < 0){
                int sum = st.top() + a;

                if(sum < 0) // moves to left
                    st.pop();
                
                else if(sum > 0){ // moves to right
                    a=0;
                }
                else{ // sum == 0, both will be destroyed
                    st.pop();
                    a=0;
                }    
            }
            // agar a bach gaya(a != 0) toh push kardo ya fir a=0 hai toh kuch nahi karna
            if(a!=0)
                st.push(a);
        }

        vector<int> ans();
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};