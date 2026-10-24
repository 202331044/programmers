#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    const int INF = 1000000000;
        
//     vector<int> left_to_right(a.begin(), a.end());
//     vector<int> right_to_left(a.begin(), a.end());
    
//     int left_min = INF;
//     int right_min = INF;
    
//     for(int i = 0; i < n; ++i)
//     {
//         if(a[i] <= left_min)
//             left_min = a[i];
//         else
//             left_to_right[i] = left_min;
        
//         if(a[n - i - 1] <= right_min)
//             right_min = a[n - i - 1];
//         else
//             right_to_left[n - i - 1] = right_min;
//     }
    
//     int answer = 0;
    
//     for(int i = 0; i < n; ++i)
//         if(a[i] <= left_to_right[i] || a[i] <= right_to_left[i])
//             answer++;

//     return answer;
    
    vector<int> right_to_left(a.begin(), a.end());
    int right_min = right_to_left[n - 1];
    
    for(int i = n - 1; i >= 0; --i)
    {
        right_min = min(right_min, right_to_left[i]);
        right_to_left[i] = right_min;
    }
    
    int left_min = a[0];
    int answer = 0;
    
    for(int i = 0; i < n; ++i)
    {
        left_min = min(a[i], left_min);
        
        if(a[i] <= left_min || a[i] <= right_to_left[i])
            answer++;
    }
    
    return answer;
}
