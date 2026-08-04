#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int dr1[4] = {0, 0, 1, -1};
const int dc1[4] = {1, -1, 0, 0};
    
const int dr2[4] = {0, 0, 2, -2};
const int dc2[4] = {2, -2, 0, 0};

const int dr3[4] = {1, 1, -1, -1};
const int dc3[4] = {1, -1, 1, -1};

bool is_valid(const int nr, const int nc)
{
    if(nr >= 0 && nr < 5 && nc >= 0 && nc < 5) return true;
    else return false;
}

bool check_distance(const int r, const int c, const vector<string>& place)
{   
    for(int i = 0; i < 4; ++i)
    {
        int nr = r + dr1[i];
        int nc = c + dc1[i];
        
        if(is_valid(nr, nc) && place[nr][nc] == 'P')
            return false;   
    }

    for(int i = 0; i < 4; ++i)
    {
        int nr = r + dr2[i];
        int nc = c + dc2[i];
        int tr = nr - dr2[i] / 2;
        int tc = nc - dc2[i] / 2;
        
        if(is_valid(nr, nc) && place[nr][nc] == 'P' &&
           is_valid(tr, tc) && place[tr][tc] != 'X')
            return false;
    }

    for(int i = 0; i < 4; ++i)
    {   
        int nr = r + dr3[i];
        int nc = c + dc3[i];
        
        if(is_valid(nr, nc) && place[nr][nc] == 'P' &&
           (place[r][nc] != 'X' || place[nr][c] != 'X'))
              return false;
    }

    return true;
}

bool bfs(const int row, const int col, const vector<string>& place)
{
    queue<tuple<int, int, int>> que;
    que.emplace(row, col, 0);
    
    bool visited[5][5] = {};
    visited[row][col] = true;
    
    while(!que.empty())
    {
        auto [r, c, dist] = que.front();
        que.pop();
        
        if(dist == 2) continue;
        
        for(int i = 0; i < 4; ++i)
        {
            int nr = r + dr1[i];
            int nc = c + dc1[i];
            
            if(!is_valid(nr, nc) || visited[nr][nc] || place[nr][nc] == 'X')
                continue;
            
            if(place[nr][nc] == 'P')
                return false;
            
            visited[nr][nc] = true;
            que.push({nr, nc, dist + 1});
        }  
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto& place: places)
    {
        bool isRight = true;
        
        for(int r = 0; r < 5; ++r)
        {
            for(int c = 0; c < 5; ++c)
            {
                // if(place[r][c] == 'P' && !check_distance(r, c, place))
                // {
                //     isRight = false;
                //     break;
                // }
                if(place[r][c] == 'P' && !bfs(r, c, place))
                {
                    isRight = false;
                    break;
                }
            }
            
            if(!isRight) break;
        }
    
        if(isRight) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}
