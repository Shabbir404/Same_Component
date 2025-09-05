#include <bits/stdc++.h>
using namespace std;

int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

int main()
{
    int a, b;
    cin >> a >> b;

    vector<string> grid(a);
    for (int i = 0; i < a; i++)
    {
        cin >> grid[i];
    }

    int xx, yy;
    cin >> xx >> yy;
    int x2, y2;
    cin >> x2 >> y2;

    vector<vector<bool>> vis(a, vector<bool>(b, false));

    queue<pair<int, int>> q;

    q.push({xx, yy});
    vis[xx][yy] = true;

    bool flag = false;

    while (!q.empty())
    {
        auto [xz, yz] = q.front();
        q.pop();
        if (xz == x2 && yz == y2)
        {
            cout << "YES" << endl;
            flag = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int xp = xz + x[i];
            int yp = yz + y[i];

            if (xp >= 0 && xp < a && yp >= 0 && yp < b && !vis[xp][yp] && grid[xp][yp] == '.')
            {
                vis[xp][yp] = true;
                q.push({xp, yp});
            }
        }
    }

    if (!flag)
        cout << "NO";


    return 0;
}
