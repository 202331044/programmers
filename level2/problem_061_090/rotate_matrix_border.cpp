#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> rotation(rows, vector<int>(columns, 0));
    int num = 1;
    
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < columns; ++j)
            rotation[i][j] = num++;
    
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    
    vector<int> answer;
    
    for(auto query: queries)
    {
        int x1 = query[0] - 1;
        int y1 = query[1] - 1;
        int x2 = query[2] - 1;
        int y2 = query[3] - 1;
        
        int tmp = rotation[x1][y1];
        int minVal = tmp;
        int x = x1;
        int y = y1;
        
        for(int i = 0; i < 4; ++i)
        {
            x += dr[i];
            y += dc[i];
            
            while(x >= x1 && x <= x2 && y >= y1 && y <= y2)
            {
                swap(tmp, rotation[x][y]);
                minVal = min(tmp, minVal);
                
                x += dr[i];
                y += dc[i];
            }
            
            x -= dr[i];
            y -= dc[i];
        }

        answer.push_back(minVal);
    }

    return answer;
}
