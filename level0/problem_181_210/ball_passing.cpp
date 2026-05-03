#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    //vector<int> order;
    //int n = numbers.size();

    //for (int i = 0; i < n; i += 2)
    //    order.push_back(numbers[i]);

    //if (n % 2 != 0)
    //{
    //    for (int j = 1; j < n; j += 2)
    //        order.push_back(numbers[j]);
    //}

    //if (order.size() >= k) return order[k - 1];
    //return order[(k - 1) % order.size()];

     int idx = 2 * (k-1) % numbers.size();
     return numbers[idx];
}