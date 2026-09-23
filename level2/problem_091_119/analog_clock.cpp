#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int start = h1 * 60 * 60 + m1 * 60 + s1;
    int end = h2 * 60 * 60 + m2 * 60 + s2;
    
    int startM = ceil(double(start * 59) / 3600);
    int endM = floor(double(end * 59) / 3600);
    int startH = ceil(double(start * 719) / 43200);
    int endH = floor(double(end * 719) / 43200);
    
    int answer = endH - startH + endM - startM + 2;
    
    if(start == 0) answer--;
    if(start <= 12 * 60 * 60 && end >= 12 * 60 * 60) answer--;
    
    return answer;
}
