#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
//     vector<vector<vector<vector<vector<int>>>>> vec(3, 
//                                             vector<vector<vector<vector<int>>>>(2,
//                                             vector<vector<vector<int>>>(2,
//                                             vector<vector<int>>(2)))
//                                             );
//     unordered_map<string, int> mp;
//     mp["cpp"] = 0;
//     mp["java"] = 1;
//     mp["python"] = 2;
//     mp["backend"] = 0;
//     mp["frontend"] = 1;
//     mp["junior"] = 0;
//     mp["senior"] = 1;
//     mp["chicken"] = 0;
//     mp["pizza"] = 1;
//     mp["-"] = 3;
    
//     for(auto& p : info)
//     {
//         istringstream iss(p);
//         string str;
//         vector<int> tmp;
        
//         while(iss >> str)
//         {
//             if(mp.find(str) != mp.end())
//                 tmp.push_back(mp[str]);
//             else tmp.push_back(stoi(str));
//         }
        
//         int idx1 = tmp[0];
//         int idx2 = tmp[1];
//         int idx3 = tmp[2];
//         int idx4 = tmp[3];
//         int score = tmp[4];
        
//         vec[idx1][idx2][idx3][idx4].push_back(score);
//     }
    
//     vector<int> answer;
//     for(auto& q: query)
//     {
//         istringstream iss(q);
//         string str;
//         vector<string> tmp;
        
//         while(iss >> str)
//         {
//             if(str != "and")
//                 tmp.push_back(str);
//         }
        
//         int e1 = mp[tmp[0]];
//         int e2 = mp[tmp[1]];
//         int e3 = mp[tmp[2]];
//         int e4 = mp[tmp[3]];
        
//         int score = stoi(tmp[4]);
//         int s1 = e1;
//         int s2 = e2;
//         int s3 = e3;
//         int s4 = e4;
        
//         if(e1 == 3) s1 = 0, e1 = 2;
//         if(e2 == 3) s2 = 0, e2 = 1;
//         if(e3 == 3) s3 = 0, e3 = 1;
//         if(e4 == 3) s4 = 0, e4 = 1;
        
//         int cnt = 0;
//         for(int i = s1; i <= e1; ++i)
//             for(int j = s2; j <= e2; ++j)
//                 for(int k = s3; k <= e3; ++k)
//                     for(int l = s4; l <= e4; ++l)
//                     {
//                         for(int cmp: vec[i][j][k][l])
//                         {
//                             if(cmp >= score)
//                                 cnt++;
//                         }
//                     }
        
//         answer.push_back(cnt);
//     }
    
//     return answer;
    
    unordered_map<string, vector<int>> mp;
    
    for(auto& p: info)
    {
        istringstream iss(p);
        
        int score;
        string lang, job, career, food;
        
        iss >> lang >> job >> career >> food >> score;
        vector<string> vec = {lang, job, career, food};
        
        for(int mask = 0; mask < (1 << 4); ++mask)
        {
            string key;
            
            for(int i = 0; i < 4; ++i)
            {
                if(mask & (1 << i))
                    key += "-";
                else 
                    key += vec[i];
                
                key += " ";
            }
            
            mp[key].push_back(score);
        }
    }
    
    for(auto& it: mp)
        sort(it.second.begin(), it.second.end());
    
    vector<int> answer;
    for(auto& q: query)
    {
        istringstream iss(q);
        
        int score;
        string lang, job, career, food, tmp;
        
        iss >> lang >> tmp 
            >> job >> tmp 
            >> career >> tmp
            >> food
            >> score;
        
        vector<string> vec = {lang, job, career, food};
        
        string key;
        
        for(auto& v : vec)
            key += v + " ";
        
        auto& scores = mp[key];
        auto it = lower_bound(scores.begin(), scores.end(), score);
        answer.push_back(scores.end() - it);
    }
    
    return answer;
}
