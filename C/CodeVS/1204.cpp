#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

char a[103],b[103];
string ta,tb;

int main(){
	scanf("%s%s",a,b);
	ta=a;
	tb=b;
	printf("%d",ta.find(tb)+1);

	return 0;
}
