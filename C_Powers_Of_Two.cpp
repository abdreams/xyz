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
#define INP_VECTOR(arr, n)      \
                                vector<int>arr(n,0); \
                                for (int i = 0; i < n; ++i) { \
                                    cin >> arr[i]; \
                                }
#define FAST_IO()               ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef vector<int>             vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
    FAST_IO();

    int targetSum, requiredCount;
    cin >> targetSum >> requiredCount;

    map<int, int> powerOfTwos;
    queue<int> breakdownQueue;

    for(int i = 0; i <= 30; i++)
        if(targetSum & (1 << i))
        {
            if(i > 0) breakdownQueue.push(1 << i);
            powerOfTwos[1 << i]++;
        }

    if((powerOfTwos.size()) > requiredCount)
    {
        cout << "NO" << endl;
        return 0;
    }

    int currentCount = powerOfTwos.size();
    while(currentCount < requiredCount && !breakdownQueue.empty())
    {
        int currentPower = breakdownQueue.front();
        breakdownQueue.pop();

        powerOfTwos[currentPower]--;
        powerOfTwos[currentPower / 2] += 2;

        if(currentPower / 2 > 1)
        {
            breakdownQueue.push(currentPower / 2);
            breakdownQueue.push(currentPower / 2);
        }
        currentCount++;
    }

    if(currentCount < requiredCount)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for(auto power : powerOfTwos)
        for(int i = 0; i < power.second; i++)
            cout << power.first << " ";
    cout << endl;

    return 0;
}
