#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>

using namespace std;

long long calculate(char op, long long a, long long b)
{
    switch(op)
    {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
    }
    return 0;
}

void split_string(string& expression,
                  vector<long long>& numbers, vector<char>& operators)
{
    string str;
    for(char ch: expression)
    {
        if(ch == '+' || ch == '-' || ch == '*')
        {
            numbers.push_back(stoll(str));
            operators.push_back(ch);
            str = "";
        }
        else str += ch;
    }
    numbers.push_back(stoll(str));
}

long long solution(string expression) {
//     vector<vector<char>> priority = {{'+', '-', '*'},
//                                       {'+', '*', '-'},
//                                       {'-', '+', '*'},
//                                       {'-', '*', '+'},
//                                       {'*', '+', '-'},
//                                       {'*', '-', '+'}};

//     vector<long long> numbers;
//     vector<char> operators;
//     split_string(expression, numbers, operators);
    
//     long long answer = 0;
//     for(auto& order: priority)
//     {
//         vector<long long> t_numbers = numbers;
//         vector<char> t_operators = operators;
        
//         for(char op: order)
//         {
//             int idx = 0;
//             vector<long long> tt_numbers = {t_numbers[0]};
//             vector<char> tt_operators;

//             while(idx < t_operators.size())
//             {
//                 if(t_operators[idx] == op)
//                 {
//                     long long a = tt_numbers.back();
//                     tt_numbers.pop_back();
//                     tt_numbers.push_back(calculate(op, a, t_numbers[idx+1]));
//                 }
//                 else
//                 {
//                     tt_numbers.push_back(t_numbers[idx + 1]);
//                     tt_operators.push_back(t_operators[idx]);
//                 }
//                 idx++;
//             }
//             t_numbers = tt_numbers;
//             t_operators = tt_operators;
//         }

//         answer = max(answer, abs(t_numbers.back()));
//     }
    
//     return answer;
    
    vector<char> priority = {'*', '+', '-'};
    sort(priority.begin(), priority.end());
    
    vector<long long> numbers;
    vector<char> operators;  
    split_string(expression, numbers, operators);
    
    long long answer = 0;
    
    do
    {
        auto nums = numbers;
        auto ops = operators;
        
        for(char op: priority)
        {
            vector<long long> next_nums = {nums[0]};
            vector<char> next_ops;
            
            for(int i = 0; i < ops.size(); ++i)
            {
                if(op == ops[i]) 
                {
                    next_nums.back() = 
                        calculate(op, next_nums.back(), nums[i + 1]);
                }
                else
                {
                    next_ops.push_back(ops[i]);
                    next_nums.push_back(nums[i + 1]);
                }
            }
            
            nums = move(next_nums);
            ops = move(next_ops);
        }
        
        answer = max(answer, llabs(nums.back()));
        
    } while(next_permutation(priority.begin(), priority.end()));
    
    return answer;    

}
