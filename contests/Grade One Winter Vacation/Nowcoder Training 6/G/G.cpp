#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>

using namespace std;
using longs = long long;
using uint = unsigned;

inline int nextInt()
{
    int x = 0, f = 1, ch = getchar();
    while (!isdigit(ch)) if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

const int N = 250;
int h[N][N], v[N][N];

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t, n, k;
    cin >> t;
    while (t --)
    {
        cin >> n >> k;
        const auto all = 2 * n * (n + 1);
        if (all % k || k == 1) {cout << -1 << endl; continue;}
        int cnt = 0, dir = 0, xx = 2 * n + 1;
        while (cnt < all)
        {
            if (!dir)
            {
                auto row = cnt / xx;
                for (int j = 0; j < n; ++ j)
                    h[row][j] = (cnt ++) % k + 1;
            }
            else
            {
                auto col = cnt / xx;
                for (int i = 0; i <= n; ++ i)
                    v[i][col] = (cnt ++) % k + 1;
            }
            dir = dir ? 0 : 1;
        }
        
        for (int i = 0; i <= n; ++ i)
        {
            for (int j = 0; j < n; ++ j)
                cout << h[i][j] << ' ';
            cout << endl;
        }
        for (int i = 0; i <= n; ++ i)
        {
            for (int j = 0; j < n; ++ j)
                cout << v[i][j] << ' ';
            cout << endl;
        }
        
        /*
        for(int i = 0; i <= n; ++i)
        {
            printf(" ");
            for (int j = 0; j < n; ++ j)
                cout << h[i][j] << ' ';
            cout << endl;
            if(i == n) break;
            for (int j = 0; j <= n; ++ j)
                cout << v[j][i] << ' ';
            cout << endl;
        }
        */
    }


    return 0;
}