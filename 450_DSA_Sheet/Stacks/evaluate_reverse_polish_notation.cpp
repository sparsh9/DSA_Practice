class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s ;
        for(auto &i:tokens)
        { 
            // jaise hi koi operator aaye, stack ke last 2 elements lo and unpe 
            // operator laga do and uska result stack mein push kardo
            if(i == "+" || i == "-" || i == "*" || i == "/") // operators 
            {
                int op1 = s.top() ; 
                s.pop() ;
                int op2 = s.top() ; 
                s.pop() ;
                if(i == "+") 
                    op1 = op2 + op1 ;
                if(i == "-") 
                    op1 = op2 - op1 ;
                if(i == "*") 
                    op1 = op2*op1 ; 
                if(i == "/") 
                    op1 = op2/op1 ;  
                s.push(op1) ;
            }
            // jab tak koi operator nahi hai, tab tak stack mein push karte raho
            else 
                s.push(stoi(i)) ; // number -> need to convert from str to int
        }    
        return s.top() ; 

    }
};