class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int right = n - 1;
        int area = 0;

        while(left <=  right){
            if(heights[left] < heights[right]){
                int length = right - left;
                int mini = min(heights[left] , heights[right]);
                area = max(area , length * mini);
                left++;
            }
            else if(heights[left] == heights[right]){
                int length = right - left;
                area = max(area , length * heights[left]);
                left++;
                right--;
            }
            else{
                int length = right - left;
                int mini = min(heights[left] , heights[right]);
                area = max(area , length * mini);
                right--;
            }
        }
        return area;
    }
};
