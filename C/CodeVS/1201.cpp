#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int n,mmp,ma=2147483648,mi=2147483647;

int main(){
	scanf("%d",&n);
	for(;n--;){
		scanf("%d",&mmp);
		ma=max(mmp,ma);
		mi=min(mmp,mi);
	}
	printf("%d %d",mi,ma);

	return 0;
}
