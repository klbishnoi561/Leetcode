class Solution {
public:
    int num(char s){
        if(s=='I') return 1;
        else if(s=='V') return 5;
        else if(s=='X') return 10;
        else if(s=='L') return 50;
        else if(s=='C') return 100;
        else if(s=='D') return 500;
        else return 1000;
    }
    int romanToInt(string s) {
        int ind = 0;
        int total = 0;
        while(ind<(s.size()-1)){
            if(num(s[ind])<num(s[ind+1])){
                total = total-num(s[ind]);
            }
            else {
                total = total + num(s[ind]);
            }
            ind++;
        }
        total = total + num(s[ind]);
        return total;

        
    }
};