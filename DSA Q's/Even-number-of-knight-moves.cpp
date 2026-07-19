class solution{
    public:
    bool canReach(vector<int>& start, vector<int>& target){
        int startX = start[0];
        int startY = start[1];
       
        int targetX = target[0];
        int targetY = target[1];

        int startcolur = (startX + startY)%2;
        int targetcolur = (targetX + targetY)%2;

        if(startcolur == targetcolur){
            return true;
        }
        return false;

    }
};