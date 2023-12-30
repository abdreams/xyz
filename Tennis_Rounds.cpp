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

int32_t main(){
FAST_IO();

    int n,pl1,pl2;
    while(cin>>n>>pl1>>pl2){

        int ans=0;
        while(pl1!=pl2){
            pl1=(pl1+1)/2;
            pl2=(pl2+1)/2;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}