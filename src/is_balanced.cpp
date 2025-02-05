#include "../src/is_balanced.h"

void error(string msg, char c){
    cout << "Message: " << msg << "\n"
         << "Symbol: " << c << "\n";
}

bool is_balanced(string s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{' || c == '<'){st.push(c); }
        else if (c == ')' || c == ']' || c == '}' || c == '>') {
            if (st.empty()) {
                error("Closing bracket found with an empty stack", c);
                return false;
            }
            char topChar = st.top();
            if ((topChar == '(' && c != ')') ||
                (topChar == '[' && c != ']') ||
                (topChar == '{' && c != '}') ||
                (topChar == '<' && c != '>')) {
                error("Different bracket", c);
                return false;
            }
            st.pop();
        }
        else{ error("Unknown char", c); }
    }
    return st.empty();
}
