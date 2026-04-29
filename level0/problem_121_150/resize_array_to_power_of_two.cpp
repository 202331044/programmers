#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int size = arr.size();
    
    for(int i = 1; ; i *= 2)
    {
        if(size == i) return arr;
        if(size < i)
        {
            arr.resize(i);
            return arr;
        }
    }
}
