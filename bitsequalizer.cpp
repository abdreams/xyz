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
    int casenum=1;
    w(t){
        string start,end;
        cin>>start;
        cin>>end;
        int n=start.length();
        int ones_start=0;
        int ones_end=0;
        int qmark=0;
        for(int i=0;i<n;i++){
            if(start[i]=='1') ones_start++;
            if(start[i]=='?') qmark++;
            if(end[i]=='1') ones_end++;
        }
        int t1=0;
        int t2=0;

        if(ones_start>ones_end){
            cout<<"Case "<<casenum<<": -1"<<endl;
        }
        else{
            for (int i = 0; i < n; i++)
            {
                if(start[i]=='1' and end[i]=='0') t1++;
                else if(start[i]=='0' and end[i]=='1') t2++;
            }
            cout<<"Case "<<casenum<<": "<<max(t1,t2)+qmark<<endl;

        }

    casenum++;
    }

    return 0;
}