#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// string convert_binary(long long number, vector<int>& vec, int& height)
// {
//     string result;
//     while(number)
//     {
//         result += (number % 2) + '0';
//         number /= 2;
//     }
    
//     reverse(result.begin(), result.end());
    
//     for(int i = 0; i < vec.size(); ++i)
//     {
//         int len = vec[i];
//         height = i + 1;
        
//         if(result.size() == len) break;
//         else if(result.size() < len)
//         {
//             string add((len - result.size()), '0');
//             result = add + result;
//             break;
//         }
//     }
    
//     return result;
// }

// int is_possible(string& str, int height)
// {
//     int rootIdx = (str.size() + 1) / 2 - 1;
    
//     if(str[rootIdx] == '0') 
//         return 0;
    
//     int term = 1;
//     for(int k = 0; k < height; ++k)
//     {
//         for(int i = term - 1; i < str.size(); i += term * 4)
//         {
//             if(str[i] == '1' || str[i + term * 2] == '1')
//             {
//                 if(str[i + term] == '0')
//                     return 0;  
//             }
//         }
//         term *= 2;
//     }

//     return 1;
// }

string convert_binary(long long num)
{
    if(num == 0) return "0";
    
    string result;
    while(num)
    {
        result += (num % 2) + '0';
        num /= 2;
    }
    
    reverse(result.begin(), result.end());
    
    int len = 1;
    while(len < result.size())
        len = len * 2 + 1;
    
    if(len != result.size())
        result = string(len - result.size(), '0') + result;
    
    return result;
}

bool is_valid_tree(const string& str, int parentIdx, int left, int right)
{
    if(left > right) return true;
    
    int mid = (right + left) / 2;
    
    if(str[parentIdx] == '0' && str[mid] == '1') return false;
    
    return is_valid_tree(str, mid, left, mid - 1) 
        && is_valid_tree(str, mid, mid + 1, right);
}

vector<int> solution(vector<long long> numbers) {
//     vector<int> vec = {1, 3, 7, 15, 31, 63};
//     vector<int> answer;
    
//     for(long long number: numbers)
//     {
//         int height = 0;
//         string str = convert_binary(number, vec, height);

//         int res = is_possible(str, height);
//         answer.push_back(res);
//     }
    
//     return answer;

    vector<int> answer;
    
    for(long long number: numbers)
    {
        string str = convert_binary(number);
        
        int rootIdx = str.size() / 2;
        
        if(is_valid_tree(str, rootIdx, 0, str.size() - 1))
            answer.push_back(1);
        else
           answer.push_back(0);
    }
    
    return answer;
}
