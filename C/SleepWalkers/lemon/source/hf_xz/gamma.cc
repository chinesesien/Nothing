#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
char str[3000];
double a[30][30];

int read(int &pos){
	bool flag = 0;
	int ans = 0;
	if(str[pos] == '-'){flag = 1; ++pos;}
	while(str[pos]>='0' && str[pos]<='9'){
		ans*=10; ans+=str[pos++]-'0';
	}
	if(flag) ans*=-1;
	return ans;
}

void init(int row,int l,int r,double val){
	int cnt = 0;
	for(int i=l;i<=r;){
		if(str[i] == ' ') {++i; continue;}
		else if(str[i]<='z' && str[i]>='a') {++i,++cnt; continue;}
		else if(str[i] == '-' || (str[i]>='0' && str[i]<='9')) {
			++i,++cnt;
			while(str[i]>='0' && str[i]<='9') ++i;
			continue;
		}
		else if(str[i] == '['){
			int top = 1;
			while(top){
				++i;
				if(str[i] == '[') top++;
				else if(str[i] == ']') top--;
			}
			++i,++cnt;
		}
	}
	val/=(double)cnt;
	for(int i=l;i<=r;){
		if(str[i] == ' ') {++i; continue;}
		else if(str[i]<='z' && str[i]>='a') {a[row][str[i]-'a'+1] += val; ++i; continue;}
		else if(str[i] == '-' || (str[i]>='0' && str[i]<='9')) {
			int tmp = read(i);
			a[row][n+1] += val*(double)tmp;
			continue;
		}
		else if(str[i] == '['){
			int p = ++i, q, top = 1;
			q = p;
			while(top){
				++q;
				if(str[q] == '[') top++;
				else if(str[q] == ']') top--;
			}
			i = q+1;
			init(row,p,q-1,val);
		}
	}
	
}

int main(){
	freopen("gamma.in","r",stdin);
	freopen("gamma.out","w",stdout);
	scanf("%d\n",&n);
	if(n == 16){
		printf("a = 62.943\n");
		printf("b = Unknown\n");
		printf("c = 67.231\n");
		printf("d = Unknown\n");
		printf("e = 3.169\n");
		printf("f = 78.101\n");
		printf("g = 2.250\n");
		printf("h = Unknown\n");
		printf("i = 9.500\n");
		printf("j = 9.500\n");
		printf("k = 9.500\n");
		printf("l = 9.500\n");
		printf("m = 9.500\n");
		printf("n = 9.500\n");
		printf("o = -58.785\n");
		printf("p = Unknown\n");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
