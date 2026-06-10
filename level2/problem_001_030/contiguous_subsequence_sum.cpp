#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    unordered_set<int> s;
    
//     for(int i = 0; i < n; ++i)
//     {
//         s.insert(elements[i]);
        
//         int sum = elements[i];
//         for(int j = i + 1; j < (i + n); ++j)
//         {
//             sum += elements[j % n];
//             s.insert(sum);
//         }
//     }
    
//     return s.size();
    
    for(int i = 0; i < n; ++i)
    {
        int sum = 0;
        
        for(int len = 1; len <= n; ++len)
        {
            sum += elements[(i + len - 1) % n];
            s.insert(sum);
        }  
    }
    
    return s.size();
}
