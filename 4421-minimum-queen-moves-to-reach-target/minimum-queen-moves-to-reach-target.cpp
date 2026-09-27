class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        vector<vector<int>> dp(9,vector<int>(9,-1));
        int sr = source[0];
        int sc = source[1];
        int er = target[0];
        int ec = target[1];
        if(sr==er && sc==ec) return 0;
        if(abs(sr-er)==abs(ec-sc)) return 1;
        if(sr==er || sc==ec) return 1;
        return 2;
    }
};