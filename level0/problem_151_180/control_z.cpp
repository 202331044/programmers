#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    string str;
    int sum = 0, num = 0;
    
    istringstream iss(s);
    
    while(iss >> str)
    {
        if(str == "Z") sum -= num;
        else
        {
            num = stoi(str);
            sum += num;
        }
    }
    
    return sum;
}
