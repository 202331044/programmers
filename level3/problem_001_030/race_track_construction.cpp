#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<int> dr = {1, -1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

int bfs(vector<vector<int>> board)
{
    int n = board.size();
    vector<vector<vector<bool>>> visited(
        n, vector<vector<bool>>(n, vector<bool>(4, false))
    );
    priority_queue<
        pair<int, tuple<int, int, int>>,
        vector<pair<int, tuple<int, int, int>>>,
        greater<pair<int, tuple<int, int, int>>>
    > pq;
    pq.push({0, {0, 0, 0}});
    pq.push({0, {0, 0, 2}});

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        
        int cost = cur.first;
        int r = get<0>(cur.second);
        int c = get<1>(cur.second);
        int dir = get<2>(cur.second);
        
        if(visited[r][c][dir] == true) continue;
        visited[r][c][dir] = true;
        
        if(r == n - 1 && c == n -1)
            return cost;
            
        for(int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int ndir = i;
            int ncost = cost + 100;
            
            if(dir != ndir) ncost += 500;

            if(nr >= 0 && nr < n && nc >= 0 && nc < n 
               && board[nr][nc] == 0 
               && visited[nr][nc][ndir] == false)
            {
                pq.push({ncost, {nr, nc, ndir}});
            }      
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    answer = bfs(board);
    return answer;
}
