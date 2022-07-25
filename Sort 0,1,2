class Solution {
public:
    /*
     -> elements left to low are 0's
     -> elements [low, mid-1] are 1's
     -> elements right to high are 2's
     TC - O(N)
     SC - O(1)
    */
    void sortColors(vector<int>& nums) {
        int low = 0; // elements left to low are 0's
        int mid = 0; // elements [low, mid-1] are 1's
        int high = nums.size()-1; // elements right to high are 2's
        while(mid<=high) {
            if(nums[mid] == 0) swap(nums[low++], nums[mid++]);
            else if(nums[mid] == 2) swap(nums[mid], nums[high--]);
            else mid++;
        }
    }
};
