#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
//     int s = -1, e = -1;
//     vector<int> answer;
    
//     for(int i = 0; i < arr.size(); ++i)
//     {
//         if(arr[i] == 2)
//         {
//             s = i;
//             break;
//         }
//     }
    
//     if(s == -1)
//     {
//         answer.push_back(-1);
//         return answer;
//     }
    
//     for(int j = arr.size() - 1; j >= 0; --j)
//     {
//         if(arr[j] == 2) 
//         {
//             e = j;
//             break;
//         }
//     }

    
//     for(int k = s; k <= e; ++k)
//         answer.push_back(arr[k]);
    
    auto it1 = find(arr.begin(), arr.end(), 2);
    auto rit = find(arr.rbegin() ,arr.rend(), 2);
    
    if(it1 == arr.end()) return {-1};
    
    auto it2 = rit.base() - 1;
    
    return vector<int>(it1, it2 + 1);
}
