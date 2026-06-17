#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void make_words(const string& target, string cur, int& answer, int& cnt)
{
    if(answer != 0)
        return;
    
    if(!cur.empty())
    {
        cnt++;
        
        if(cur == target)
        {
            answer = cnt;
            return;
        }
    }
    
    if(cur.size() == 5)
        return;
    
    string str = "AEIOU";
    for(char ch: str)
        make_words(target, cur + ch, answer, cnt);
}

int solution(string word) {
//     int answer = 0, cnt = 0;
//     make_words(word, "", answer, cnt);
    
//     return answer;
   
    vector<int> weight = {781, 156, 31, 6, 1};
    string str = "AEIOU";
    int answer = 0;
    
    for(int i = 0; i < word.size(); ++i)
    {
        int idx = str.find(word[i]);
        answer += weight[i] * idx + 1;
    }
        
    return answer;
}
