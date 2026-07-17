class Solution {
    public:
        vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
            int maxValue = 0;
    
            for (int num : nums) {
                maxValue = max(maxValue, num);
            }
    
            vector<int> frequency(maxValue + 1, 0);
    
            for (int num : nums) {
                frequency[num]++;
            }
    
            vector<long long> countGcd(maxValue + 1, 0);
    
            for (int g = maxValue; g >= 1; g--) {
                long long divisibleCount = 0;
    
                for (int multiple = g; multiple <= maxValue; multiple += g) {
                    divisibleCount += frequency[multiple];
                }
    
                long long totalPairs = divisibleCount * (divisibleCount - 1) / 2;
    
                for (int multiple = 2 * g; multiple <= maxValue; multiple += g) {
                    totalPairs -= countGcd[multiple];
                }
    
                countGcd[g] = totalPairs;
            }
    
            vector<long long> prefix(maxValue + 1, 0);
    
            for (int g = 1; g <= maxValue; g++) {
                prefix[g] = prefix[g - 1] + countGcd[g];
            }
    
            vector<int> answer;
    
            for (long long query : queries) {
                int left = 1;
                int right = maxValue;
                int result = maxValue;
    
                while (left <= right) {
                    int mid = left + (right - left) / 2;
    
                    if (prefix[mid] > query) {
                        result = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
    
                answer.push_back(result);
            }
    
            return answer;
        }
    };