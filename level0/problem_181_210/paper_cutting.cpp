#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    // if(M == 1 && N == 1) return 0;
    // else if(M < N) return (M-1) + M * (N-1);
    // else return (N-1) + N * (M-1);
    
    return N*M - 1;
}
