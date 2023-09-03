#include <bits/stdc++.h>
using namespace std;

/*
Example Path : /a/./b/../..//c/

1) Here we only want to deal with 'a','.','b','..' and 'c' because these are the only valid characters in the path.
2) We will use stack to store the valid characters.
3) We will push the characters in the stack until we encounter '..' or '.' .
4) We will use concept of tokeniser like '/' will act as a delimiter and we will split the path into tokens.
*/

// class Solution {
// public:
//     string simplifyPath(string path) {
        
//         stringstream ss(path);
//         string token = "";
//         stack<string> st;
        
//         while(getline(ss, token, '/')) {

//             if(token == "" || token == ".") 
//                 continue;
            
//             if (token != "..") 
//                 st.push(token);
//             else if (!st.empty()) 
//                 st.pop();
//         }
        
//         string result = "";
        
//         while(!st.empty()){ // add all the stack elements
//             result="/"+st.top()+result;
//             st.pop();
//         }
        
//         if(result.length()==0) // if no directory or file is present
//             result="/"; // minimum root directory must be present in result
        
//         return result;
//     }
// };

//Approach-2 (Using vector as stack)
class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        
        stringstream ss(path);
        vector<string> st;
        
        while(getline(ss, token, '/')) {

            if(token == "" || token == ".") continue;
            
            if (token != "..") 
                st.push_back(token);
            else if (!st.empty()) 
                st.pop_back();
        }
        
        string result = "";
        
        for(auto &token : st) {
            result += "/" + token;
        }
        
        return result.empty() ? "/" : result;
    }
};




// Complete main function to execute above class functions

int main()
{
    string path = "/home/foo1/../foo/";
    Solution obj;
    cout<<obj.simplifyPath(path);
    return 0;
}