#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
//     priority_queue<int> left;
//     priority_queue<int, vector<int>, greater<int>> right;
//     vector<int> removed(200000);
//     string answer(n, 'O');
    
//     int idx = 0;
//     int cur = k;
    
//     for(int l = 0; l < k; ++l) left.push(l);
//     for(int r = k + 1; r < n; ++r) right.push(r);

//     for(string& str: cmd)
//     {
//         char op = str[0];
//         if(op == 'U')
//         {
//             int cnt = stoi(str.substr(2, str.size()));
//             while(!left.empty() && cnt > 0)
//             {
//                 cnt--;
//                 right.push(cur);
//                 cur = left.top();
//                 left.pop();
//             }
//         }
//         else if(op == 'D')
//         {
//             int cnt = stoi(str.substr(2, str.size()));
//             while(!right.empty() && cnt > 0)
//             {
//                 cnt--;
//                 left.push(cur);
//                 cur = right.top();
//                 right.pop();
//             }
//         }
//         else if(op == 'C')
//         {
//             answer[cur] = 'X';
//             removed[idx++] = cur;
            
//             if(!right.empty())
//             {
//                 cur = right.top();
//                 right.pop();
//             }
//             else
//             {
//                 cur = left.top();
//                 left.pop();
//             }
//         }
//         else
//         {
//             int prev = removed[--idx];
//             answer[prev] = 'O';
            
//             if(prev < cur) left.push(prev);
//             else right.push(prev);
//         }
//     }

//     return answer;
    vector<int> pre(n);
    vector<int> next(n);
    stack<int> removed;
    
    string answer(n, 'O');
    int cur = k;
    
    for(int i = 0; i < n; ++i)
    {
        pre[i] = i - 1;
        next[i] = i + 1;
    }
    
    for(string& str: cmd)
    {
        char op = str[0];
        
        
        if(op == 'U')
        {
            int cnt = stoi(str.substr(2));
            while(cnt--)
                cur = pre[cur];
        }
        else if(op == 'D')
        {
            int cnt = stoi(str.substr(2));
            while(cnt--)
                cur = next[cur];
        }
        else if(op == 'C')
        {
            removed.push(cur);
            answer[cur] = 'X';
            
            if(pre[cur] != -1)
                next[pre[cur]] = next[cur];
            if(next[cur] != n)
                pre[next[cur]] = pre[cur];
            
            if(next[cur] != n) cur = next[cur];
            else cur = pre[cur];
        }
        else
        {
            int idx = removed.top();
            removed.pop();
            
            answer[idx] = 'O';
            
            if(pre[idx] != -1)
                next[pre[idx]] = idx;
            if(next[idx] != n)
                pre[next[idx]] = idx;
        }
    }
    
    return answer;
}
