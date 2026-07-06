#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> orders;
    for(int number: numbers)
        orders.push_back(to_string(number));
    
    sort(orders.begin(), orders.end(), [](const string& a, const string& b)
         {
             return a + b > b + a;
         });
    
    if(orders[0] == "0") return "0";
    
    string answer;
    for(string& str: orders)
        answer += str;
    
    return answer;
}
