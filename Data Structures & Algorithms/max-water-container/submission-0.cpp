class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;

        int area;
        int i = 0;
        int j = heights.size() - 1;
        while(i < j){
            //cout << max_area << endl;
            area = (j-i) * min(heights[i], heights[j]);
            
            if(area > max_area)
                max_area = area;

            if (heights[i] < heights[j]){
                int height = heights[i];
                while( i < j && heights[i] <= height) 
                    i++;
            }

            else {
                int height = heights[j];
                while(i < j && heights[j] <= height) 
                    j--;
            }
            
            
        }

        return max_area;
    }
};
