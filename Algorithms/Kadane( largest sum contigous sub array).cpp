int kadane(vector<int> nums){
	int mxSum = INT_MIN;
	int curr = 0;
	for(int i=0; i<nums.size(); i++){
		curr = curr + nums[i];
		if(curr>mxSum){
			mxSum = curr;
		}
		if(curr<0){
			curr = 0;
		}
	}
	return mxSum;
}
