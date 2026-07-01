#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> inout, times;
    
    for(string& record: records)
    {
        istringstream iss(record);
        string time, number, state;
        iss >> time >> number >> state;
        
        int t = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
        
        if(state == "IN")
            inout[number] = t;
        else
        {
            times[number] += t - inout[number];
            inout[number] = -1;
        }
    }
    
    int endTime = 23 * 60 + 59;
    vector<int> answer;
    
    for(auto& it: inout)
    {
        if(it.second != -1)
            times[it.first] += endTime - it.second;
        
        int fee = fees[1];
        if(times[it.first] > fees[0])
            fee +=  (times[it.first] - fees[0] + fees[2] - 1) / fees[2] * fees[3];
        
        answer.push_back(fee);
    }
    
    return answer;
}
