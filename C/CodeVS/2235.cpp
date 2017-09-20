#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

double n,k;

int main(){
	scanf("%lf%lf",&n,&k);
	k*=0.1;
	n*=k;
	n+=0.5;
	int tn=n;
	tn+=5;
	tn/=10;
	tn*=10;
	printf("%d",tn);
	return 0;
}
