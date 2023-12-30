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

bool is_prime(int n) {
    for(int i = 2; i * i <= n; i++) 
        if(n % i == 0) return 0; 
    return 1; 
}

int32_t main() {
FAST_IO();

/*

Goldbach's conjecture is one of the oldest and best-known unsolved problems in
number theory and all of mathematics. It states that every even natural number greater
than 2 is the sum of two prime numbers.
/////
According to Goldbach's conjecture, which is checked for all numbers no more than 10^9,
every number is a sum of two prime numbers. Odd number can be sum of two primes, 
if (n-2) is prime (the only even prime number is 2).

*/

    int n;
    cin >> n;
    if(is_prime(n) == 1) 
        cout << 1 << endl;  
    else if(n % 2==1 and is_prime(n - 2)==0) 
        cout << 3 << endl;  
    else 
        cout << 2 << endl; 
}

