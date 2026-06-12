#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
//     unordered_set<string> s;
//     sort(phone_book.begin(), phone_book.end(), 
//          [](const string& a, const string& b)
//          {
//              return a.size() < b.size();
//          });
    
//     for(string& str: phone_book)
//     {
//         if(s.empty())
//             s.insert(str);
//         else
//         {
//             for(int i = 1; i <= str.size(); ++i)
//             {
//                 if(s.count(str.substr(0, i)))
//                     return false;
//             }
//         }
        
//         s.insert(str);
//     }
    
//     return true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size() - 1; ++i)
    {
        int idx = phone_book[i + 1].find(phone_book[i]);
        if(idx == 0)
            return false;
    }
    
    return true;
}
