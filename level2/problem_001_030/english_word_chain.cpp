#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    if(words[0].size() == 1) 
        return {1, 1};
    
    unordered_set<string> s;
    s.insert(words[0]);
    
    for(int i = 1; i < words.size(); ++i)
    {
        string word = words[i];
        
        if(word.size() == 1 || 
          (words[i - 1].back() != word.front()) ||
          (s.find(word) != s.end()))
        {
            return {i % n + 1, i / n + 1};
        }

        s.insert(word);
    }
           
    return {0, 0};
}
