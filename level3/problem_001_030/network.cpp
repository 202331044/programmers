#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(int i, vector<vector<int>>& computers, vector<bool>& visited)
{
    queue<int> que;
    que.push(i);
    visited[i] = true;
    
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        
        for(int next = 0; next < visited.size(); ++next)
        {
            if(computers[cur][next] == 1 && visited[next] == false)
            {
                que.push(next);
                visited[next] = true;
            }
        }
    }
}

void dfs(int cur, vector<vector<int>>& computers, vector<bool>& visited)
{
    visited[cur] = true;
    
    for(int next = 0; next < visited.size(); ++next)
    {
        if(visited[next] == false && computers[cur][next] == 1)
            dfs(next, computers, visited);
    }
}

int solution(int n, vector<vector<int>> computers) {

    vector<bool> visited(n, false);
    int answer = 0;
    
    for(int i = 0; i < n; ++i)
    {
        if(visited[i]) continue;
        
        answer++;
        //bfs(i, computers, visited);
        dfs(i, computers, visited);
    }
    
    return answer;
}
