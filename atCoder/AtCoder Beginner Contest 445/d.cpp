#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int H, W, N;
    cin >> H >> W >> N;

    vector<pii> piece;
    map<int, map<int, bool>> heights, widths;
    for(int i = 0; i < N; i++)
    {
        int h, w;
        cin >> h >> w;

        piece.emplace_back(h, w);
        heights[h][i] = true;
        widths[w][i] = true;
    }

    int ans_h = 1, ans_w = 1;
    vector<pii> ans(N);

    int iter = 1;
    while(iter++ <= N)
    {
        if(heights[H].size() > 0)
        {
            int i = heights[H].begin()->first;
            auto [h, w] = piece[i];

            heights[h].erase(i);
            widths[w].erase(i);

            ans[i] = {ans_h, ans_w};
            ans_w += w;

            W -= w;
        }
        else
        {
            int i = widths[W].begin()->first;
            auto [h, w] = piece[i];

            heights[h].erase(i);
            widths[w].erase(i);

            ans[i] = {ans_h, ans_w};
            ans_h += h;

            H -= h;
        }
    }

    for(auto [h, w] : ans)
        cout << h << ' ' << w << '\n';

    return 0;
}
