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


bool check(int interval,vector<int>&times,int h){
    int n=times.size();
    int totaldamage=0;
    for (int i = 0; i < n-1; i++)
    {
        totaldamage+=min(times[i+1]-times[i],interval);
    }
    totaldamage+=interval; // after last one attack still possible 
    if(totaldamage>=h) return true;
    return false;
    
}
int32_t main(){
FAST_IO();
    w(t){
        int n,h;
        cin>>n>>h;
        vector<int>times(n,0);
        for (int i = 0; i < n; i++)
        {
            cin>>times[i];
        }
        int ans=0;
        int l=0;
        int r=1e18;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,times,h)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        cout<<ans<<endl;
        
    }

    return 0;
}