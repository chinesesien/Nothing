#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,v[100003],sj[10003],ps[10003][4],zs[10003][2],ts[10003][6];

void out(int w,int l){
	if(l==0){
		printf("It's over.\n");
		return;
	}
	if(l==1){
		if(ps[w][3]==1){
			if(ps[w][1]==1) 
				printf("v%d+v%d=%d\n",ps[w][0],ps[w][2],v[ps[w][0]]+v[ps[w][2]]);
			else 
				printf("v%d-v%d=%d\n",ps[w][0],ps[w][2],v[ps[w][0]]-v[ps[w][2]]);
		}
		else{
			if(ps[w][1]==1) 
				printf("v%d+%d=%d\n",ps[w][0],ps[w][2],v[ps[w][0]]+ps[w][2]);
			else 
				printf("v%d-%d=%d\n",ps[w][0],ps[w][2],v[ps[w][0]]-ps[w][2]);
		}
	}
	else if(l==2){
		printf("1.to %d\n2.to %d\n",zs[w][0],zs[w][1]);
	}
	else{
		if(ts[w][0]==0&&ts[w][2]==0){
			if(ts[w][0]>ts[w][2]) printf("to %d\n",ts[w][4]);
			else printf("to %d\n",ts[w][5]);
		}
		else if(ts[w][0]==1&&ts[w][2]==0){
			if(v[ts[w][0]]>ts[w][2]) printf("to %d",ts[w][4]);
			else printf("to %d",ts[w][5]);
		}
		else if(ts[w][0]==0&&ts[w][2]==1){
			if(ts[w][0]>v[ts[w][2]]) printf("to %d",ts[w][4]);
			else printf("to %d",ts[w][5]);
		}
		else if(ts[w][0]==1&&ts[w][2]==1){
			if(v[ts[w][0]]>v[ts[w][2]]) printf("to %d",ts[w][4]);
			else printf("to %d",ts[w][5]);
		}
	}
}

void qkqn(){
	char useless;
	scanf("%c",&useless);
	return;
}

void control(){
	for(int i=1;i<=n;i++){
		if(sj[i]==1){
			out(i,1);
			if(ps[i][1]==1){
				if(ps[i][3]==1) v[ps[i][0]]+=v[ps[i][2]];
				else v[ps[i][0]]-=v[ps[i][2]];
			}
			else{
				if(ps[i][3]==1) v[ps[i][0]]+=ps[i][2];
				else v[ps[i][0]]-=ps[i][2];
			}
			system("pause");
		}
		else if(sj[i]==2){
			int x;
			out(i,2);
			scanf("%d",&x);
			if(x==1) i=zs[i][0];
			else i=zs[i][1];
			system("pause");
		}
		else{
			out(i,3);
			if(ts[i][0]==0&&ts[i][2]==0){
				if(ts[i][1]>ts[i][3]) i=ts[i][4];
				else i=ts[i][5];
			}
			else if(ts[i][0]==1&&ts[i][2]==0){
				if(v[ts[i][1]]>ts[i][3]) i=ts[i][4];
				else i=ts[i][5];
			}
			else if(ts[i][0]==0&&ts[i][2]==1){
				if(ts[i][1]>v[ts[i][3]]) i=ts[i][4];
				else i=ts[i][5];
			}
			else if(ts[i][0]==1&&ts[i][2]==1){
				if(v[ts[i][1]]>v[ts[i][3]]) i=ts[i][4];
				else i=ts[i][5];
			}
			system("pause");
		}
	}
	out(0,0);
	return;
}

void in(int i){
	char l;
	int x;
	qkqn();
	scanf("%c",&l);
	if(l=='v'){
		sj[i]=1;
		scanf("%d",&x);
		ps[i][0]=x;
		qkqn();
		scanf("%c",&l);
		if(l=='+') ps[i][3]=1;
		else ps[i][3]=0;
		qkqn();
		scanf("%c",&l);
		if(l=='c'){
			ps[i][1]=0;
			scanf("%d",&x);
			ps[i][2]=x;
		}
		else{
			ps[i][1]=1;
			scanf("%d",&x);
			ps[i][2]=x;
		}
	}
	else if(l=='s'){
		sj[i]=2;
		scanf("%d%d",&zs[i][0],&zs[i][1]);
	}
	else if(l=='i'){
		sj[i]=3;
		qkqn();
		scanf("%c",&l);
		if(l=='c')
			ts[i][0]=0;
		else
			ts[i][0]=1;
		scanf("%d",&x);
		ts[i][1]=x;
		qkqn();
		scanf("%c",&l);
		if(l=='c')
			ts[i][2]=0;
		else
			ts[i][2]=1;
		scanf("%d",&x);
		ts[i][3]=x;
		scanf("%d%d",&ts[i][4],&ts[i][5]);
	}
	return;
}

int main(){
	freopen("train1.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=0;i<=m;i++) v[i]=0;
	for(int i=1;i<=n;i++) in(i);
	fclose(stdin);
	control();
	return 0;
}