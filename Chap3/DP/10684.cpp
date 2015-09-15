#include <bits/stdc++.h>
using namespace std;

#define icin(x) scanf("%d",&x)
typedef vector<int> vi;
typedef vector<vi> vvi;

vi v;
vi dp;
int solve(){
	dp.resize(v.size());
	dp[0]=v[0];
	int maxi=dp[0];
	for(int i=1;i<dp.size();i++){
		if(dp[i-1]>0)dp[i]=dp[i-1]+v[i];
		else dp[i]=v[i];
		maxi=max(maxi,dp[i]);
	}
	return maxi;
}


int main(){
	while(1){
		int n;
		icin(n);
		if(n==0)return 0;
		v.resize(n);
		for(int i=0;i<n;i++)icin(v[i]);
		int ans=solve();
		if(ans>0)
			printf("The maximum winning streak is %d.\n",ans);
		else
			printf("Losing streak.\n");
	}
	return 0;
}