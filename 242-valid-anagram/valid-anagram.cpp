class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,int> countChar;
        for(char ch: s){
            countChar[ch] +=1;
        }
        for(char ch: t){
            countChar[ch] -=1;
        }
        for(auto& pair: countChar){
            if(pair.second != 0){
                return false;
            }
        }
        return true;
    }
};