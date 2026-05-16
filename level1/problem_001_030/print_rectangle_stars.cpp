#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    
    for(int i = 0; i < b; ++i)
    {
        cout << string(a, '*') << '\n';
        // for(int j = 0; j < a; ++j)
        //     cout << '*';
        //  cout << '\n';
    }
        
    return 0;
}
