class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        for(char c: s){
            if(c == '[')
                balance++;
            else if(balance>0){
                balance--;
            }
        }
        return (balance+1)/2;
    }
};