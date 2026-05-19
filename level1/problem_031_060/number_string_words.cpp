#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>

using namespace std;

int solution(string s) {
    unordered_map<string, char> words = {{"zero", '0'}, {"one", '1'},
                                         {"two", '2'}, {"three", '3'},
                                         {"four", '4'}, {"five", '5'},
                                         {"six", '6'}, {"seven", '7'},
                                         {"eight", '8'}, {"nine", '9'}};
    
    string answer, word;   
    for(char& ch: s)
    {
        if(isdigit(ch)) answer += ch;
        else word += ch;
        
        auto it = words.find(word);
        if(!word.empty() && it != words.end()) 
        {
            answer += words[word];
            word.clear();
        }
    }
    
    return stoi(answer);
}
