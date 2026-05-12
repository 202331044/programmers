#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for(string& str: quiz)
    {
        istringstream iss(str);
        
        int x, y, z;
        char op, equal;
        
        iss >> x >> op >> y >> equal >> z;
        
        int result = (op == '+') ? x + y : x - y;
        
        if(result == z) answer.push_back("O");
        else answer.push_back("X");
        
        // if(op == '+')
        // {
        //     if(x + y == z) answer.push_back("O");
        //     else answer.push_back("X");
        // }
        // else
        // {
        //     if(x - y == z) answer.push_back("O");
        //     else answer.push_back("X");
        // }
    }

    return answer;
}
