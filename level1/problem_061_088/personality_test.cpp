#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer;
    map<char, int> m;
    
    for(int i = 0; i < survey.size(); ++i)
    {
        char a = survey[i][0], b = survey[i][1];
        int choice = choices[i];
        
        switch (choice)
        {
            case 1: m[a] += 3; break;
            case 2: m[a] += 2; break;
            case 3: m[a] += 1; break;
            case 5: m[b] += 1; break;
            case 6: m[b] += 2; break;
            case 7: m[b] += 3; break;
        } 
    }
    
    answer += m['R'] >= m['T'] ? 'R' : 'T';
    answer += m['C'] >= m['F'] ? 'C' : 'F';
    answer += m['J'] >= m['M'] ? 'J' : 'M';
    answer += m['A'] >= m['N'] ? 'A' : 'N';

    return answer;
}
