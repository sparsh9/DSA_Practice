// Approach 1 using simple logic that
// goal + goal will have all the possible rotation combinations of a string goal
// and hence if the state is a part of its substring then
// it is a substring or else not.
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if(s.size() != goal.size()) return false;
//         string state = s+s; // state = s + s
//         return state.find(goal) != string::npos;
//     }
// };


// Approach 2 using queue and checking every rotation
class Solution {
public:
    bool rotateString(string s, string goal) {
        queue<char> q1,q2;
        if(s == goal)
            return true;

        if(s.size() != goal.size())
            return false;
        
        for(int i=0;i<s.size();i++)
            q1.push(s[i]);

        for(int i=0;i<goal.size();i++)
            q2.push(goal[i]);

        int r = s.size()-1;
        while(r != 0){
            char temp = q2.front();
            q2.pop();
            q2.push(temp);
            if(q1 == q2)
                return true;  
            r--;          
        }
        return false;

    }
};