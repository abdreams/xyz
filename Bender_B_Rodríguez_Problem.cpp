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

void solve(int n, vector<string> &seq)
{
    int x = n;
    int y = 0;
    int z = 0;

    for (auto it : seq)
    {
        if (it == "+x")
        {
            x -= 1;
        }
        else if (it == "-x")
        {
            x += 1;
        }
        else if (it == "+y")
        {
            swap(x, y);
            x *= -1;
        }
        else if (it == "-y")
        {
            swap(x, y);
            y *= -1;
        }
        else if (it == "+z")
        {
            swap(x, z);
            x *= -1;
        }
        else if (it == "-z")
        {
            swap(x, z);
            z *= -1;
        }
        else continue;
    }

    if (x == n)
    {
        cout << "+x" << endl;
    }
    else if (x == -n)
    {
        cout << "-x" << endl;
    }
    else if (y == n)
    {
        cout << "+y" << endl;
    }
    else if (y == -n)
    {
        cout << "-y" << endl;
    }
    else if (z == n)
    {
        cout << "+z" << endl;
    }
    else if (z == -n)
    {
        cout << "-z" << endl;
    }
}


int32_t main(){
ab_d();
    
    while(true){
        int n;
        cin>>n;
        if(n==0) break;
        vector<string>seq(n-1);
        for(int i=0;i<n-1;i++){
            cin>>seq[i];
        }
        solve(n,seq);
    }


    return 0;
}

/*
void solve(int n,vector<string>&seq){
    int x=n;
    int y=0;
    int z=0;
    int x2=n-1;
    int y2=0;
    int z2=0;

    for(auto it:seq){
        if(it=="+x"){
            x+=0;
        }
        else if(it=="-x"){
            x-=1;
        }
        else if(it=="+y"){
            y+=1;
        }
        else if(it=="-y"){
            y-=1;
        }
        else if(it=="+z"){
            z+=1;
        }
        else if(it=="-z"){
            z-=1;
        }
    }

    for(int i=1;i<seq.size();i++){
        string it2=seq[i];

        if(it2=="+x"){
            x2+=0;
        }
        else if(it2=="-x"){
            x2-=1;
        }
        else if(it2=="+y"){
            y2+=1;
        }
        else if(it2=="-y"){
            y2-=1;
        }
        else if(it2=="+z"){
            z2+=1;
        }
        else if(it2=="-z"){
            z2-=1;
        }   
    }
    cout<<x<<" "<<y<<" "<<z<<" "<<endl;
    cout<<x2<<" "<<y2<<" "<<z2<<" "<<endl;


    if(x!=x2 and y==y2 and z==z2){
        if(x2>x) {
        cout<<"-x"<<endl;
        return;
        }
        else if(x2<x) {
        cout<<"+x"<<endl;
        return;
        }
    }
    else if(y!=y2 and x==x2 and z==z2){
        if(y2>y) {
        cout<<"-y"<<endl;
        return;
        }
        else if(y2<y) {
        cout<<"+y"<<endl;
        return;
        }
    }
    else if(z!=z2 and x==x2 and y==y2){
        if(z2>z) {
        cout<<"-z"<<endl;
        return;
        }
        else if(z2<z) {
        cout<<"+z"<<endl;
        return;
        }
    }

}
*/