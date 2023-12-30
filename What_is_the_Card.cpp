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
    w(t){
        vector<string>cards(52);
        for(int i=0;i<52;i++) cin>>cards[i];

        // 25 cards in hand top k, 27 card jameen pe
        // int topcard=52-25-1;

        vector<string>cards_on_desk;
        for(int i=0;i<=26;i++){
            cards_on_desk.push_back(cards[i]);
        }
        string topcard= cards.back();
        int value_of_card=0;
        int y=0;
        if(topcard[0]>=50 and topcard[0]<=57){
            value_of_card=topcard[0]-48;
        }else{
            value_of_card=10;
        }
        int z=x+y;
        cards_on_desk[z]
    }

    return 0;
}