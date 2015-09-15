#include <bits/stdc++.h>
using namespace std;

#define icin(x) scanf("%d",&x)
#define lcin(x) scanf("%lld",&X)

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

vi v;
vi dp;
vi last;
int solve(int& a,int& b){
	dp.resize(v.size());
	last.resize(v.size());
	dp[0]=v[0];
	last[0]=0;
	for(int i=1;i<dp.size();i++){
		if(dp[i-1]>=0){
			last[i]=last[i-1];
			dp[i]=dp[i-1]+v[i];
		}
		else{
			last[i]=i;
			dp[i]=v[i];
		}
	}
	int maxi=dp[0];
	a=1;b=2;
	for(int i=1;i<dp.size();i++){
		if(dp[i]>maxi){
			maxi=dp[i],a=last[i]+1,b=i+2;
		}
		else if(dp[i]==maxi){
			if(( (i+2)-(last[i]+1) )>(b-a))
				a=last[i]+1,b=i+2;
		}
	}
	return maxi;
}

int main(){
	int  n;
	icin(n);
	for(int r=1;r<=n;r++){
		int s;
		icin(s);
		v.resize(s-1);
		for(int i=0;i<=s-2;i++){
			icin(v[i]);
		}
		int a,b;
		if(solve(a,b)>0){
			printf("The nicest part of route %d is between stops %d and %d\n",r,a,b);
		}
		else{
			printf("Route %d has no nice parts\n",r);
		}
	}
	return 0;
}