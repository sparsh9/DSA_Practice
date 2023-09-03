/*
Input :
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>s1, s2;
    // we are stack s1 to store the elements and s2 to store the minimum element
    
    void push(int x) {
        // agar s1 khali hai toh s2 mein bhi push kardo
        if(s1.empty()){
            s2.push(x);
        }
        // agar naya element chota hai pehle se toh s2 mein push kardo
        else if(x <= s2.top()){
            s2.push(x);
        }
        // s1 mein toh push karna hi hai hamesha
        s1.push(x);
    }
    
    void pop() {
        if(s1.empty())return;
        // agar s1 ka top s2 ka top hai toh s2 ka top bhi pop kardo 
        if(s1.top() == s2.top()){
            s2.pop();
        }
        // s1 ka top toh pop karna hi hai hamesha
        s1.pop();
    }
    
    int top() {
        // yeh toh s1 ka hi dekhenge
        if(s1.empty())return -1;
        return s1.top();
    }
    
    int getMin() {
        // yeh toh s2 ka hi dekhenge bcz yahi minimum element store kar raha hai hamesha
        if(s1.empty())return -1;
        return s2.top();
    }
};



// Approach : Using single stack and pair

class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>>s;
    // we are using pair to store the element and the minimum element till now
    
    void push(int x) {
        // agar stack khali hai toh minimum element bhi wahi hai
        if(s.empty()){
            s.push({x,x});
        }
        // agar naya element chota hai pehle se toh minimum element wahi hai
        else if(x <= s.top().second){
            s.push({x,x});
        }
        // agar naya element bada hai pehle se toh minimum element wahi hai
        else{
            s.push({x,s.top().second});
        }
    }
    
    void pop() {
        if(s.empty())return;
        s.pop();
    }
    
    int top() {
        if(s.empty())return -1;
        return s.top().first;
    }
    
    int getMin() {
        if(s.empty())return -1;
        return s.top().second;
    }
};