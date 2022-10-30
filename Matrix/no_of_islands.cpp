//Link:   https://www.geeksforgeeks.org/find-number-of-islands/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void travel(vector<vector<int>> &v, int i, int j, int n, int m){
	v[i][j] = -1;
	int a[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int b[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	for(int k=0; k<8; k++){
		if(i+a[k]>=0 && i+a[k]<=n-1 && j+b[k]>=0 && j+b[k]<=m-1 && v[i+a[k]][j+b[k]]==1){
			travel(v, i+a[k], j+b[k], n, m);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n);
	for(int i=0; i<n; i++){
		v.push_back({});
		for(int j=0; j<m; j++){
			int x;
			cin>>x;
			v[i].push_back(x);
		}
	}
	int res = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(v[i][j] == 1){
				travel(v, i, j, n, m);
				res++;
			}
		}
	}
	cout<<res;
	return 0;
}
