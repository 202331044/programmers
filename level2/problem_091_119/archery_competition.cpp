#include <string>
#include <vector>

using namespace std;

void dfs(const int n, int idx, int& maxDiff, int lionArrow, 
         vector<int>& answer, vector<int>& info, vector<int>& lion)
{
    if(idx == 10)
    {
        lion[10] = n - lionArrow;
        int lionScore = 0;
        int apeachScore = 0;
        
        for(int i = 0; i < 11; ++i)
        {
            if(lion[i] > info[i]) lionScore += 10 - i;
            else if(info[i] != 0) apeachScore += 10 - i;
        }
        
        int diff = lionScore - apeachScore;
        if(maxDiff < diff)
        {
            maxDiff = diff;
            answer = lion;
        }
        else if(maxDiff == diff)
        {
            for(int j = 10; j >= 0; --j)
            {
                if(lion[j] > answer[j])
                {
                    answer = lion;
                    break;
                }
                else if(lion[j] < answer[j])
                    break;
            }
        }
        
        lion[10] = 0;
        return;
    }
    
    if(lionArrow + info[idx] + 1 <= n)
    {
        lion[idx] = info[idx] + 1;
        dfs(n, idx + 1, maxDiff, lionArrow + info[idx] + 1, 
            answer, info, lion);
        lion[idx] = 0;
    }

    dfs(n, idx + 1, maxDiff, lionArrow, answer, info, lion);
}

vector<int> solution(int n, vector<int> info) {
//     int apeachFinalScore = 0;
    
//     for(int i = 0; i < 10; ++i)
//         if(info[i] > 0) apeachFinalScore += (10 - i);
    
//     int maxDiff = 0;
//     int lion = 0;
//     int arrow = -1;
    
//     for(int mask = 1; mask < (1 << 10); ++mask)
//     {
//         int lionArrow = 0;
//         int lionScore = 0;
//         int apeachScore = apeachFinalScore;

//         for(int i = 0; i < 10; ++i)
//         {
//             if(mask & (1 << i))
//             {
//                 lionArrow += (info[9 - i] + 1);
//                 lionScore += i + 1;
//                 if(info[9 - i] > 0) apeachScore -= (i + 1);
//             }
//         }

//         if(lionArrow <= n && maxDiff < lionScore - apeachScore)
//         {
//             maxDiff = lionScore - apeachScore;
//             lion = mask;
//             arrow = lionArrow;
//         }
//         else if(lionArrow <= n && maxDiff == lionScore - apeachScore)
//         {
//             bool valid = false;
            
//             if(arrow == lionArrow)
//             {
//                 for(int k = 0; k < 10; ++k)
//                 {
//                     if((mask & (1 << k)) > (lion & (1 << k)))
//                     {
//                         valid = true;
//                         break;
//                     }
//                     else if((mask & (1 << k)) < (lion & (1 << k)))
//                         break;
//                 }
//             }
            
//             if(arrow < lionArrow || valid)
//             {
//                 maxDiff = lionScore - apeachScore;
//                 lion = mask;
//                 arrow = lionArrow;
//             }
//         }
//     }
    
//     if(maxDiff == 0) return {-1};

//     vector<int> answer(11, 0);
    
//     for(int i = 0; i < 10; ++i)
//         if(lion & (1 << i))
//             answer[9 - i] = (info[9 - i] + 1);

//     answer[10] = n - arrow;

//     return answer;
    
    int idx = 0;
    int maxDiff = 0;
    int lionArrow = 0;
    
    vector<int> answer(11, 0), lion(11, 0);
    dfs(n, idx, maxDiff, lionArrow, answer,info, lion);
    
    if(maxDiff == 0) return {-1};
    
    return answer;
}
