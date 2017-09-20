#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int n,pc[1003]={0},s[103]={0};

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(pc[x]!=0){
			i--;
			n--;
			continue;
		}
		s[i]=x;
		pc[i]=1;
	}
	sort(s,s+n);
	for(int i=0;i<n;i++){
		if(i==n-1){
			printf("%d",s[i]);
			break;
		}
		printf("%d ",s[i]);
	}

	return 0;
}
