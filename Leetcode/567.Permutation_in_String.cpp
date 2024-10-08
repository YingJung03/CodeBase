class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int s1_size=s1.size();
       int s2_size=s2.size();

       if(s1_size>s2_size){
        return false;
       }

       vector<int> countS1(26, 0), countS2(26, 0);

       for(int i=0;i<s1_size;i++){
        countS1[s1[i]- 'a']++;
        countS2[s2[i]- 'a']++;
       }

       for(int i = 0; i <= s2_size - s1_size; i++){
        if(countS1==countS2){
            return true;
        }
        if(i+s1_size<s2_size){
            countS2[s2[i]- 'a']--;
            countS2[s2[i+s1_size]- 'a']++;
        }
       }
       return false;
    }
};
