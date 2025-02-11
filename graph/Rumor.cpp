#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MAX_SIZE = 100005;
vector<ll> edge[MAX_SIZE];
ll visit[MAX_SIZE];
const ll template_size = 1e6 + 4832;
ll a[template_size];

ll dfs(ll i)
{
    ll Val = a[i];
    visit[i] = 1;
    for (ll curr : edge[i])
    {
        if (!visit[curr])
        {
            Val = min(Val, dfs(curr));
        }
    }
    return Val;
}

void solve()
{
    ll m;
    ll n;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        
        edge[x-1].push_back(y-1);
        edge[y-1].push_back(x-1);
    }

    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            ans += dfs(i);
        }
    }
    cout << ans << endl;
}

int main()

{
    solve();
    return 0;
}
