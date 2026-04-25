#include <string>
#include <vector>
#include <numeric>

using namespace std;

string solution(vector<string> arr) {
    string answer = "";
    
    // for(string str: arr)
    //     answer += str;
    
    answer = accumulate(arr.begin(), arr.end(), string{});
    
    return answer;
}
