class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            result += to_string(str.length()) + "#" + str;
        }
        
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        
        int i=0;
        while(i<s.length()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int length=stoi(s.substr(i,j));
            string str=s.substr(j+1,length);
            result.push_back(str);
            i=j+length+1;

        }
        
        return result;
    }
};
