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

int calculateWays(int n)
{
    int ways = 0;
    for (int i = 2; i * i * i <= n; ++i)
        ways += n / (1ll * i * i * i);
    return ways;
}

int32_t main(){
    FAST_IO();

    int m, result = -1;
    cin >> m;

    int left = 0, right = inf;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (calculateWays(mid) < m) left = mid + 1;
        else right = mid-1;
    }

    if (calculateWays(left) == m) result = left;
    else if (/* condition */)
    {
        /* code */
    }
    
    cout << result << endl;
    return 0;
}
