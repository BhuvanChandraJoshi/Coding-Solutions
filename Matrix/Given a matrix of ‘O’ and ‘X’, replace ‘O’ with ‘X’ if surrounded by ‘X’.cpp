//Link:   https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void travel(vector<vector<char>> &v, int i, int j, int n, int m){
	v[i][j] = '-';
	int a[8] = {-1, 0, 1, 0};
	int b[8] = {0, 1, 0, -1};
	for(int k=0; k<4; k++){
		if(i+a[k]>=0 && i+a[k]<=n-1 && j+b[k]>=0 && j+b[k]<=m-1 && v[i+a[k]][j+b[k]]=='O'){
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
	vector<vector<char>> v(n);
	for(int i=0; i<n; i++){
		v.push_back({});
		for(int j=0; j<m; j++){
			char x;
			cin>>x;
			v[i].push_back(x);
		}
	}
	for(int i=0; i<m; i++){
		if(v[0][i] == 'O')
			travel(v, 0, i, n, m);
	}
	for(int i=0; i<n; i++){
		if(v[i][0] == 'O')
			travel(v, i, 0, n, m);
	}
	for(int i=0; i<m; i++){
		if(v[n-1][i] == 'O')
			travel(v, n-1, i, n, m);
	}
	for(int i=0; i<m; i++){
		if(v[i][m-1] == 'O')
			travel(v, i, m-1, n, m);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(v[i][j] == '-')
				v[i][j] = 'O';
			else if(v[i][j] = 'O')
				v[i][j] = 'X';
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
