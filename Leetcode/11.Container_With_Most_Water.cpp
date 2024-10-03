class Solution {
public:
    int maxArea(vector<int>& heights) {
        int front=0;
        int rear=heights.size()-1;
        int maximum=0;

        while(front<rear){
            if(heights[front]<=heights[rear]){
                int water=heights[front]*(rear-front);
                maximum=max(maximum,water);
                front++;
            }else if(heights[front]>heights[rear]){
                int water=heights[rear]*(rear-front);
                maximum=max(maximum,water);
                rear--;
            }
        }
        return maximum;
        
    }
};
