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

int n=100000000;
bitset<100000005>b; // stores a bit indicating 1 or 0 at each index
vector<int>primes;
 
void sieve(){
 
    for(int i=3;i<=n;i=i+2){
        b[i]=1;
    }
 
    for(int i=3;i<=n;i=i+2){
        if(b[i]==1){
        for(int j=i*i;j<=n;j+=i){
            b[j]=0;
        }
        }
    }
    b[2]=1;
    b[1]=b[0]=0;
 
    for(int i=0;i<=n;i++){
        if(b[i]==1) primes.push_back(i);
    }
}
 
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    sieve();
    //w(T) this gives TLE!!
    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        cout<<primes[num-1]<<endl;
    }
    return 0;
 
}