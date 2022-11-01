//Link: https://leetcode.com/problems/rotate-image/submissions/

//first do transpose of matrix, then reverse individual rows 
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
    for(int i=0; i<n; i++){
        int s=0, e=n-1;
        while(s<=e){
            swap(matrix[i][s], matrix[i][e]);
            s++;
            e--;
        }
    }
}
