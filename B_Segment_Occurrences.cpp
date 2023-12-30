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

vector<int> prefix_fun(string s){
    int n = s.size();
    vector<int> pf(n,0);
    for(int i=1;i<n;i++){
        int j = pf[i-1];
        while(j>0 && s[i]!=s[j]){
            j = pf[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pf[i] = j;
    }
    
    return pf;
}

int32_t main(){
    FAST_IO();

    int n, m, q;
    string s, t;
    cin >> n >> m >> q;
    cin >> s >> t;
    vector<int> v = prefix_fun(t);
    
    for(int query = 0; query < q; query++){
        int l, r;
        int count = 0;
        cin >> l >> r;
        int i = l - 1;
        int j = 0;
        while(i < r){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                if(j != 0){
                    j = v[j - 1];
                }
                else{
                    i++;
                }
            }
            if(j == t.size()){
                count++;
                j = v[j - 1];
            }
        }
        cout << count << endl;
    }

    return 0;
}
