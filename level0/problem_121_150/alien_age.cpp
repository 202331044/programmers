#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int age) {
    string answer = "";
    string str = to_string(age);
    
    for(char ch: str)
        answer += ch - '0' + 'a';
    
    return answer;
}
