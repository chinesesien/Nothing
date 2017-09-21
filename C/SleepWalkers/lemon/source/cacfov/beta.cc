#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
char s[200];         
int k,tp,num,n;
int ans[110] ;
int a[110],b[110],c[110],aa[110];
void gjc(int a[], int b[], int b1, int c[],int c1){
	for(int i=0;i<c1;i++)
		c[i]=0;
	if(b1>c1)
		b1=c1;
	for(int i=0;i<b1;i++){
		if(b[i]){
			for(int j=0;j<c1-i;j++){
				c[i+j]=a[j]*b[i]+c[i+j];
				c[i+j+1]=c[i+j+1]+c[j+i]/10;
				c[i+j]=c[i+j]%10;
			}
		}
	}
}
int main(){
	freopen("beta.in","r",stdin);
	freopen("beta.out","w",stdout);
	cin>>s;
	cin>>k;
	n=strlen(s);
	for(int i=0;i<n;i++)
		a[n-i-1]=s[i]-'0';
	for(int i=0;i<k;i++)
		aa[i]=a[i];
    ans[0]=1;
	for(int i=0;i<k;i++){
		for(int j=0;j<=i;j++)
			b[j]=aa[j];
		tp=b[i];
		num=0;
		do{
			gjc(a, b, i+1, c, i+1);
			num++;
			for(int j=0;j<k;j++)
				b[j]=c[j];
		}while((num<10)&&(b[i]!=tp));
		if(b[i]!=tp){
			cout<<-1<<endl;
			return 0;
		}
		for(int j=0;j<k;j++)
			b[j] = a[j];
		for(int j=0;j<num-1;j++){
			gjc(a, b, k, c, k);
			for(n=0;n<110;n++)
				a[n]=c[n];
		}
		gjc(ans,&num,1,c,110);
		for(n=0; n<110; n++)
			ans[n]=c[n];
	}
	for(int i=110-1;;i--)
		if(ans[i]!=0){
			n=i;
			break;
		}
	for(int i=n;i>=0;i--)
		cout<<ans[i];
	return 0;
}
