class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m1;  //<key,value>
        unordered_map<char, int> m2;

        if (s.length()!= t.length())
        {
            return false;
        }

        for(int i=0;i<s.length();i++)
        {
            m1[s[i]]++;   //將字元加進m，如果字元以存在m裡面，則value加1
        }

        for(int i=0;i<t.length();i++)
        {
            m2[t[i]]++;   
        }
        for(auto x: m1){           //x是row <key,value>
            if(x.second!=m2[x.first])
            {
                return false;
            }
        }
        return true;
    }
};