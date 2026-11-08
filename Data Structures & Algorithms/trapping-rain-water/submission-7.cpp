class Solution {
public:
    int trap(vector<int>& height) {
        int total_water = 0;

        int max_pole = 0;
        for(int i = 0; i < height.size(); i++)
            if(height[i] > height[max_pole])
                max_pole = i;

        int left = 0;
        int next = 1;
        int blocks = 0;
        int water = 0;
        while(next <= max_pole){

            water = max(0, min(height[left], height[next]) * (next - left - 1) - blocks);

            if ( height[next] >= height[left]){
                left = next;
                next++;
                blocks = 0;
                total_water += water;
                continue;
            }

            blocks += height[next];
            next++;
        }

        int right = height.size() - 1;
        next = right - 1;
        water = 0;
        blocks = 0;
        while(next >= max_pole){

            water = max(0, min(height[right], height[next]) * (right - next - 1) - blocks);

            if ( height[next] >= height[right]){
                right = next;
                next--;
                blocks = 0;
                total_water += water;
                continue;
            }

            blocks += height[next];
            next--;
        }

        return total_water;
    }
};
