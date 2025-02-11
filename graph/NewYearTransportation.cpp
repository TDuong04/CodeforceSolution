#include <iostream>
using namespace std;

typedef long long ll;

ll n, t;
const ll template_size = 1e6 + 4832;
ll a[template_size];

void solve() {
    cin >> n >> t;
    for (ll i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    ll cur = 1;
    while (cur < t) {
        cur = cur + a[cur - 1];
    }

    if (cur == t) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    solve();
    return 0;
}
