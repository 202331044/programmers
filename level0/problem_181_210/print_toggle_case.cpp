#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(char& ch: str)
    {
        if(isupper(ch)) ch = tolower(ch);
        else ch = toupper(ch);
    }
    
    cout << str;
    
    return 0;
}
