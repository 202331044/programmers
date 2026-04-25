#include <string>
#include <vector>
#include<algorithm>
#include <cctype>

using namespace std;

int solution(string myString, string pat) {
    transform(myString.begin(), myString.end(), myString.begin(), [](char ch)
              {
                  return tolower(ch);
              });
    
    transform(pat.begin(), pat.end(), pat.begin(), [](char ch)
              {
                  return tolower(ch);
              });
    
    return myString.find(pat) != string::npos;
}
