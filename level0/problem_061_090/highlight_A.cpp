#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string myString) {
    
    transform(myString.begin(), myString.end(), myString.begin(), [](char ch)
          {
              if(ch == 'a') return 'A';
              if (ch != 'A' && isupper(ch)) return static_cast<char>(tolower(ch));
              return ch;
          });
    
    return myString;
}
