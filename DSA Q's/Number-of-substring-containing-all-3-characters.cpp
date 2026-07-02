class Solution {
    public:
    int numberOfSubstrings( string s){
        int lastA = -1;
        int lastB = -1;
        int lastC = -1;
        int ans=0;

        for (int i=0; i< s.size(); i++){
            if (s[i]=='a')
                lastA = i;
            else if (s[i] == 'b')
                lastB = i;
            else
                lastC = i;
                int earliest = min(lastA, min(lastB, lastC));

            if (earliest != -1)
                ans += earliest +1;
        }
        return ans;

    }
};