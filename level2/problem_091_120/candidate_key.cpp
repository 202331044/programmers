#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

void make_key_list(const int cols, int start, 
                 vector<vector<int>>& key_list, vector<int>& tmp)
{
    if(tmp.size() == cols)
        return;
    
    for(int i = start; i < cols; ++i)
    {
        tmp.push_back(i);
        key_list.push_back(tmp);
        
        make_key_list(cols, i + 1, key_list, tmp);
        
        tmp.pop_back();
    }
}

// bool isDuplicated(const string& str, const string& cmp)
// {
//     int cnt = 0;
    
//     for(const char a: str)
//         for(const char b: cmp)
//             if(a == b) cnt++;
    
//     return str.size() == cnt;
// }

// bool is_candidate_key(const vector<int>& keys, 
//                       const vector<vector<string>>& relation)
// {
//     unordered_set<string> duplication;
    
//     for(const auto& tuple: relation)
//     {
//         string str;
//         for(const int idx: keys)
//             str += tuple[idx];
        
//         if(duplication.find(str) == duplication.end()) 
//             duplication.insert(str);
//         else return false;
//     }
    
//     return true;
// }

// bool is_subset(const vector<int>& small, const vector<int>& big)
// {
//     for(int x: small)
//     {
//         if(find(big.begin(), big.end(),  x) == big.end()) 
//             return false;
//     }
    
//     return true;
// }

int solution(vector<vector<string>> relation) {
//     int cols = relation[0].size();
//     vector<int> tmp;
//     vector<vector<int>> key_list;
    
//     make_key_list(cols, 0, key_list, tmp);
    
//     stable_sort(key_list.begin(), key_list.end(), 
//          [](const vector<int>& a, const vector<int>& b)
//          {
//              if(a.size() != b.size()) 
//                  return a.size() < b.size();
//          });
    

//     unordered_set<string> answer;
    
//     for(const auto& keys: key_list)
//     {
//         bool isValid = true;
//         unordered_set<string> dup;
        
//         for(auto& tuple: relation)
//         {
//             string str;
            
//             for(const int idx: keys)
//                 str += (tuple[idx] + " ");
            
//             if(dup.find(str) == dup.end())
//                 dup.insert(str);
//             else
//             {
//                 isValid = false;
//                 break;
//             }
//         }

//         if(isValid)
//         {
//             string ans;
            
//             for(char ch: keys)
//                 ans += to_string(ch);
            
//             answer.insert(ans);
//         }  
//     }
    
//     unordered_set<string> del;
    
//     for(const auto& str: answer)
//         for(const auto& cmp: answer)
//             if(str != cmp && isDuplicated(str, cmp))
//                 del.insert(cmp);   

//   return answer.size() - del.size();
    
//     int cols = relation[0].size();
    
//     vector<vector<int>> key_list;
//     vector<int> tmp;
    
//     make_key_list(cols, 0, key_list, tmp);
    
//     stable_sort(key_list.begin(), key_list.end(), 
//                 [](const auto& a, const auto&b)
//                 {
//                     return a.size() < b.size();
//                 });
    
    
//     vector<vector<int>> answer;
//     for(const auto& keys: key_list)
//     {
//         bool isValid = true;
        
//         for(const auto& ans: answer)
//         {
//             if(is_subset(ans, keys))
//             {
//                 isValid = false;
//                 break;
//             }
//         }
        
//         if(!isValid) continue;
        
//         if(is_candidate_key(keys, relation))
//             answer.push_back(keys);
//     }
    
//     return answer.size();
    
    int col = relation[0].size();
    vector<int> masks;
    
    for(int mask = 1; mask < (1 << col); ++mask)
        masks.push_back(mask);
    
   sort(masks.begin(), masks.end(), [](const auto& a, const auto& b)
        {
            return __builtin_popcount(a) < __builtin_popcount(b);
        });
    
    vector<int> answer;
    for(const int mask: masks)
    {
        bool isStop = false;
        for(int ans: answer)
        {
            if((ans & mask) == ans)
            {
                isStop = true;
                break;
            }
        }
        
        if(isStop) continue;
        
        unordered_set<string> duplication;
        for(const auto& tuple: relation)
        {
            string str;
            
            for(int i = 0; i < col; ++i)
                if(mask & (1 << i)) 
                    str += tuple[i];
            
            if(duplication.find(str) == duplication.end())
                duplication.insert(str);
            else
            {
                isStop = true;
                break;
            }      
        }
        
        if(!isStop) answer.push_back(mask);
    }
   
    return answer.size();
}
