#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

char c[10005];
int a[10003],b[10003],la=0,lb=0,ll;

void jian(bool d){
	if(d==1){
		printf("-");
		for(int i=ll-1;i>=0;i--){
			b[i]-=a[i];
			int
			while(b[i]<0){
				b[i]+=10;
				b[i+1]--;
			}
			if(b[i]==0&&i==ll-1) ll--;
		}
		for(int i=ll-1;i>=0;i--) printf("%d",b[i]);
	}
	else{
		for(int i=ll-1;i>=0;i--){
			a[i]-=b[i];
			if(a[i]<0){
				a[i]+=10;
				a[i+1]--;
			}
			if(a[i]==0&&i==ll-1) ll--;
		}
		for(int i=ll-1;i>=0;i--) printf("%d",a[i]);
	}
	printf("\n");
	return;
}

int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%s",c);
	for(int i=0;c[i]>='0'&&c[i]<='9';i++,la++) a[la]=c[i]-'0';
	for(int i=0,j=la-1;i<la/2;i++,j--){
		int c=a[j];
		a[j]=a[i];
		a[i]=c;
	}

	scanf("%s",c);
	for(int i=0;c[i]>='0'&&c[i]<='9';i++,lb++) b[lb]=c[i]-'0';
	for(int i=0,j=lb-1;i<lb/2;i++,j--){
		int c=b[j];
		b[j]=b[i];
		b[i]=c;
	}
	
	ll=max(la,lb);
	if(lb>la){
		jian(1);
		return 0;
	}
	else if(la==lb){
		for(int i=ll;i>=0;i--){
			if(b[i]>a[i]){
				jian(1);
				return 0;
			}
		}
		jian(0);
		return 0;
	}
	else jian(0);
	return 0;
}

/*
30141
8160
=
21981

*/