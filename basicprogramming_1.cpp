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
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
}

void solve2(int ind,vector<int>&arr,vector<int>&vis){
        int n=arr.size();

    if(ind>=n or ind<0){
        cout<<"Out"<<endl;
        return;
    }
    else if(ind==n-1){
        cout<<"Done"<<endl;
        return;
    }
    else{     
        if(!vis[ind]){
            vis[ind]=1;
            solve2(arr[ind],arr,vis);
        }
        else{
            cout<<"Cyclic"<<endl;
            return;
        }
    }
    return;

}

int32_t main(){
ab_d();

    int n,t;
    cin>>n;
    cin>>t;
    vector<int>arr(n,-1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    if(t==1){
        cout<<7<<endl;
    }
    else if(t==2){
        if(arr[0]>arr[1]) cout<<"Bigger"<<endl;
        else if (arr[0]==arr[1]) cout<<"Equal"<<endl;
        else cout<<"Smaller"<<endl;
    }
    else if(t==3){
        vector<int>v;
        v.push_back(arr[0]);
        v.push_back(arr[1]);
        v.push_back(arr[2]);
        sort(v.begin(),v.end());
        cout<<v[1]<<endl;
    }
    else if(t==4){
        int sum=0;
        for(auto it:arr){
            sum+=it;
        }
        cout<<sum<<endl;
    }
    else if(t==5){
        int sum=0;
        for(auto it:arr){
            if(it%2==0)
                sum+=it;
        }
        cout<<sum<<endl;
    }
    else if(t==6){
        for(auto it:arr){
            int num=it%26;
            char ch=num+97;
            cout<<ch;
        }
        cout<<endl;
    }
    else if(t==7){
        vector<int>vis(n,0);
        solve2(0,arr,vis);
    }

    return 0;
}
