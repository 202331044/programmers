#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string id = id_pw[0], pw = id_pw[1];
    
//     int i = 0;
//     for(auto data: db)
//     {
//         if(id == data[0] && pw == data[1]) return "login";
//         else if(id == data[0] && pw != data[1]) i = 1;
//     }
    
//     if(i == 1) return "wrong pw";
//     return "fail";
    
    for(const auto& data: db)
    {
        if(id == data[0])  
        {
            if(pw == data[1]) return "login";
            else return "wrong pw";
        }
    }
    
    return "fail";
}
