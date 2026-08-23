#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // Count how many valid amounts <= x
        auto count = [&](long long x) {
            long long total = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = gcd(lcm, (long long)coins[i]);

                        // Avoid overflow / unnecessary large LCM
                        if (lcm / g > x / coins[i]) {
                            valid = false;
                            break;
                        }

                        lcm = (lcm / g) * coins[i];
                    }
                }

                if (!valid || lcm > x)
                    continue;

                if (bits % 2 == 1)
                    total += x / lcm;
                else
                    total -= x / lcm;
            }

            return total;
        };

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};