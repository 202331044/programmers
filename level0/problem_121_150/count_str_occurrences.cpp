#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int cnt = 0;
    
//     for(int i = 0; i < myString.size(); ++i)
//     {
//         if(myString[i] == pat.front())
//         {
//             int j = i, tmp = 0;
            
//             for(char ch: pat)
//             {
//                 if(j >= myString.size() || myString[j++] != ch) 
//                     break;
//                 tmp++;
//             }
            
//             if(tmp == pat.size()) cnt++;
//         }
//     }
    
    int size = pat.size();
    
    for(int i = 0; i < myString.size() - (size - 1); ++i)
        if(myString.substr(i, size) == pat) cnt++;
    
    return cnt;
}
