#include <string>
#include <vector>
#include <queue>

using namespace std;

void fill_que(const int r, const int c, const char request,
              vector<string>& storage,
              vector<vector<bool>>& visited, queue<pair<int, int>>& que)
{
        if((storage[r][c] == '0'|| storage[r][c] == request)
           && visited[r][c] == false)
        {
            visited[r][c] = true;
            que.push({r, c});
        }
}

void forklift(const char request, vector<string>& storage)
{
    int h = storage.size();
    int w = storage[0].size();
    
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    queue<pair<int, int>> que;
    
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    
    for(int r = 0; r < h; ++r)
        fill_que(r, 0, request, storage, visited, que);
    
    for(int c = 1; c < w; ++c)
        fill_que(0, c, request, storage, visited, que);
    
    for(int r = 1; r < h; ++r)
        fill_que(r, w - 1, request, storage, visited, que);
    
    for(int c = 1; c < w; ++c)
        fill_que(h - 1, c, request, storage, visited, que);
    
    while(!que.empty())
    {
        auto [cr, cc] = que.front();
        que.pop();
        
        if(storage[cr][cc] == request)
        {
            storage[cr][cc] = '0';
            continue;
        }
        
        for(int i = 0; i < 4; ++i)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr >= 0 && nr < h && nc >= 0 && nc < w && 
               visited[nr][nc] == false &&
               (storage[nr][nc] == request || storage[nr][nc] == '0'))
            {
                que.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
}


void forklift2(const char request, vector<string>& storage)
{
    int h = storage.size();
    int w = storage[0].size();
    
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    queue<pair<int, int>> que;
    que.push({0, 0});
    visited[0][0] = true;
    
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    
    while(!que.empty())
    {
        auto [cr, cc] = que.front();
        que.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr < 0 || nr >= h || nc < 0 || nc >= w || visited[nr][nc] == true)
                continue;
            
            if(storage[nr][nc] == request)
            {
                storage[nr][nc] = '0';
                visited[nr][nc] = true;
            }
            else if(storage[nr][nc] == '0')
            {
                que.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
}

void crane(const char request, vector<string>& storage)
{
    int h = storage.size();
    int w = storage[0].size();
    
    for(int r = 0; r < h; ++r)
    {
        for(int c = 0; c < w; ++c)
        {
            if(storage[r][c] == request)
                storage[r][c] = '0';
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int h = storage.size();
    int w = storage[0].size();

//     for(int i = 0; i < requests.size(); ++i)
//     {
//         if(requests[i].size() == 2)
//             crane(requests[i][0], storage);
//         else
//             forklift(requests[i][0], storage);
//     }
    
//     int answer = 0;
//     for(int r = 0; r < h; ++r)
//         for(int c = 0; c < w; ++c)
//             if(storage[r][c] != '0') answer++;
    
//     return answer;
    
    vector<string> pad_storage(h + 2, string(w + 2, '0'));
    for(int r = 0; r < h; ++r)
        for(int c = 0; c < w; ++c)
            pad_storage[r + 1][c + 1] = storage[r][c];
    
    for(int i = 0; i < requests.size(); ++i)
    {
        if(requests[i].size() == 2)
            crane(requests[i][0], pad_storage);
        else
            forklift2(requests[i][0], pad_storage);
    }
    
    int answer = 0;
    for(int r = 1; r <= h; ++r)
        for(int c = 1; c <= w; ++c)
            if(pad_storage[r][c] != '0') answer++;
    
    return answer;
}
