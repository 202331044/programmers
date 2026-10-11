#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
//     unordered_set<string> gem_type;
//     for(const string& gem: gems)
//         gem_type.insert(gem);
    
//     int start = 0, end = 0;
//     unordered_map<string, int> gem_count;
    
//     for(const string& gem: gems)
//     {
//         gem_count[gem]++;
        
//         if(gem_count.size() == gem_type.size())
//             break;
        
//         end++;
//     }

//     int left = 0;
//     int right = end;
    
//     while(right < gems.size())
//     { 
//         while(left <= right)
//         {
//             string gem = gems[left];
//             gem_count[gem]--;
//             left++;
            
//             if(gem_count[gem] == 0) break;
//         }
        
//         if(end - start > right - (left - 1))
//         {
//             start = left - 1;
//             end = right;
//         }
        
//         right++;
//         if(right == gems.size()) break;
        
//         while(right < gems.size())
//         {
//             string gem = gems[right];
//             gem_count[gem]++;
            
//             if(gem_count[gem] == 1) break;
            
//             right++;
//         }
//     }
    
//     return {start + 1, end + 1};
    
    unordered_set<string> gems_type(gems.begin(), gems.end());
    unordered_map<string, int> gem_count;
    
    int n = gems_type.size();
    int left = 0;
    int best_left = 0;
    int best_len = gems.size() + 1;
    
    for(int right = 0; right < gems.size(); ++right)
    {
        gem_count[gems[right]]++;
        
        while(gem_count.size() == n)
        {
            if(best_len > right - left + 1)
            {
                best_len = right - left + 1;
                best_left = left;
            }
            
            gem_count[gems[left]]--;
            
            if(gem_count[gems[left]] == 0)
                gem_count.erase(gems[left]);
            
            left++;
        }
    }
    
    return {best_left + 1, best_left + best_len};
}
