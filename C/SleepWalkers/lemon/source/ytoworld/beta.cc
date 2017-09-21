#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string>
#include<iostream>
#include<algorithm>
using std::min;
using std::cin;
using std::string;
int t;
int main(){
  string a;
  cin>>a;
  scanf("%d",&t);
  while (t>a.size()){
    a='0'+a;
  }
  string b;
  for (int i=a.size()-t;i<a.size();i++){
    b+=a[i]-48;
  }
  long long ans=0;
  string c=b;
  while(1){
    for (int i=0;i< c.size();i++){
      for (int j=0;j< c.size()-i;j++){
	c[c.size()-1-i-j]=c[c.size()-1-i]*c[c.size()-1-j];
	if (c[c.size()-1-i-j]>=10){
	  if (i+j!=c.size()-1) c[c.size()-i-j-2]+=c[c.size()-1-i-j]/10;
	  c[c.size()-i-j]%=10;
	}
      }
    }
    ans++;
    for (int k=0;k< c.size();k++) printf("%d ",c[k]);
    printf("\n");
    if (ans>1000000000){
      printf("-1");
      break;
    }
    if (c==b){
      printf("%lld",ans);
      break;
    }
  }
  printf("\n%ld",clock()/1000);
  return 0;
}
  
