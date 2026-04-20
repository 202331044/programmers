#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string vowel = "aeiou";
    // for(char c: vowel)
    //     my_string.erase(remove(my_string.begin(), my_string.end(), c), my_string.end());
    
    my_string.erase(remove_if(my_string.begin(), my_string.end(), [&](char c)
                  {
                    return vowel.find(c) != string::npos;
                  }), my_string.end());
    return my_string;
}
