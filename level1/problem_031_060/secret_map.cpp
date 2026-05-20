#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void fill_map(int& n, vector<string>& map, vector<int>& arr)
{
     for(int num: arr)
    {
        string str;
        while(num)
        {
            if(num % 2 == 0) str += ' ';
            else str += '#';
            
            num /= 2;
        }
         
        if(str.size() < n) str.insert(str.end(), (n - str.size()), ' ');
        
        reverse(str.begin(), str.end());
        
        map.push_back(str);
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
//     vector<string> map1, map2;
//     fill_map(n, map1, arr1);
//     fill_map(n, map2, arr2);
    
//     vector<string> answer(n);
//     for(int i = 0; i < n; ++i)
//     {
//         for(int j = 0; j <n; ++j)
//         {
//             if(map1[i][j] == ' ' && map2[i][j] == ' ') answer[i].push_back(' ');
//             else answer[i].push_back('#');
//         }
//     }
     
//     return answer;
    
    vector<string> answer;
    
    for(int i = 0; i < n; ++i)
    {
        int num = arr1[i] | arr2[i];
        
        string str;
        for(int j = n - 1; j >=0; --j)
        {
            if(num & (1 << j)) str += '#';
            else str += ' ';
        }
        
        answer.push_back(str);
    }

    return answer;
}
