#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string polynomial) {
    string n, op;

    istringstream iss(polynomial);
    iss >> n;
    
    int x = 0, num = 0;
    
    if(n[n.size() - 1] == 'x')
    {
        if(n.size() == 1) x = 1;
        else x = stoi(n.substr(0, n.size() - 1));
    }
    else
        num = stoi(n);
    
    while(iss >> op >> n)
    {
        if(n[n.size() - 1] == 'x')
        {
            if(n.size() == 1) x += 1;
            else x += stoi(n.substr(0, n.size() - 1));
        } 
        else
            num += stoi(n);
    }
    
    string answer;
    if(x == 1) answer += 'x';
    else if(x > 1) answer += to_string(x) + 'x';
    
    if(answer.empty() && num != 0) answer += to_string(num);
    else if(!answer.empty() && num > 0) answer += " + " + to_string(num);

    return answer;
}
