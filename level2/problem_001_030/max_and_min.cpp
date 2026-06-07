#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    istringstream iss(s);
    
    int num;
    iss >> num;
    
    int maxVal = num, minVal = num;
    
    while(iss >> num)
    {
        if(maxVal < num) maxVal = num;
        if(minVal > num) minVal = num;
    }
    
    return to_string(minVal) + " " + to_string(maxVal);
}
