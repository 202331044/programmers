#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    
    string answer;
    
    for(int i = 1; i < food.size(); ++i)
    {
        char ch = i + '0';
        int num = food[i] / 2;
        while(num--)
            answer += ch;
    }
    
    string rev = answer;
    
    reverse(rev.begin(), rev.end());
    
    return answer + '0' + rev;
}
