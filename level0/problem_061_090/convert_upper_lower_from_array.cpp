#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> solution(vector<string> strArr) {;
    
    vector<string> answer;
                            
    for(int i = 0; i < strArr.size(); ++i)
    {
        string str = strArr[i];
        transform(str.begin(), str.end(), str.begin(), [i](char ch)
              {
                  if(i % 2 == 0) return tolower(ch);
                  else return toupper(ch);
                  
              });
        // if(i % 2 == 0)
        // {
        //     transform(str.begin(), str.end(), str.begin(), [](char ch)
        //       {
        //           return tolower(ch);
        //       });
        // }
        // else 
        // {
        //     transform(str.begin(), str.end(), str.begin(), [](char ch)
        //     {
        //         return toupper(ch);
        //     });
        // }
        answer.push_back(str);
    }
                                                
    return answer;
}
