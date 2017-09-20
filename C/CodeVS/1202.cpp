#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int n,ans=0,cnm;

int main(){
	scanf("%d",&n);
	for(;n--;){
		scanf("%d",&cnm);
		ans+=cnm;
	}
	printf("%d",ans);

	return 0;
}
