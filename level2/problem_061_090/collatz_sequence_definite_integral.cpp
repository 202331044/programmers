#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<int> ys;
    
    while(k > 1)
    {
        ys.push_back(k);
        
        if(k % 2 == 0) k /= 2;
        else k = k * 3 + 1;
    }
    ys.push_back(1);
    
    vector<double> area;
    
    for(int i = 0; i < ys.size() - 1; ++i)
    {
//         int x1 = i, y1 = ys[i];
//         int x2 = i + 1, y2 = ys[i + 1];
//         int x3 = i + 1, y3 = 0;
//         int x4 = i, y4 = 0;
        
//         double tmp = abs((x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1) - 
//                          (y1 * x2 + y2 * x3 + y3 * x4 + y4 * x1));
//         double num = tmp / 2;
        
        double num = (ys[i] + ys[i + 1]) / 2.0; 
        area.push_back(num);
    }
    
    int n = ys.size() - 1;
    vector<double> answer;
    
    for(auto& range: ranges)
    {
        double sum = 0;

        if(range[0] > n + range[1])
            sum = -1;
        else
        {
            for(int i = range[0]; i < n + range[1]; ++i)
                sum += area[i];
        }
        
        answer.push_back(sum);
    }
    
    return answer;
}
