#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    //     int h = park.size();
    //     int w = park[0].size();

    //     int x, y;
    //     bool isStop = false;

    //     for(int r = 0; r < h; ++r)
    //     {
    //         for(int c = 0; c < w; ++c)
    //         {
    //             if(park[r][c] == 'S')
    //             {
    //                 y = r;
    //                 x = c;
    //                 isStop = true;
    //                 break;
    //             }
    //         }
    //         if(isStop) break;
    //     }

    //     for(const string& route: routes)
    //     {
    //         char op = route[0];
    //         int dist = route[2] - '0';

    //         if(op == 'E')
    //         {
    //             if(x + dist < w)
    //             {
    //                 bool go = true;
    //                 for(int dc = x; dc <= x + dist; ++dc)
    //                 {
    //                     if(park[y][dc] == 'X')
    //                     {
    //                         go = false;
    //                         break;
    //                     }
    //                 }
    //                 if(go) x += dist;
    //             }
    //         }
    //         else if(op == 'W')
    //         {
    //             if(x - dist >= 0)
    //             {
    //                 bool go = true;
    //                 for(int dc = x; dc >= x - dist; --dc)
    //                 {
    //                     if(park[y][dc] == 'X')
    //                     {
    //                         go = false;
    //                         break;
    //                     }
    //                 }
    //                 if(go) x -= dist;
    //             }
    //         }
    //         else if(op == 'S')
    //         {
    //             if(y + dist < h)
    //             {
    //                 bool go = true;
    //                 for(int dr = y; dr <= y + dist; ++dr)
    //                 {
    //                     if(park[dr][x] == 'X')
    //                     {
    //                         go = false;
    //                         break;
    //                     }
    //                 }
    //                 if(go) y += dist;
    //             }
    //         }
    //         else if(op == 'N')
    //         {
    //             if(y - dist >= 0)
    //             {
    //                 bool go = true;
    //                 for(int dr = y; dr >= y - dist; --dr)
    //                 {
    //                     if(park[dr][x] == 'X')
    //                     {
    //                         go = false;
    //                         break;
    //                     }
    //                 }
    //                 if(go) y -= dist;
    //             }
    //         }
    //     }

    //     return {y, x};

    int h = park.size();
    int w = park[0].size();

    int x, y;
    bool isStop = false;

    for (int r = 0; r < h; ++r)
    {
        for (int c = 0; c < w; ++c)
        {
            if (park[r][c] == 'S')
            {
                y = r;
                x = c;
                isStop = true;
                break;
            }
        }
        if (isStop) break;
    }

    int dx[128] = {};
    int dy[128] = {};
    dx['E'] = 1;
    dx['W'] = -1;
    dy['S'] = 1;
    dy['N'] = -1;

    for (const string& route : routes)
    {
        char op = route[0];
        int dist = route[2] - '0';

        int cx = x;
        int cy = y;

        for (int i = 1; i <= dist; ++i)
        {
            cx += dx[op];
            cy += dy[op];

            if (cx < 0 || cx >= w || cy < 0 || cy >= h || park[cy][cx] == 'X')
            {
                cx = x;
                cy = y;
                break;
            }
        }

        x = cx;
        y = cy;
    }

    return { y, x };
}