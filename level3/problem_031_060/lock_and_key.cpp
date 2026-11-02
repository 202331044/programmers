#include <string>
#include <vector>

using namespace std;

bool is_fit(
    int type,
    int n, int m,
    int lr, int lc, int kr, int kc,
    vector<vector<int>>& lock, vector<vector<int>>& key
)
{
    for(int r = 0; r < n; ++r)
    {
        for(int c = 0; c < n; ++c)
        {
            int a = r - lr;
            int b = c - lc;
            
            int x = kc - b;
            int y = kr - a;

            if(type == 1)
            {
                x = kc + a;
                y = kr - b;
            }
            else if(type == 2)
            {
                x = kc + b;
                y = kr + a;
            }
            else if(type == 3)
            {
                x = kc - a;
                y = kr + b;
            }
            
            if(lock[r][c] == 0)
            {
                if(y >= m || y < 0 || x >= m || x < 0 || key[y][x] == 0) 
                    return false;
            }
            else
            {
                if(y < m && y >= 0 && x < m && x >= 0 && key[y][x] == 1)
                    return false;
            }
        }
    }
    
    return true;
}

bool check_board(const int n, const int m, vector<vector<int>>& board)
{
    for(int r = m; r < m + n; ++r)
        for(int c = m; c < m + n; ++c)
            if(board[r][c] != 1)
                return false;

    return true;
}

vector<vector<int>> rotate_key(vector<vector<int>>& key)
{  
    int m = key.size();
    
    vector<vector<int>> new_key(m, vector<int>(m));
    
    for(int y = 0; y < m; ++y)
        for(int x = 0; x < m; ++x)
            new_key[x][m - y - 1] = key[y][x];
    
    return new_key;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
//     int n = lock.size();
//     int m = key.size();
    
//     vector<pair<int, int>> lock_holes;
//     for(int r = 0; r < n; ++r)
//         for(int c = 0; c < n; ++c)
//             if(lock[r][c] == 0) 
//                 lock_holes.push_back({r, c});
    
//     vector<pair<int, int>> key_bump;
//     for(int r = 0; r < m; ++r)
//         for(int c = 0; c < m; ++c)
//             if(key[r][c] == 1) 
//                 key_bump.push_back({r, c});
    
//     if(lock_holes.size() == 0) return true;
//     if(key_bump.size() == 0) return false;
    
//     int lr = lock_holes[0].first;
//     int lc = lock_holes[0].second;
    
//     for(int type = 0; type < 4; ++type)
//     { 
//         for(auto [kr, kc]: key_bump)
//         {
//             bool isValid = is_fit(type, n, m, lr, lc, kr, kc, lock, key);
//             if(isValid) return true;
//         }
//     }
    
//     return false;

    int n = lock.size();
    int m = key.size();
    
    vector<vector<int>> board(n + m * 2, vector<int>(n + m * 2, 0));
    
    for(int r = 0; r < n; ++r)
        for(int c = 0; c < n; ++c)
            board[r + m][c + m] = lock[r][c];
    
    for(int i = 0; i < 4; ++i)
    {
        for(int r = 0; r < n + m; ++r)
        {
            for(int c = 0; c < n + m; ++c)
            {
                for(int y = 0; y < m; ++y)
                    for(int x = 0; x < m; ++x)
                        board[r + y][c + x] += key[y][x];
                
                if(check_board(n, m, board)) return true;
                
                for(int y = 0; y < m; ++y)
                    for(int x = 0; x < m; ++x)
                        board[r + y][c + x] -= key[y][x];
            }
        }
        key = rotate_key(key);   
    }
    return false;
}
