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

int n,k;
vector<int>reqd;
vector<int>has;

bool check(int num){
    vector<int>extra_ingredients_needed_for_num(n,0);
    for (int i = 0; i < n; i++)
    {
        extra_ingredients_needed_for_num[i]=(reqd[i]*num)-has[i];
        // !!imp condition to check::
        if(extra_ingredients_needed_for_num[i]<0) extra_ingredients_needed_for_num[i]=0;
    }
    int total=0;
    for(auto it:extra_ingredients_needed_for_num) total+=it;
    if(total<=k) return true;
    return false;
}

int32_t main(){
FAST_IO();
    cin>>n>>k;
    reqd.assign(n,0);
    has.assign(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>reqd[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>has[i];
    }

    int ans=0;
    int left=0;
    int right=1e14;

    while (left<=right)
    {   int mid=left+(right-left)/2;

        if(check(mid)){
            ans=mid;
            left=mid+1;
        }
        else right=mid-1;
    }

    cout<<ans<<endl;
    
    return 0;
}