#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_valid(vector<int> vec, vector<vector<int>>& q, vector<int>& ans)
{
    for(int i = 0; i < q.size(); ++i)
    {
        int cnt = 0;
        
        for(int num: vec)
        {   
            if(find(q[i].begin(), q[i].end(), num) != q[i].end()) 
                cnt++;
            else if(cnt > ans[i]) 
                return false;
        }
        
        if(cnt != ans[i]) 
            return false;
    }
    
    return true;
}

bool is_valid2(int mask, const vector<int>& q_mask, const vector<int>& ans)
{
    for(int i = 0; i < q_mask.size(); ++i)
        if(__builtin_popcount(mask & q_mask[i]) != ans[i]) 
            return false;
    
    return true;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
//     int cnt = 0;
    
//     for(int i = 1; i <= n - 4; ++i)
//         for(int j = i + 1; j <= n - 3; ++j)
//             for(int k = j + 1; k <= n - 2; ++k)
//                 for(int l = k + 1; l <= n - 1; ++l)
//                     for(int m = l + 1; m <= n; ++m)
//                         if(is_valid({i, j, k, l, m}, q, ans)) cnt++;
    
//     return cnt;
    
    int cnt = 0;
    
    vector<int> q_mask;
    for(int i = 0; i < q.size(); ++i)
    {
        int tmp = 0;
        for(int j = 0; j < 5; ++j)
            tmp |= (1 << q[i][j]);
        
        q_mask.push_back(tmp);
    }
    
    for(int i = 1; i <= n - 4; ++i)
    {
        for(int j = i + 1; j <= n - 3; ++j)
        {
            for(int k = j + 1; k <= n - 2; ++k)
            {
                for(int l = k + 1; l <= n - 1; ++l)
                {
                    for(int m = l + 1; m <= n; ++m)
                    {
                        int mask = 
                            (1 << i) | (1 << j) | (1 << k) | (1 << l) | (1 << m);
                        if(is_valid2(mask, q_mask, ans)) cnt++;
                    }
                }       
            }
        }   
    }
        
    return cnt;
}
