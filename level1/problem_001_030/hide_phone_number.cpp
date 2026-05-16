#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string phone_number) {
    // for(int i = 0; i < phone_number.size() - 4; ++i)
    //     phone_number[i] = '*';
    
    fill(phone_number.begin(), phone_number.end() - 4, '*');
    
    return phone_number;
}
