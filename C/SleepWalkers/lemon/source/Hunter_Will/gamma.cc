#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>

using namespace std;

#define maxn 30
const double eps=1e-9;
int n,m;
double mat[maxn][maxn],b[maxn];
char now[4096];

void solve(int l,int r,int k,int tp){
    int sta[200];
    int top=0,cnt=0;
    for(int i=l;i<=r;i++){
	if(now[i]=='[')sta[top++]=1;
	else if(now[i]==']'){
	    --top;
	    if(!top)cnt++;
	}
    }
    if(!cnt){
	int x=0,cnt1=0,tmp=0,s=1;
	for(int i=l;i<=r;i++){
	    if(now[i]=='-')s=-1;
	    if(isdigit(now[i])){
		x=x*10+now[i]-'0';
	    }
	    else if(x&&now[i]==' '){
		tmp+=x*s;x=0;cnt1++;s=1;
	    }
	    else if(now[i]>='a'&&now[i]<='z')cnt1++;
	}
	if(x){cnt1++;tmp+=x*s;x=0;s=1;}
	for(int i=l;i<=r;i++){
	    if(now[i]>='a'&&now[i]<='z')
		mat[tp][now[i]-'a']-=(double)1/(cnt1*k);
	}
	b[tp]+=(double)tmp/(cnt1*k);
    }
    else {
	int nl=-1,nr=-1;
	for(int i=l;i<=r;i++){
	    if(now[i]=='['){
		sta[top++]=1;
		if(nl<0)nl=i+1;
	    }
	    else if(now[i]==']'){
		--top;
		if(!top){
		    nr=i-1;
		    solve(nl,nr,k*cnt,tp);
		    nl=-1;
		}
	    }
	}
    }
    return;
}

void outp(){
    for(int i=0;i<n;i++,puts(""))
	for(int j=0;j<m;j++)cout<<mat[i][j]<<' ';
}

void gauss(){
    for(int i=0;i<n;i++){
	int mxi=i;
	for(int j=i+1;j<n;j++)
	    if(abs(mat[j][i])-abs(mat[mxi][i])>eps)mxi=j;
	if(mxi!=i){
	  for(int j=0;j<m;j++)swap(mat[i][j],mat[mxi][j]);
	  swap(b[i],b[mxi]);
	}
	b[i]/=mat[i][i];
	for(int j=m-1;j>=i;j--)mat[i][j]/=mat[i][i];
	for(int j=i+1;j<n;j++){
	    b[j]/=mat[j][i];
	    for(int k=m-1;k>=i;k--)mat[j][k]/=mat[j][i];
	    b[j]=b[i]-b[j];
	    for(int k=i;k<m;k++)mat[j][k]=mat[i][k]-mat[j][k];
	}
    }
    for(int i=n-1;i>=0;i--){
	for(int j=i-1;j>=0;j--){
	    b[j]-=b[i]*mat[j][i];
	}
    }
    for(int i=0;i<n;i++){
	printf("%c = ",char(i+'a'));
	if(abs(mat[i][i])<eps)puts("Unknown");
	else printf("%.3f\n",b[i]);
    }
}
	    
int main(){
    freopen("gamma.in","r",stdin);
    freopen("gamma.out","w",stdout);
    int sta[200],top=0,nl=-1,nr;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
	int p=0;char ch=getchar();
	while(ch!='\n'&&ch!='\r'){now[p++]=ch;ch=getchar();}
	mat[i][now[0]-'a']++;
	for(int j=0;now[j]!='\0';j++){
	    if(now[j]>='a'&&now[j]<='z')m=max(m,(int)(now[j]-'a'));
	    if(now[j]=='['){
		sta[top++]=1;
		if(nl<0)nl=j+1;
	    }
	    else if(now[j]==']'){
		--top;
		if(!top)nr=j-1;
	    }
	}
	solve(nl,nr,1,i);
    }m++;
    for(int i=0;i<n;i++,puts("")){
	for(int j=0;j<n;j++){
	    cout<<mat[i][j]<<' ';
	}
    }
    for(int i=0;i<n;i++)cout<<b[i]<<endl;
    gauss();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
