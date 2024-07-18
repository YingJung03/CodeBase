class Solution {
public:
    bool judgeCircle(string moves) {
        int arr1=0;
        int arr2=0;
        for(int i=0;i<moves.length();i++){
            char ch=moves[i];
            if(ch=='U'){
                arr2-=1;
            }else if(ch=='D'){
                arr2+=1;
            }else if(ch=='R'){
                arr1+=1;
            }else if(ch=='L'){
                arr1-=1;
            }
        }
        
        return arr1==0 && arr2==0;
    }
};