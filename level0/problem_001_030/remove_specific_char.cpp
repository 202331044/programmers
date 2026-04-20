#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    //     while(my_string.find(letter) != string::npos)
    //     {
    //         int idx = my_string.find(letter);

    //         my_string.erase(idx, letter.size());
    //     }      

    string answer;

    for (char c : my_string)
        if (c != letter[0]) answer.push_back(c);

    return answer;
}