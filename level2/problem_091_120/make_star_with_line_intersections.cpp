#include <string>
#include <vector>

using namespace std;
using ll = long long;

vector<string> solution(vector<vector<int>> line) {
    
    vector<pair<ll, ll>> points;
    
    for(int i = 0; i < line.size() - 1; ++i)
    {
        ll a = line[i][0];
        ll b = line[i][1];
        ll e = line[i][2];
        
        for(int j = i + 1; j < line.size(); ++j)
        {
            ll c = line[j][0];
            ll d = line[j][1];
            ll f = line[j][2];
            
            ll term1 = b * f - e * d;
            ll term2 = e * c - a * f;
            ll div = a * d - b * c;
            
            if(div != 0 && term1 % div == 0 && term2 % div == 0)
                points.push_back({term1/div, term2/div});
        }
    }
    
    ll maxx = points[0].first;
    ll minx = points[0].first;
    ll maxy = points[0].second;
    ll miny = points[0].second;
    
    for(const auto& [x, y]: points)
    {
        if(maxx < x) maxx = x;
        if(minx > x) minx = x;
        if(maxy < y) maxy = y;
        if(miny > y) miny = y;
    }

    int h = maxy - miny + 1;
    int w = maxx - minx + 1;
    
    vector<string> answer(h, string(w, '.'));
    
    for(const auto& [x, y]: points)
        answer[maxy - y][x - minx] = '*';

        
    return answer;
}
