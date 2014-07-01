// Evaluate the value of an arithmetic expression in Reverse Polish Notation.

// Valid operators are +, -, *, /. Each operand may be an integer or another expression.

// Some examples:
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> myStack;
        for(int i = 0; i < tokens.size(); ++i) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int op2 = myStack.top();
                myStack.pop();
                int op1 = myStack.top();
                myStack.pop();
                int res;
                if(tokens[i] == "+") {
                    res = op1+op2;
                } else if(tokens[i] == "-") {
                    res = op1-op2;
                } else if(tokens[i] == "*") {
                    res = op1*op2;
                } else if(tokens[i] == "/") {
                    res = op1/op2;
                }
                myStack.push(res);
            } else {
                stringstream ss(tokens[i]);
                int op;
                ss>>op;
                myStack.push(op);
            }
        }
        return myStack.top();
    }
};
