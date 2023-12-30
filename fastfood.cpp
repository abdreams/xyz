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
        int num_prizes, num_stickers;
        cin >> num_prizes >> num_stickers;

        vector<int> required_sticker_types;
        vector<int> prize_values;
        vector<vector<int>> prize_stickers(num_prizes, vector<int>(num_stickers, -1));

        for (int i = 0; i < num_prizes; i++) {
            int num_required_stickers;
            cin >> num_required_stickers;

            required_sticker_types.push_back(num_required_stickers);

            for (int j = 0; j < num_required_stickers; j++) {
                int sticker_type;
                cin >> sticker_type;
                prize_stickers[i][j] = sticker_type - 1;
            }

            int prize_value;
            cin >> prize_value;
            prize_values.push_back(prize_value);
        }

        vector<int> coach_stickers(num_stickers);

        for (int i = 0; i < num_stickers; i++) {
            int num_collected_stickers;
            cin >> num_collected_stickers;
            coach_stickers[i] = num_collected_stickers;
        }

        int total_cash = 0;

        for (int i = 0; i < num_prizes; i++) {
            int min_stickers = coach_stickers[prize_stickers[i][0]];

            for (int j = 1; j < required_sticker_types[i]; j++) {
                if (min_stickers > coach_stickers[prize_stickers[i][j]] && prize_stickers[i][j] > -1) {
                    min_stickers = coach_stickers[prize_stickers[i][j]];
                }
            }

            if (min_stickers > 0) {
                total_cash += (min_stickers * prize_values[i]);
            }
        }

        cout << total_cash << endl;
    }

    return 0;
}
