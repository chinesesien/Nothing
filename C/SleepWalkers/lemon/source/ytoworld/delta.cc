#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
using std::map;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
int n,m;
vector<int> a;
map<string,int> point;
int main(){
	freopen ("delta.in","r",stdin);
	freopen ("delta.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	cin>>n;
	int nn = 1;
	for (int i=0;i<n;i++){
		string fff;
		cin>>fff;
		point[fff]=nn;
		nn++;
	}
	cin>>m;
	for (int i=0;i<m;i++){
		string fff;
		cin>>fff;
		if (point[fff]) a.push_back(point[fff]);
		else a.push_back(0);
	}
	int ans = 0;
	int ans2 = m-1;
	for (int i = 1;i <= m;i++){
		for (int j = i;j < m;j++){
// 			cout << "For i=" << i << ", j=" << j;
			bool fff[1005] = {0};
			int ttans = 0;
			for (int k = j;k >= j-i;k--){
				fff[a[k]] = 1;                             // mark this string as shown;
			}
			for (int l = 1;l < 1005;l++){
				if (fff[l]) ttans++;
			}
// 			cout << ", ttans=" << ttans << endl;
			if (ttans>ans){
				ans = ttans;
				ans2 = i;
			}
		}
	}
	cout << ans << endl;
	cout << ans2+1 << endl;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
