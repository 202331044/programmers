#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    int n = id_list.size();
    
    unordered_map<string, int> um;
    for(int i = 0; i < n; ++i)
        um[id_list[i]] = i;
    
    vector<unordered_set<string>> vec(n);
    for(string& str: report)
    {
        istringstream iss(str);
        string a, b;
        iss >> a >> b;
        vec[um[a]].insert(b);
    }
    
    unordered_map<string, int> count;
    for(int j = 0; j < n; ++j)
    {
        for(const string& user: vec[j])
            count[user]++;
    }
    
    vector<int> answer(n);
    for(int l = 0; l < n; ++l)
    {
        for(const string& user: vec[l])
        {
            if(count[user] >= k)
                answer[l]++;
        }
    }
    
    return answer;
}
