#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr) {
    vector<int> len(31, 0);
    
    for(string& str: strArr)
        len[str.size()]++;
    
    auto it = max_element(len.begin(), len.end());
    
    return *it;
}
