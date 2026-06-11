#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//int maxCnt = 0;

// void getCnt(const int& n, int k, int cnt, vector<bool>& visited, 
//             vector<vector<int>>& dungeons)
// {
//     for(int i = 0; i < n; ++i)
//     {
//         if(!visited[i] && k >= dungeons[i][0])
//         {
//             visited[i] = true;
//             getCnt(n, k - dungeons[i][1], cnt + 1, visited, dungeons);
//             visited[i] = false;
//         }    
//     }
    
//     maxCnt = max(maxCnt, cnt);
// }

void dfs(int k, int cnt, vector<bool>& visited, const vector<vector<int>>& dungeons, int& answer)
{
    answer = max(cnt, answer);
    
    for(int i = 0; i < dungeons.size(); ++i)
    {
        if(!visited[i] && k >= dungeons[i][0])
        {
            visited[i] = true;
            dfs(k - dungeons[i][1], cnt + 1, visited, dungeons, answer);
            visited[i] = false;
        }    
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    // int n = dungeons.size();
    
    vector<bool> visited(dungeons.size(), false);
    // getCnt(n, k, 0, visited, dungeons);
    // return maxCnt;
    
    dfs(k, 0, visited, dungeons, answer);
    
    return answer;
    
}
