// semper fi //
// abdreams //
// 

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

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int32_t main(){
ab_d();
    int n;
    cin>>n;
    vector<vector<int>>coordinates(2,vector<int>(2*n,-1));
    vector<int>taken(2*n,-1);
    is_move_constructible(nqueens);00
    vector<vector<is_member_pointer>>

    for(int i=0;i<2*n;i++){
        string s;
        cin>>s;
        cin>>coordinates[0][i];
        cin>>coordinates[1][i];
    }
    int sum=0;
    for(int i=0;i<2*n;i++){
        int mini=INT_MAX;
        for(int j=i+1;j<2*n;j++){
            int distance= pow((coordinates[0][i]-coordinates[0][j]),2)+pow((coordinates[1][i]-coordinates[1][j]),2);
            int finalD= pow(distance,0.5);
            mini=min(finalD,mini);             
        }
        sum+=mini;
    }
    cout<<sum<<endl;
    
    return 0;
}
