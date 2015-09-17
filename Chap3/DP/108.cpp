#include <bits/stdc++.h>
using namespace std;

#define icin(x) scanf("%d",&x)
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi v,dp;
vi arr;
int n;

void precompute(){
	dp.resize(n+1,vi(n,0));
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			dp[i][j]+=v[i][j]+dp[i-1][j];
		}
	}
}
int maxSubarray(int a,int b){
	arr.resize(n);
	arr[0]=dp[b][0]-dp[a][0];
	int maxi=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i-1]>0)
			arr[i]=arr[i-1]+(dp[b][i]-dp[a][i]);
		else
			arr[i]=(dp[b][i]-dp[a][i]);
		maxi = max(maxi,arr[i]);
	}
	return maxi;
}
int main(){
	icin(n);
	v.resize(n+1,vi(n));
	for(int i=1;i<=n;i++)
		for(int j=0;j<n;j++)
			icin(v[i][j]);
	
	precompute();
	int ans=-int(1e9);
	for(int a=1;a<=n;a++){
		for(int b=a;b<=n;b++){
			ans = max(ans,maxSubarray(a-1,b));
		}
	}
	printf("%d\n",ans);
	return 0;
}