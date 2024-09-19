// class Solution {
// public:
//     int isOperator(char ch) {
//         if (ch == '+' || ch == '-' || ch == '*' || ch == '/') return 1;
//         return -1;
//     }

//     // Check if a character is an operand
//     int isOperand(char ch) {
//         return isdigit(ch);
//     }
    
//     int precedence(char op) {
//         if (op == '+' || op == '-') return 1;
//         if (op == '*' || op == '/') return 2;
//         return 0;
//     }
    
//     int scanNum(char ch) {
//         return int(ch - '0');
//     }
    
//     void show(vector<string>&vec) {
//         for(auto x:vec) {
//             cout<<x<<"   ";
//         } cout<<endl;
//     }

//     int operation(int a, int b, char op) {
//         switch (op) {
//             case '+': return b + a;
//             case '-': return b - a;
//             case '*': return b * a;
//             case '/': return b / a;  // Integer division
//             default: return 0;
//         }
//     }
    
//     int postfixEval(string postfix) {
//         int a, b;
//         stack<int> stk;
//         for (char token : postfix) {
//             if (isOperator(token) != -1) {
//                 a = stk.top(); stk.pop();
//                 b = stk.top(); stk.pop();
//                 stk.push(operation(a, b, token));
//             } else if (isOperand(token)) {
//                 stk.push(scanNum(token));
//             }
//         }
//         return stk.top();
//     }
    
//     string infixToPostfix(const string& exp) {
//         stack<char> operators;
//         string postfix = "";

//         for (char token : exp) {
//             if (isOperand(token)) {
//                 // Append operand to postfix expression
//                 postfix += token;
//             } else if (token == '(') {
//                 // Push '(' to the stack
//                 operators.push(token);
//             } else if (token == ')') {
//                 // Pop to postfix until '('
//                 while (!operators.empty() && operators.top() != '(') {
//                     postfix += operators.top();
//                     operators.pop();
//                 }
//                 operators.pop(); // Pop '('
//             } else if (isOperator(token) != -1) {
//                 // Pop operators with higher or equal precedence
//                 while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
//                     postfix += operators.top();
//                     operators.pop();
//                 }
//                 operators.push(token);
//             }
//         }

//         // Pop remaining operators
//         while (!operators.empty()) {
//             postfix += operators.top();
//             operators.pop();
//         }

//         return postfix;
//     }

//     // Complete evaluate function
//     int evaluate(string exp) {
//         string postfix = infixToPostfix(exp);
//         return postfixEval(postfix);
//     }

//     void recur(vector<string>&vec, vector<int>&res, int pos, string exp, int opening) {
//         if(pos == vec.size()) {
//             int r = evaluate(exp);
//             res.push_back(r);
//             return;
//         }
        
//         // otherwise create the expression
//         if(pos == vec.size()-1) {
//             while(opening--) {
//                 exp = exp + ")";
//             }
//             recur(vec, res, pos+1, exp, opening);
//             return;
//         }
        
//         exp = exp + "(";    opening++;
//         exp = exp + vec[pos];
//         exp = exp + vec[pos+1]; 
//         recur(vec, res, pos+2, exp, opening);
        
//         exp = exp + vec[pos+2];
//         exp = exp + ")";
//         opening--;
//         recur(vec, res, pos+3, exp, opening);
//     }

//     vector<int> diffWaysToCompute(string expression) {
//         vector<int>res;
//         vector<string>exp;
//         int x = 0, n = expression.length();
//         string curr = "";
//         while(x < n) {
//             if(expression[x] >= '0' && expression[x] <= '9') {
//                 curr = curr + expression[x];
//             } else {
//                 exp.push_back(curr);
//                 curr = "";
//                 exp.push_back(expression.substr(x,1));
//             }
//             x++;
//         }
//         exp.push_back(curr);
//         recur(exp, res, 0, "", 0);
//         // show(exp);
//         return res;
//     }
// };



class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i < expression.size(); ++i) {
            char oper = expression[i];
            if (oper == '+' || oper == '-' || oper == '*') {
                vector<int> s1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> s2 = diffWaysToCompute(expression.substr(i + 1));
                for (int a : s1) {
                    for (int b : s2) {
                        if (oper == '+') res.push_back(a + b);
                        else if (oper == '-') res.push_back(a - b);
                        else if (oper == '*') res.push_back(a * b);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(expression));
        return res;
    }
};
