#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
//     vector<int> groups(cards.size() + 1, -1);
//     int idx = 0;
    
//     for(int i = 0; i < cards.size(); ++i)
//     {
//         int pos = i;
//         if(groups[cards[pos]] != -1) continue;
        
//         while(groups[cards[pos]] == -1)
//         {
//             groups[cards[pos]] = idx;
//             pos = cards[pos] - 1;
//         }
        
//         idx++;
//     }

//     vector<int> sum(idx, 0);

//     for(int i = 1; i < groups.size(); ++i)
//         sum[groups[i]]++;
    
//     int answer = 0;
    
//     for(int i = 0; i < sum.size(); ++i)
//         for(int j = i + 1; j < sum.size(); ++j)
//             answer = max(sum[i] * sum[j], answer);
    
//     return answer;
    
    vector<bool> visited(cards.size() + 1, false);
    int first = 0, second = 0;
    
    for(int i = 0; i < cards.size(); ++i)
    {
        int pos = i;
        int cnt = 0;
        if(visited[cards[pos]]) continue;
        
        while(visited[cards[pos]] == false)
        {
            visited[cards[pos]] = true;
            pos = cards[pos] - 1;
            cnt++;
        }
        
        if(first < cnt)
        {
            second = first;
            first = cnt;
        }
        else if(second < cnt)
            second = cnt;
    }

    return first * second;
    
}
