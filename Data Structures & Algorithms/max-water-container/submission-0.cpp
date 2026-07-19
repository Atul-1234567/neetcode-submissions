class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n =  heights.size();
        int left = 0;
        int right = n - 1;
        int maxi = INT_MIN;
        int area = 1;

        while(left <= right){
           int length = right - left;

           if(heights[left] < heights[right]){
               area =  heights[left] * length;
               maxi = max(maxi , area);
               left++;
           }
           else if(heights[right] < heights[left]){
              area = heights[right] * length;
              maxi = max(maxi , area);
              right--;
           }
           else{
              area = heights[left] * length;
              maxi = max(maxi , area);
              left++;
              right--;
           }

        }
        return maxi;
    }
};
