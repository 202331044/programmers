#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int idx = my_string.find(is_prefix);
    
    return idx == 0;
}
