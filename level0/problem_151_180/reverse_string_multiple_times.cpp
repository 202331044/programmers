#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    for(auto query: queries)
    {
        int s = query[0], e = query[1];
        
        reverse(my_string.begin() + s, my_string.begin() + e + 1);
    }
    
    return my_string;
}
