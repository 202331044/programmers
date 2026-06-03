#include <string>
#include <vector>

using namespace std;

int getTime(string& str)
{
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int curPos = getTime(pos);
    int len = getTime(video_len);
    int start = getTime(op_start);
    int end = getTime(op_end);

    for(const string& command: commands)
    {
        if(curPos >= start && curPos <= end) curPos = end;
        
        if(command == "next") curPos = min(curPos + 10, len);
        else if(command == "prev") curPos = max(curPos - 10, 0);
    }
    
    if(curPos >= start && curPos <= end) curPos = end;
    
    string minutes = to_string(curPos / 60);
    string seconds = to_string(curPos % 60);
    
    if(minutes.size() == 1) minutes = '0' + minutes;
    if(seconds.size() == 1) seconds = '0' + seconds;
    
    return minutes + ":" + seconds;
}
