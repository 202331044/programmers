#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int answer = 0;
    int n = A.size();
    
    for(int i = 0; i < n; ++i)
        answer += A[i] * B[n - i - 1];
    
    return answer;
}
