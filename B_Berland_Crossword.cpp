#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int                     long long
#define mod                     (int)1e9+7
#define inf                     (int)1e18
#define w(x)                    int x; cin>>x; while(x--)
#define setbits(x)              __builtin_popcountll(x)
#define msb_position(x)         (x ? 63 - __builtin_clzll(x) : -1)
#define all(var)                var.begin(), var.end()
#define INP_VECTOR(arr, n)      vector<int>arr(n,0); for (int i = 0; i < n; ++i) { cin >> arr[i]; }
#define FAST_IO()               ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef vector<int>             vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main() {
    FAST_IO();

    w(t) {
        int n, U, R, D, L;
        cin >> n >> U >> R >> D >> L;

        bool possible = false;
        for (int mask = 0; mask < 16; mask++) {
            int rU = U, rR = R, rD = D, rL = L;
            if (mask & 1) {
                rU--;
                rL--;
            }
            if (mask & 2) {
                rL--;
                rD--;
            }
            if (mask & 4) {
                rD--;
                rR--;
            }
            if (mask & 8) {
                rR--;
                rU--;
            }
            if (min({rU, rR, rD, rL}) >= 0 && max({rU, rR, rD, rL}) <= n - 2) {
                possible = true;
                break;
            }
        }

        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
    