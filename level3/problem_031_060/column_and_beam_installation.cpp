#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool insert_construction(
    const int type, const int n, 
    int x, int y, 
    vector<vector<vector<bool>>>& state
)
{
    if(type == 0)
    {
        if(y == n + 1) return true;
        if(state[y + 1][x][0] == true) return true;
        if(state[y][x][1] == true) return true;
        if(state[y][x - 1][1] == true) return true;
    }
    else
    {
        if(state[y + 1][x][0] == true) return true;
        if(state[y + 1][x + 1][0] == true) return true;
        if(state[y][x - 1][1] == true && state[y][x + 1][1] == true) return true;
    }
    
    return false;
}

bool delete_construction(
    const int n, int x, int y, 
    vector<vector<vector<bool>>>& state
)
{
    for(int i = x - 1; i < x + 2; ++i)
        for(int j = y - 1; j < y + 2; ++j)
            for(int k = 0; k < 2; ++k)
                if(state[j][i][k] == true 
                    && insert_construction(k, n, i, j, state) == false)
                            return false;
    
    return true;             
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<vector<bool>>> state(
        n + 3, vector<vector<bool>>(n + 3, vector<bool>(2, false))
    );
    
    for(const auto& frame: build_frame)
    {
        int x = frame[0], y = frame[1];
        int a = frame[2], b = frame[3];
        
        int nx = x + 1;
        int ny = n + 1 - y;
        
        if(b == 1)
        {
            if(insert_construction(a, n, nx, ny, state))
                state[ny][nx][a] = true;
        }
        else
        {
            state[ny][nx][a] = false;
            if(delete_construction(n, nx, ny, state) == false)
                state[ny][nx][a] = true;
        }
    }
    
    vector<vector<int>> answer;
    
//     for(int x = 1; x < n + 3; ++x)
//         for(int y = 1; y < n + 3; ++y)
//             for(int k = 0; k < 2; ++k)
//                 if(state[y][x][k] == true)
//                     answer.push_back({x - 1, n + 1 - y, k});
    
//     sort(answer.begin(), answer.end(), [](const auto& a, const auto& b)
//     {
//         if(a[0] != b[0]) return a[0] < b[0];
//         if(a[1] != b[1]) return a[1] < b[1];
//         return a[2] < b[2];
//     });
    
    for(int x = 1; x < n + 3; ++x)
        for(int y = n + 2; y >= 1; --y)
            for(int k = 0; k < 2; ++k)
                if(state[y][x][k])
                    answer.push_back({x - 1, n + 1 - y, k});
                    
    return answer;
}
