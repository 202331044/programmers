#include <string>
#include <vector>

using namespace std;
void dfs(int& answer, int cnt, const int& size, vector<bool>& visited,
         string begin, const string& target, vector<string>& words)
{
    if(begin == target)
    {
        answer = min(answer, cnt);
        return;
    }
    
    for(int i = 0; i < size; ++i)
    {
        for(int idx = 0; idx < words.size(); ++idx)
        {
            if(visited[idx] == true)
                continue;
            
            bool check = true;
            for(int j = 0; j < size; ++j)
            {
                if((i == j && begin[j] == words[idx][j]) ||
                   (i != j && begin[j] != words[idx][j]))
                {
                    check = false;
                    break;
                }
            }
            
            if(check)
            {
                string str = begin;
                str[i] = words[idx][i];
                visited[idx] = true;
                
                dfs(answer, cnt + 1, size, visited, str, target, words);
                
                visited[idx] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = words.size();
    int size = begin.size();
    vector<bool> visited(words.size(), false);
    
    dfs(answer, 0, size, visited, begin, target, words);
    
    if(answer == words.size()) answer = 0;
    
    return answer;
}
