#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define w(x)            int x; cin>>x; while(x--)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void FAST_IO(){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

bool canRotateToZero(const vector<int>& angles, int index, int sum) {
    if (index == angles.size()) {
        return sum % 360 == 0;
    }

    if (canRotateToZero(angles, index + 1, sum + angles[index])) {
        return true;
    }

    if (canRotateToZero(angles, index + 1, sum - angles[index])) {
        return true;
    }

    return false;
}

int32_t main() {
    int n;
    cin >> n;

    vector<int> angles(n);
    for (int i = 0; i < n; i++) {
        cin >> angles[i];
    }

    if (canRotateToZero(angles, 0, 0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
