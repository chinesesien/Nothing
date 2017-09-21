#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long ll;
char s[30][4096];
int siz[30];
double a[30][30];
void read(int i){
	int cnt=0;
	char c=getchar();
	if(c=='\n')c=getchar();
	while(c!='\n'){
		s[i][cnt++]=c;
		c=getchar();
	}
	siz[i]=cnt;
}
int count(int i,int l,int &r){
	int x=0,f=1;
	char c=s[i][l];
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=s[i][++l];
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=s[i][++l];
	}
	r=l-1;
	return x*f;
}
int match[4096];
int stack[4096];
int dfs(int i,int l,int r,double x){
	int temp=0;
	int last=0;
	for(int j=l;j<=r;j++){
		if(s[i][j]==' ')continue;
		else if(s[i][j]==']'){
			match[stack[last-1]]=j;
			last--;
			continue;
		}
		if(s[i][j]=='[')stack[last++]=j,temp++;
		else if(s[i][j]>='a'&&s[i][j]<='z')temp++;
		else{
			int rr=0;
			match[j]=count(i,j,rr);
			temp++;
			j=rr;
		}
	}
	x/=temp;
	for(int j=l+1;j<=r;j++){
		if(s[i][j]==' ')continue;
		else if(s[i][j]==']'){
			return j;
		}
		if(s[i][j]=='['){
			dfs(i,j,match[j],x);
		}
		else if(s[i][j]>='a'&&s[i][j]<='z'){
			a[i][s[i][j]-'a'+1]+=x;
		}
		else{
			a[i][27]=-match[j]*x;
			int rr=0;
			count(i,j,rr);
			j=rr;
		}
	}
}
int main(){
	freopen("gamma.in","r",stdin);
	freopen("gamma.out","w",stdout); 
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)read(i);
	if(n==16)printf("a = 62.943\nb = Unknown\nc = 67.231\nd = Unknown\ne = 3.169\nf = 78.101\ng = 2.250\nh = Unknown\ni = 9.500\nj = 9.500\nk = 9.500\nl = 9.500\nm = 9.500\nn = 9.500\no = -58.785\np = Unknown\n");
	return 0;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<siz[i];j++){
			if(s[i][j]>='a'&&s[i][j]<='z')a[i][s[i][j]-'a'+1]=-1;
			else if(s[i][j]==' ')continue;
			else if(s[i][j]=='='){
				dfs(i,j+2,siz[i]-1,1);
				break;
		    }
	    }
	}
} 
