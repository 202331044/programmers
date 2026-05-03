#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    int total = 0;
    
    istringstream iss(my_string);
//     string str;
//     char op = '+';
    
//     while(iss >> str)
//     {
//         if(str == "+") op = '+';
//         else if(str == "-") op = '-';
//         else
//         {
//             int num = stoi(str);
//             if(op == '-') total -= num;
//             else total += num;
//         }
//     }
    
    iss >> total;
    
    while(!iss.eof())
    {
        char op;
        int num;
        iss >> op >> num;
        if(op == '+') total += num;
        else total -= num;
    }
    
    return total;
}
