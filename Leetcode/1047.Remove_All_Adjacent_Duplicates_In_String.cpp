class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>stack1;
        string lst;
        for(int i=0;i<s.length();i++){
            if(stack1.empty()){
                stack1.push(s[i]);
            }else if(stack1.top()==s[i]){
                stack1.pop();
            }else{
                stack1.push(s[i]);
            }
        }
        while(!stack1.empty()){
            lst += stack1.top(); 
            stack1.pop();
            
        }

        // 因為從堆疊中取出的順序是反的，所以需要將字串反轉
        reverse(lst.begin(), lst.end());

        return lst;

    }
};