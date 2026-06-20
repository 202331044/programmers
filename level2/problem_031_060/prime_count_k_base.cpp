#include <string>
#include <algorithm>

using namespace std;

string make_kth(int n, int k)
{
    string str;
    
    while(n)
    {
        str += (n % k) + '0';
        n /= k;
    }
    
    reverse(str.begin(), str.end());
    
    return str;
}

bool isPrime(long long num)
{   
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    
    for(long long i = 3; i * i <= num; ++i)
        if(num % i == 0) return false;

    return true;
}

int solution(int n, int k) {
    string str = make_kth(n, k);
    string number;
    int answer = 0;
    
    for(char ch: str)
    {
        if(ch == '0')
        {
            if(!number.empty() && isPrime(stoll(number)))
                answer++;
            
            number.clear();
        }
        else
            number += ch;
    }
    
    if(!number.empty() && isPrime(stoll(number)))
        answer++;
    
    return answer;
}
