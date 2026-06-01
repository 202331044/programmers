#include <string>
#include <vector>
#include <utility>

using namespace std;

int solution(vector<vector<int>> signals) {
    vector<pair<int ,int>> vec;
    int MAX = 10000000;
    
    
    vector<int> count(MAX + 1, 0);
    for(auto& signal: signals)
    {
        int start = signal[0] + 1;
        int term = signal[0] + signal[1] + signal[2];
        int range = signal[1];
        
        for(int i = start; i <= MAX; i += term)
        {
            for(int j = i; j <= i + range - 1; ++j)
                count[j]++;
        }      
    }
    
    for(int i = 0; i <= MAX; ++i)
    {  
        if(count[i] == signals.size()) 
            return i;
    }
    
    return -1;
}
