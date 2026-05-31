#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> names;
    vector<string> numbers(players.size());
    
    for(int i = 0; i < players.size(); ++i)
    {
        names[players[i]] = i + 1;
        numbers[i] = players[i];
    }
        
    for(const string& name1: callings)
    {
        int num1 = names[name1];
        string name2 = numbers[num1 - 2];
        
        names[name1]--;
        swap(numbers[num1 - 1], numbers[num1 - 2]);
        names[name2]++;
    }
    
    return numbers;
}
