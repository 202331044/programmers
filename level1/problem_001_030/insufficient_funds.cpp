using namespace std;

long long solution(int price, int money, int count)
{   
//     long long answer = money;
    
//     for(int i = 1; i <= count; ++i)
//         answer -= price * i;
    
//     return (answer < 0) ? -answer : 0;
    
    //long long answer = (static_cast<long long>(price) + (price * count)) * count / 2;
    
    long long answer = (long long)price * count * (count + 1) / 2;
    return answer > money ? answer - money : 0;
}
