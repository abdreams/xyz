#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007

#define w(x)            int x; cin>>x; while(x--)
const int inf     =        1e9+7;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void FAST_IO(){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

int32_t main(){
FAST_IO();
    w(t){
        int n,k;
        cin>>n>>k;
        int p=1;
        int ans=0;
        for (int i = 0; i < 32; i++)
        {
            if(k & (1<<i)){
                ans=(ans+p)%inf;
            }
            p*=n;
            p%=inf;
        }
        cout<<ans<<endl;
        
    }

    return 0;
}