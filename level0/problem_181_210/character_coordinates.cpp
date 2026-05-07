#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    int h = board[1] / 2, w = board[0] / 2;
    int x = 0, y = 0;
    
    for(const string& key: keyinput)
    {
        
        if(key == "up" && y + 1 <= h) y++;
        else if(key == "down" && y - 1 >= -h) y--;
        else if(key == "right" && x + 1 <= w) x++;
        else if(key == "left" && x - 1 >= -w) x--;
    }
    
    return {x, y};
}
