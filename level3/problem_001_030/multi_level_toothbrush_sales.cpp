#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
//     const int MAX = 100 * 100;
    
//     unordered_map<string, int> name_to_idx;
//     name_to_idx["-"] = -1;
    
//     for(int i = 0; i < enroll.size(); ++i)
//         name_to_idx[enroll[i]] = i;
    
//     vector<vector<int>> prices(enroll.size(), vector<int>(MAX + 1, 0));
    
//     for(int i = seller.size() - 1; i >= 0; --i)
//     {
//         string name = seller[i];
//         int idx = name_to_idx[name];
//         prices[idx][amount[i] * 100]++;
//     }
    
//     vector<int> answer;
    
//     for(int i = enroll.size() - 1; i >= 0; --i)
//     {
//         int to = name_to_idx[referral[i]];
//         int sum = 0;
        
//         for(int money = 0; money <= MAX; ++money)
//         {
//             int add = (double)money * 0.1;
            
//             if(to != -1)
//                 prices[to][add] += prices[i][money];
            
//             sum += (money - add) * prices[i][money];
//         }
//         answer.push_back(sum);
//     }
    
//     reverse(answer.begin(), answer.end());
    
//     return answer;
    
    unordered_map<string, int> name_to_idx;
    for(int i = 0; i < enroll.size(); ++i)
        name_to_idx[enroll[i]] = i;
    
    vector<int> parent(enroll.size(), -1);
    for(int i = 0; i < enroll.size(); ++i)
    {
        string p = referral[i];
        if(p != "-")
            parent[i] = name_to_idx[p];
    }
    
    vector<int> answer(enroll.size(), 0);
    
    for(int i = 0; i < seller.size(); ++i)
    {
        int cur = name_to_idx[seller[i]];
        int money = amount[i] * 100;

        while(cur != -1 && money > 0)
        {
            int add = (double)money * 0.1;
            answer[cur] += money - add;
            cur = parent[cur];
            money = add;
        }
    }
    
    return answer;
}
