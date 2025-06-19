class Solution {
public:
    bool allCapital(string word){
        for(char c:word){
            if(!isupper(c)) return false;
        }
        return true;
    }
    bool allSmall(string word){
        for(char c:word){
            if(isupper(c)) return false;
        }
        return true;
    }
    bool onlyFirst(string word){
        if(!isupper(word[0])) return false;
        for(int i=1;i<word.length();i++){
            if(isupper(word[i])) return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
         return allCapital(word)||allSmall(word)||onlyFirst(word);

        
    }
};