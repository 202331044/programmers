#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isPrime(int num)
{     
    if(num < 2) 
        return false;
    
    for(int i = 2; i * i <= num; ++i)
    {
        if(num % i == 0)
            return false;
    }
    
    return true;   
}

void dfs(int num, const string& numbers, vector<bool>& visited, 
         unordered_set<int>& primes)
{
    if(isPrime(num)) 
        primes.insert(num);

    for(int i = 0; i < numbers.size(); ++i)
    {
        if(visited[i]) continue;
        
        if(i > 0 && numbers[i - 1] == numbers[i] && !visited[i - 1])
            continue;

        visited[i] = true;
        dfs(num * 10 + (numbers[i] - '0'), numbers, visited, primes);
        visited[i] = false;
    }
}

int solution(string numbers) {
    sort(numbers.begin(), numbers.end());
    
    unordered_set<int> primes;
    vector<bool> visited(numbers.size(), false);
    
    dfs(0, numbers, visited, primes);
    
    return primes.size();
}
