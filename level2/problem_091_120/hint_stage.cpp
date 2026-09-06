#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(const int n, int idx, int& minCost, int total_cost,
         const vector<vector<int>>& cost, const vector<vector<int>>& hint,
         vector<int> hintCount)
{
    if(idx == n - 1)
    {
        for(int i = 0; i < n; ++i)
            total_cost += cost[i][min(n - 1, hintCount[i])];

        if(minCost > total_cost) minCost = total_cost;
        return;
    }
    
    dfs(n, idx + 1, minCost, total_cost, cost, hint, hintCount);
    
    for(int i = 1; i < hint[idx].size(); ++i)
        hintCount[hint[idx][i] - 1]++;

    dfs(n, idx + 1, minCost, total_cost + hint[idx][0], cost, hint, hintCount);
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int n = cost.size();
    int answer = 100000 * n;
    int idx = 0;
    int total_cost = 0;
    
    vector<int> hintCount(n, 0);

    dfs(n, idx, answer, total_cost, cost, hint, hintCount);
    
    return answer;
}
