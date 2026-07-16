#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    //     vector<vector<int>> vec(n, vector<int>(n, 0));
    //     const int MAX = n % 2 == 0 ? (n + 1) * (n / 2) : (n + 1) * (n / 2) + (n + 1) / 2;
    //     int cnt = 1;
    //     int r = 0, c = 0;

    //     while(cnt <= MAX)
    //     {
    //         while(r >= 0 && r < n && c >= 0 && c < n)
    //         {
    //             if(vec[r][c] != 0)
    //                 break;

    //             vec[r++][c] = cnt++;
    //         }

    //         r--;
    //         c++;

    //         while(r >= 0 && r < n && c >= 0 && c < n)
    //         {
    //             if(vec[r][c] != 0)
    //                 break;

    //             vec[r][c++] = cnt++;
    //         }

    //         c -= 2;
    //         r--;

    //         while(r >= 0 && r < n && c >= 0 && c < n)
    //         {
    //             if(vec[r][c] != 0)
    //             {
    //                 r += 2;
    //                 c++;
    //                 break;
    //             }
    //             vec[r--][c--] = cnt++;
    //         }
    //     }

    vector<vector<int>> vec(n, vector<int>(n, 0));
    const int MAX = n * (n + 1) / 2;
    int cnt = 1;
    int r = 0, c = 0;
    int dr[3] = { 1, 0, -1 };
    int dc[3] = { 0, 1, -1 };
    int idx = 0;

    while (cnt <= MAX)
    {
        vec[r][c] = cnt++;

        int nr = r + dr[idx];
        int nc = c + dc[idx];

        if (nr < 0 || nr >= n || nc < 0 || nc >= n || vec[nr][nc] != 0)
        {
            idx = (idx + 1) % 3;
            nr = r + dr[idx];
            nc = c + dc[idx];
        }

        r = nr;
        c = nc;
    }

    vector<int> answer;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            answer.push_back(vec[i][j]);

    return answer;
}