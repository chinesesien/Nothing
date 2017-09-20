#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

double a,b;

int main(){
	scanf("%lf%lf",&a,&b);
	a*=100000000;
	b*=100000000;
	if((int)a==(int)b) printf("yes");
	else printf("no");

	return 0;
}
