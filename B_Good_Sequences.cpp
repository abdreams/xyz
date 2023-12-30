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

void FAST_IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    FAST_IO();

    int num_elements;
    cin >> num_elements;

    vector<int> numbers(num_elements + 1);
    int max_number = 0;

    for (int idx = 0; idx < num_elements; idx++) {
        cin >> numbers[idx];
        if (numbers[idx] > max_number) {
            max_number = numbers[idx];
        }
    }

    vector<int> prime_factors(max_number + 1, 0);
    vector<int> sequence_lengths(max_number + 1, 0);

    for (int p = 2; p <= max_number; p++) {
        if (prime_factors[p] == 0) {
            for (int q = p; q <= max_number; q += p) {
                prime_factors[q] = p;
            }
        }
    }

    int longest_sequence_so_far = 1;

    for (int idx = 0; idx < num_elements; idx++) {
        int current_number = numbers[idx];
        int current_count = 0;

        while (current_number > 1) {
            if (current_count <= sequence_lengths[prime_factors[current_number]]) {
                current_count = 1 + sequence_lengths[prime_factors[current_number]];
            }
            current_number /= prime_factors[current_number];
        }

        if (current_count > longest_sequence_so_far) {
            longest_sequence_so_far = current_count;
        }

        current_number = numbers[idx];
        while (current_number > 1) {
            if (sequence_lengths[current_number] < current_count) {
                sequence_lengths[prime_factors[current_number]] = current_count;
            }
            current_number /= prime_factors[current_number];
        }
    }

    cout << longest_sequence_so_far << endl;
    return 0;
}
