#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;

    for (auto h : array)
        if (h > height) answer++;

    return answer;
}