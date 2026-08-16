class Solution {
    public:
        bool stoneGameIX(vector<int>& stones) {
            int cnt[3] = {0, 0, 0};
    
            for (int x : stones) {
                cnt[x % 3]++;
            }
    
            // If count of remainder-0 stones is even,
            // Alice needs at least one remainder-1 and one remainder-2 stone.
            if (cnt[0] % 2 == 0) {
                return cnt[1] > 0 && cnt[2] > 0;
            }
    
            // If count of remainder-0 stones is odd,
            // Alice wins only when the difference is sufficiently large.
            return abs(cnt[1] - cnt[2]) > 2;
        }
    };