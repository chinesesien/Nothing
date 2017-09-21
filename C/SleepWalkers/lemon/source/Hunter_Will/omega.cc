#include<iostream>
#include<cstdio>

using namespace std;

#define maxn 1000000
#define abs(i) ((i)>=0?(i):-(i))
int n,k,a[maxn];

int main(){
    freopen("omega.in","r",stdin);
    freopen("omega.out","w",stdout);
    int cnt=0,ans=0;
    char ch[10];
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
	scanf("%s",ch);
	a[i]=ch[0]-'A';
    }
    int s[3];
    s[0]=s[1]=0;
    for(int i=1;i<=n;i++){
	s[a[i]]++;
	if(s[0]&&s[1]&&abs((s[0]-s[1]))>k){
	    ans++;
	    s[0]=0;s[1]=0;
	    s[a[i]]++;
	}
    }
    ans++;
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
