#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

char ta[10003][10003];
int n=0;

int main(){
	for(;~scanf("%s",ta[n]);n++);
	for(;n--;) printf("%s ",ta[n]);
	return 0;
}
