#include <bits/stdc++.h>
using namespace std;

#define icin(x) scanf("%d",&x)
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi v,dp;
vi arr,tmp,len;
int n;

void precompute(){
	dp.resize(2*n+1,vi(n,0));
	for(int j=0;j<n;j++)dp[0][j]=0;
	for(int i=1;i<=2*n;i++){
		for(int j=0;j<n;j++){
			dp[i][j]=(v[i][j]+dp[i-1][j]);
		}
	}
}
int maxSubarray(int a,int b){
	arr.resize(n);tmp.resize(n);len.resize(n);
	int sum=0;
	int flag=0;
	for(int i=0;i<n;i++){
		tmp[i]=dp[b][i]-dp[a][i];
		if(tmp[i]>=0)flag=1;
		sum+=tmp[i];
	}
	arr[0]=tmp[0];
	len[0]=1;
	int maxi=arr[0];
	for(int i=1;i<tmp.size();i++){
		if(arr[i-1]>0)
			arr[i]=arr[i-1]+tmp[i],len[i]=1+len[i-1];
		else
			arr[i]=tmp[i],len[i]=1;
		maxi = max(maxi,arr[i]);
	}
	int mini=arr[0];
	for(int i=1;i<tmp.size();i++){
		if(arr[i-1]<=0)
			arr[i]=arr[i-1]+tmp[i],len[i]=1+len[i-1];
		else
			arr[i]=tmp[i],len[i]=1;
		mini = min(mini,arr[i]);
	}
	if(flag)
	return max(maxi,sum-mini);
	else
		return maxi;
}
int main(){
	int t;
	icin(t);
	while(t--){
		v.clear();dp.clear();arr.clear();tmp.clear();len.clear();
		icin(n);
		v.resize(2*n+1,vi(n));
		for(int i=1;i<=n;i++)
			for(int j=0;j<n;j++){
				icin(v[i][j]);
				v[i+n][j]=v[i][j];
			}
		
		precompute();

		int ans=-int(1e9);
		for(int a=1;a<=n;a++){
			for(int b=a;b<=2*n && (b-a)<=n-1;b++){
				ans = max(ans,maxSubarray(a-1,b));
			}
		}
		printf("%d\n",ans);	
	}
	return 0;
}