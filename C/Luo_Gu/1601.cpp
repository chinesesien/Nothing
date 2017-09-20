/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int a[1000],b[1000],c[1000],la=0,lb=0,ll;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	for(char i;;la++){
		i=getchar();
		if(i>='0'&&i<='9') c[la]=i-'0';
		else break;
	}
	for(int i=0,j=la-1;i<la;i++,j--)
		a[i]=c[j];
	for(char i;;lb++){
		i=getchar();
		if(i>='0'&&i<='9') c[lb]=i-'0';
		else break;
	}
	for(int i=0,j=lb-1;i<lb;i++,j--)
		b[i]=c[j];
	ll=max(la,lb);
	for(int i=0;i<ll;i++){
		b[i]+=a[i];
		if(b[i]>9){
			b[i]-=10;
			b[i+1]++;
			if(i==ll-1){
				ll++;
				break;
			}
		}
	}
	for(int i=ll-1;i>=0;i--){
		printf("%d",b[i]);
	}

	return 0;
}
*/
/*
123
123
=
246
*/

#include <cstdio>
#include <cstring>
using namespace std;

char a[505], b[505], ans[505], ans1[505];

char *add(char *a, char *b)
{
	int aptr = strlen(a + 1), bptr = strlen(b + 1), ansptr = aptr > bptr ? aptr : bptr;
	while (aptr > 0 && bptr > 0)
	{
		ans[ansptr] += a[aptr] + b[bptr] - '0';
		if (ans[ansptr] > '9')
		{
			ans[ansptr] -= 10;
			ans[ansptr - 1]++;
		}
		aptr--, bptr--, ansptr--;
	}
	while (aptr > 0)
	{
		ans[aptr] += a[aptr];
		if (ans[aptr] > '9')
			ans[aptr] -= 10, ans[aptr - 1]++;
		aptr--;
	}
	while (bptr > 0)
	{
		ans[bptr] += b[bptr];
		if (ans[bptr] > '9')
			ans[bptr] -= 10, ans[bptr - 1]++;
		bptr--;
	}
	if (ans[0] != 0)
	{
		ans[0] = '1';
		return ans;
	}
	else
	{
		strcpy(ans1, ans + 1);
		return ans1;
	}
}
int main()
{
	scanf("%s%s", a + 1, b + 1);
	printf("%s\n", add(a, b));
	return 0;
}
