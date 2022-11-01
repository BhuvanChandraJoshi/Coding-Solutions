//Link: https://leetcode.com/problems/sort-colors/

void sortColors(vector<int>& nums) {
        int s=-1, e=nums.size();
        int index = 0;
        while(index<e && index<nums.size()){
            if(nums[index]==0){
                s++;
                swap(nums[index],nums[s]);
                index++;
            }
            else if(nums[index]==2){
                e--;
                swap(nums[index],nums[e]);
            }
            else{
                index++;
            }
        }
    }
