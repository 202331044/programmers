#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int solution1(vector<string> friends, vector<string> gifts) {
    unordered_map<string, int> answer, score;
    unordered_map<string, unordered_map<string, int>> um;
    
    for(string& gift: gifts)
    {
        istringstream iss(gift);
        string from, to;
        iss >> from >> to;
        
        score[from]++;
        score[to]--;
        um[from][to]++;
    }
    
    int n = friends.size();
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            string from = friends[i];
            string to = friends[j];
            
            if(um[from][to] == um[to][from])
            {
                if(score[from] < score[to])
                    answer[to]++;
                else if(score[from] > score[to])
                    answer[from]++;
            }
            else if(um[from][to] < um[to][from])
                answer[to]++;
            else
                answer[from]++;
        }
    }
    
    int maxVal = 0;
    for(auto& ans: answer)
        maxVal = maxVal < ans.second ? ans.second : maxVal;
    
    return maxVal;
}

int solution(vector<string> friends, vector<string> gifts) {
    int n = friends.size();
    unordered_map<string, int> idx;
    vector<vector<int>> vec(n, vector<int>(n, 0));
    vector<int> score(n), answer(n);
    
    for(int i = 0; i < n; ++i)
        idx[friends[i]] = i;
    
    for(string& gift: gifts)
    {
        istringstream iss(gift);
        string from, to;
        
        iss >> from >> to;
        int idx1 = idx[from];
        int idx2 = idx[to];
        
        vec[idx1][idx2]++;
        score[idx1]++;
        score[idx2]--;
    }
    
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(vec[i][j] == vec[j][i])
            {
                if(score[i] < score[j])
                    answer[j]++;
                else if(score[i] > score[j])
                    answer[i]++;
            }
            else if(vec[i][j] < vec[j][i])
                answer[j]++;
            else
                answer[i]++;
        }
    }
    
    int maxVal = 0;
    for(int& cnt: answer)
        maxVal = maxVal < cnt ? cnt : maxVal;
    
    return maxVal;
}
