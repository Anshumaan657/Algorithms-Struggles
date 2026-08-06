class Solution {
    public:
        int digitProduct(int num) {
            int product = 1;
    
            while (num > 0) {
                int digit = num % 10;
                product = product * digit;
                num = num / 10;
            }
    
            return product;
        }
    
        int smallestNumber(int n, int t) {
            int num = n;
    
            while (true) {
                int product = digitProduct(num);
    
                if (product % t == 0) {
                    return num;
                }
    
                num++;
            }
    
            return -1;
        }
    };