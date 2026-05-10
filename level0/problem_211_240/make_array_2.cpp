#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;

    for (int i = 5; i <= r; i += 5)
    {
        string str = to_string(i);
        bool valid = true;

        for (char ch : str)
        {
            if (ch != '0' && ch != '5')
            {
                valid = false;
                break;
            }
        }

        if (valid && i >= l) answer.push_back(i);
    }

    if (answer.empty()) return { -1 };
    return answer;
}