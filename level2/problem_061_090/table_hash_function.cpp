#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    sort(data.begin(), data.end(), [col](const vector<int>& a, const vector<int>& b)
         {
             if(a[col - 1] != b[col - 1]) return a[col - 1] < b[col - 1];
             return a[0] > b[0];
         });

    int answer = 0;
    
    for(int idx = row_begin - 1; idx < row_end; ++idx)
    {
        int tmp = 0;
       
        for(int x: data[idx])
            tmp += x % (idx + 1);

        answer ^= tmp;
    }
    
    return answer;
}
