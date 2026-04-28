#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
//     int i = my_string.size() - 1, j = is_suffix.size() - 1;
    
//     if(i < j) return 0;
    
//     while(i >= 0 && j >= 0)
//     {
//         if(my_string[i] == is_suffix[j])
//         {
//             i--;
//             j--;
//         }
//         else return 0;
//     }
    
//     return 1;
    
    if(my_string.size() < is_suffix.size()) return 0;
    return my_string.substr(my_string.size() - is_suffix.size()) == is_suffix;
}
