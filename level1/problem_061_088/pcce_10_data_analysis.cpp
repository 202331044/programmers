#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getIdx(string& str)
{
    if(str == "code") return 0;
    else if(str == "date") return 1;
    else if(str == "maximum") return 2;
    else return 3;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int idx1 = getIdx(ext);
    int idx2 = getIdx(sort_by);
    
    for(int i = 0; i < data.size(); ++i)
    {
        if(data[i][idx1] < val_ext) answer.push_back(data[i]);
    }
    
    sort(answer.begin(), answer.end(), [idx2](const vector<int>& a, const vector<int>& b)
         {
             return a[idx2] < b[idx2];
         });
    
    return answer;
}
