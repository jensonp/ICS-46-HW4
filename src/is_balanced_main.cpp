#include "is_balanced.h"
#include <vector>
void print_test(const std::vector<string>& tests ){ 
    for(size_t i=0; i<tests.size(); ++i) 
    {std::cout << tests[i] << " is " << 
    (is_balanced(tests[i])?"balanced\n":"not balanced\n"); }}
int main()
{  
    std::string 
    test1 = "[{}", 
    test2 = "{{[]}}", 
    test3 = "", 
    test4 = "{{((((()))))}}", 
    test5 = "{}", 
    test6 = "}";
    std::vector<string> tests = { test1, test2, test3, test4, test5, test6 };
    print_test(tests);
}