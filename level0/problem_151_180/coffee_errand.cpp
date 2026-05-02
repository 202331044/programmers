#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int price = 0;
    
    for(const string& str: order)
    {
        if(str.find("cafelatte") != string::npos) price += 5000;
        else price += 4500;
    }
                
    return price;
}
