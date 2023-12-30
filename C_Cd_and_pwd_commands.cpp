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
#define INP_VECTOR(arr, n)      vector<int>arr(n,0); for (int i = 0; i < n; ++i) { cin >> arr[i]; }
#define FAST_IO()               ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef vector<int>             vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
    FAST_IO();

    int n;
    cin>>n;
    cin.ignore();
    stack<string> s;
    
    while(n--){
        string str;
        getline(cin, str);
        if(str.substr(0, 3) == "cd "){
            string address = str.substr(3);
            if(address[0] == '/'){
                while(!s.empty()) s.pop();
            }
            vector<string> v;
            int i = (address[0] == '/') ? 1 : 0;
            string temp = "";
            while(i < address.length()){
                if(address[i] != '/'){
                    temp += address[i];
                    i++;
                }
                else{
                    v.push_back(temp);
                    temp = "";
                    i++;
                }
            }
            v.push_back(temp);
            for(string word : v){
                if(!s.empty() && word == ".."){
                    s.pop();
                }
                else{
                    s.push(word);
                }
            }
        }
        else if(str == "pwd"){
            stack<string> temp = s;
            vector<string> v;
            while(!temp.empty()){
                v.push_back(temp.top());
                temp.pop();
            }
            reverse(v.begin(), v.end());
            cout << '/';
            for(string word : v){
                cout << word << '/';
            }
            cout << endl;
        }
    }
    return 0;
}
