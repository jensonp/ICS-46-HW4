#include <iostream>
#include "../src/is_balanced.h"
void error(string msg, char c){
    cout << "Message: " << msg <<"\n"
         << "Symbol: " << c << "\n";
}
bool is_balanced(string s){
    std::stack<char> stack;
    for (auto c : s){
        if(c == '('|| c == '<'||c == '['||c == '{'){ stack.push(c); }
        else if(c == ')'|| c == '>'||c == ']'||c == '}'){
            if(stack.empty()) return false;
            stack.pop();
        }
    }
    return stack.empty();
}

