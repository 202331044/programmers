#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& discounts, 
         vector<vector<int>>& users, 
         vector<vector<int>>& discounted_prices, 
         vector<int>& answer, 
         vector<int>& discount_rates)
{
    if(discounts.size() == discounted_prices.size())
    {
        int total_cnt = 0, total_price = 0;
        
        for(auto& user: users)
        {
            int price = 0;
            int min_discount = user[0];
            int target_price = user[1];
            
            for(int j = 0; j < discounted_prices.size(); ++j)
                if(min_discount <= discounts[j]) 
                    price += discounted_prices[j][(discounts[j] / 10 - 1)];
            
            if(price >= target_price) total_cnt++;
            else total_price += price;
        }
        
        if((total_cnt > answer[0]) || 
           (total_cnt == answer[0] && total_price > answer[1]))
        {
            answer[0] = total_cnt;
            answer[1] = total_price;
        }
        
        return;
    }
    
    for(int rate: discount_rates)
    {
        discounts.push_back(rate);
        dfs(discounts, users, discounted_prices, answer, discount_rates);
        discounts.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<vector<int>> discounted_prices;
    
    for(int price: emoticons)
    {
        int a = price  - (price * 1 / 10);
        int b = price  - (price * 2 / 10);
        int c = price  - (price * 3 / 10);
        int d = price  - (price * 4 / 10);

        discounted_prices.push_back({a, b, c, d});
    }
    
    vector<int> discounts;
    vector<int> answer = {0, 0};
    vector<int> discount_rates = {10, 20, 30, 40};
        
    dfs(discounts, users, discounted_prices, answer, discount_rates);

    return answer;
}
