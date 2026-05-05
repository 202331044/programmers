#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
    vector<string> num = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for(int i = 0; i < 10; ++i)
    {
        string str = num[i];
        while(true)
        {
            int idx = numbers.find(str);
            if(idx == string::npos) break;
            
            numbers.replace(idx, str.size(), to_string(i));
        }  
    }
    
    long long answer = stoll(numbers);
    
    return answer;
}
