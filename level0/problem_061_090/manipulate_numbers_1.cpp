#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
//     for(char ch: control)
//     {
//         if(ch == 'w') n++;
//         else if(ch == 's') n--;
//         else if(ch == 'd') n += 10;
//         else n -= 10;
//     }
    
    for(char ch: control)
    {
        switch(ch)
        {
            case 'w': n++; break;
            case 's': n--; break;
            case 'd': n += 10; break;
            case 'a': n -= 10; break;
        }
    }
    
    return n;
}
