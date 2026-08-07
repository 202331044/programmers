#include <string>
#include <vector>

using namespace std;

void hanoi_tower(vector<vector<int>>& answer, int n, int src, int tmp, int dst)
{
    if(n == 1)
    {
        answer.push_back({src, dst}); 
        return;
    }
        
    hanoi_tower(answer, n - 1, src, dst, tmp);
    answer.push_back({src, dst});
    hanoi_tower(answer, n - 1, tmp, src, dst);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi_tower(answer, n, 1, 2, 3);
    return answer;
}
