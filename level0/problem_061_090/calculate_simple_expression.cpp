#include <string>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

int solution(string binomial) {

//     char op;
//     bool isFirst = true;
//     string str1 = "", str2 = "";
     
//     for(char ch: binomial)
//     {
//         if(isdigit(ch))
//         {
//             if(isFirst) str1 += ch;
//             else str2 += ch;
//         }
//         else if(ch != ' ')
//         {
//             op = ch;
//             isFirst = false;
//         }   
//     }
   
//     int num1 = stoi(str1), num2 = stoi(str2);

//     if(op == '+') return num1 + num2;
//     else if(op == '-') return num1 - num2;
    
//     return num1 * num2;
    int num1{}, num2{};
    char op;
    
    istringstream iss(binomial);
    iss >> num1 >> op >> num2;
    
    if(op == '+') return num1 + num2;
    if(op == '-') return num1 - num2;
    
    return num1 * num2;
}
