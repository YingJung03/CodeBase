class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<int> m;
        int a=mat.size();
        int b=mat[0].size();
        if((a*b)!=(r*c)) return mat;  //避免輸入及輸出大小不符，發生buffer-overflow
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                m.push_back(mat[i][j]);
            }
        }

        vector<vector<int>> ans(r,vector<int> (c));
        int k=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j]=m[k++];
            }
        }
        return  ans;    
    }
};