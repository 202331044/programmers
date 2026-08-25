#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int compareName(const int nextPos, string& name, string& curName)
{
    if(curName[nextPos] != name[nextPos])
    {
        curName[nextPos] = name[nextPos];
        return min('Z' - name[nextPos] + 1, name[nextPos] - 'A');;
    }
    
    return 0;
}

void dfs(int& answer, int pos, int cnt, const int size, 
         string& name, string& curName)
{
    if(cnt > answer)
        return;
    
    if(name == curName)
    {
        answer = min(cnt, answer);
        return;
    }
    
    int nextPos;
    int plus;
    for(int i = 0; i < size; ++i)
    {
        nextPos = (pos + i) % size;
        plus = compareName(nextPos, name, curName);
        
        if(plus)
        {
            dfs(answer, nextPos, cnt + i + plus, size, name, curName);
            curName[nextPos] = 'A';
        }
        
        nextPos = (pos - i) < 0 ? size + (pos - i) : pos - i;
        plus = compareName(nextPos, name, curName);
        
        if(plus)
        {
            dfs(answer, nextPos, cnt + i + plus, size, name, curName);
            curName[nextPos] = 'A';
        }
    }
}
    
int solution(string name) {    
//     int answer = 20 * 26;
//     int pos = 0;
//     int cnt = 0;
//     int size = name.size();
    
//     string curName = string(size, 'A');
    
//     dfs(answer, pos, cnt,  size, name, curName);
    
    int answer = 0;
    for(char ch: name)
        if(ch != 'A')
            answer += min(ch - 'A', 'Z' - ch + 1);
    
    int size = name.size();
    int move = size - 1;
    
    for(int pos = 0; pos < size; ++pos)
    {
        int nextPos = pos + 1;
        
        while(nextPos < size && name[nextPos] == 'A')
            nextPos++;
        
        int rl = 2 * pos + size - nextPos;
        int lr = 2 * (size - nextPos) + pos;
        
        move = min({move, rl, lr});
    }
    
    answer += move;
    return answer;
}
