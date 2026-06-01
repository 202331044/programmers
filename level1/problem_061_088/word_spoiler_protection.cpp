#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    vector<int> check(message.size(), 0);
    unordered_set<string> noSpoiler, spoiler;    
    
    for(auto& range: spoiler_ranges)
    {
        int s = range[0], e = range[1];
        
        for(int i = s; i <= e; ++i)
            check[i] = 1;
    }
    
    string word;
    bool isSpoiler = false;
    
    for(int i = 0; i < message.size(); ++i)
    {
        if(message[i] == ' ')
        {
            if(isSpoiler) spoiler.insert(word);
            else noSpoiler.insert(word);
            word.clear();
            isSpoiler = false;
        }
        else
            word += message[i];
        
        if(message[i] != ' ' && check[i] == 1) isSpoiler = true;
    }
    
    if(isSpoiler) spoiler.insert(word);
    else noSpoiler.insert(word);    
    
    for(const string& tmp: spoiler)
    {
        if(noSpoiler.find(tmp) == noSpoiler.end()) 
            answer++;
    }
        
    return answer;
}
