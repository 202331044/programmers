#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
//     sort(A.rbegin(), A.rend());
//     sort(B.rbegin(), B.rend());
    
//     int answer = 0;
    
//     int startA = 0;
//     int startB = 0;
//     int endA = A.size() - 1;
//     int endB = B.size() - 1;
    
//     while(startA <= endA && startB <= endB)
//     {
//         if(A[startA] < B[startB])
//         {
//             answer++;
//             startA++;
//             startB++;
//         }
//         else
//         {
//             startA++;
//             endB--;
//         }
//     }
    
//     return answer;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int idxA = 0;
    int idxB = 0;
    
    int answer = 0;
    
    while(idxA < A.size() && idxB < B.size())
    {
        if(A[idxA] < B[idxB])
        {
            answer++;
            idxA++;
            idxB++;
        }
        else
            idxB++;
    }
    
    return answer;
}
