#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    //int answer = 0;
    
    // for(int i = 0; i < a.size(); ++i)
    //     answer += a[i] * b[i];
    
    //return answer;
    
    return inner_product(a.begin(), a.end(), b.begin(), 0);
}
