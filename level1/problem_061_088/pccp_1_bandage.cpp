#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int preTime = 0;
    int range = bandage[0], rate = bandage[1], extra = bandage[2];
    int curHealth = health;
    
    for(auto& attack: attacks)
    {
        int curTime = attack[0];
        int damage = attack[1];
        int healTime = (curTime - preTime - 1);
        
        curHealth += (healTime * rate) + (healTime / range * extra);
        curHealth = min(curHealth, health);
        curHealth -= damage;
        
        if(curHealth <= 0) return -1;
        
        preTime = curTime;
    }
    
    return curHealth;
}
