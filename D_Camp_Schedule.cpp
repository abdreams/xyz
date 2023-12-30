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
#define FAST_IO()               ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl                    "\n"

typedef vector<int>             vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void solve(){
    string s,t;
    cin >> s >> t;
    int ct0=0,ct1=0;
    int ct2=0,ct3=0;
    int n=s.size();
    int m=t.size();
    for(int i=0;i<n;i++){
        ct0+=(s[i]=='0');
        ct1+=(s[i]=='1');
    }
    for(int i=0;i<m;i++){
        ct2+=(t[i]=='0');
        ct3+=(t[i]=='1');
    }
    if(ct0<ct2||ct1<ct3){
        cout<<s<<endl;
    }
    else{
        vi pi(m,0);
        for(int i=1;i<m;i++){
            int j=pi[i-1];
            while(j>0&&t[i]!=t[j]){
                j=pi[j-1];
            }
            if(t[i]==t[j])j++;
            pi[i]=j;
        }
        int a=pi[m-1];
        string s1;
        for(int i=a;i<m;i++){
            s1.push_back(t[i]);
        }
        int rct0=0,rct1=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='0'){
                rct0++;
            }
            else{
                rct1++;
            }
        }
        string ans=t;

        ct0-=ct2;
        ct1-=ct3;

        while(ct0-rct0>=0&&ct1-rct1>=0){
            if(s1.size()==0){
                break;
            }
            for(int i=0;i<s1.size();i++){
                ans.push_back(s1[i]);
            }
            ct0-=rct0;
            ct1-=rct1;
        }
        for(int i=0;i<ct0;i++){
            ans.push_back('0');
        }
        for(int i=0;i<ct1;i++){
            ans.push_back('1');
        }
        cout<<ans<<endl;
    }
}

int32_t main(){
FAST_IO();

   
    solve();
    

    return 0;
}
