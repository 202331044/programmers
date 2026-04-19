#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {

    int meat = n * 12000;
    int drink = (k - n / 10) * 2000;

    return meat + drink;
}