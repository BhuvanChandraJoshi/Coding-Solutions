//Question Link:  https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int maxArea(vector<int> arr){
	int res = INT_MIN;
	int n = arr.size();
	int ps[n], ns[n];
	stack<int> p, g;
	for(int i=0; i<n; i++){
		while(p.empty()==false && arr[p.top()] >= arr[i]){
			p.pop();
		}
		if(p.empty()){
			ps[i] = -1;
			p.push(i);
		}
		else{
			ps[i] = p.top();
			p.push(i);
		}
	}
	for(int i=n-1; i>-1; i--){
		while(g.empty()==false && arr[g.top()] >= arr[i]){
			g.pop();
		}
		if(g.empty()){
			ns[i] = n;
			g.push(i);
		}
		else{
			ns[i] = g.top();
			g.push(i);
		}
	}
	for(int i=0; i<n; i++){
		res = max(res, arr[i]*(ns[i]-ps[i]-1));
	}
	return res;
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
	int ans = maxArea(v[0]);
	for(int i=1; i<n; i++){
		for(int j=0; j<m; j++){
			if(v[i][j] != 0){
				v[i][j] += v[i-1][j];
			}
		}
		ans = max(ans, maxArea(v[i]));
	}
	cout<<ans;
	return 0;
}
