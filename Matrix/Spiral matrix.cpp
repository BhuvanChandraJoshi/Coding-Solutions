//Link:   https://leetcode.com/problems/spiral-matrix/submissions/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<int> moves = {m, n-1};
    int r=0, c=-1;
    int iDir = 0;
    while(moves[iDir%2]!=0){
        for(int i=1; i<=moves[iDir%2]; i++){
            r += directions[iDir][0];
            c += directions[iDir][1];
            res.push_back(matrix[r][c]);
        }
        moves[iDir%2]--;
        iDir = (iDir+1)%4;
    }
    return res;
}
