#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    transform(my_string.begin(), my_string.end(), my_string.begin(), [](char ch)
              {
                  return tolower(ch);
              });
    
    sort(my_string.begin(), my_string.end());
    
    return my_string;
}
