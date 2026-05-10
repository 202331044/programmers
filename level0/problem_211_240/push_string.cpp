#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
//     for(int i = A.size(); i >= 0; --i)
//     {
//         string tmp = A.substr(i) + A.substr(0, i);
        
//         if(B == tmp) return (A.size() - i);
//     }
    
    for(int i = 0; i < A.size(); ++i)
    {
        string tmp = A.substr(A.size() - i) + A.substr(0, A.size() - i);
        
        if(B == tmp) return i;
    }
    
    return -1;
}
