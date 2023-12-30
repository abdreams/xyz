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
//MSB:: Adjust the constant if you're working with a different integer size. Answer in 0 based indexing.
#define all(var)                var.begin(), var.end()
#define INP_VECTOR(arr, n) \
                                vector<int>arr(n,0); \
                                for (int i = 0; i < n; ++i) { \
                                    cin >> arr[i]; \
                                }
#define FAST_IO()               ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef vector<int>             vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// *s.find_by_order(), order_of_key()
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)

int n,m;
 
void solve(){
    int x;

    cin>>n>>m>>x;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    for (int i = 1; i < m+1; i++)
    {
        pq.push({0,i});
    }
        
    cout<<"YES"<<endl;
    
    for (int i = 1; i < n+1; i++)
    {
        int x;
        cin>>x;
        auto it=pq.top();
        pq.pop();
        cout<<it.second<<" ";
        // cout<<"first:"<<it.first<<"x:"<<x<<endl;
        pq.push({it.first+x,it.second});
    }

    cout<<endl;
}
 
int32_t main(){
FAST_IO();
    w(t){
        solve();
    }
    return 0;
}


