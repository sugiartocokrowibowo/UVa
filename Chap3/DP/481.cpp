#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair	

typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<LL> v,ans;

void LIS(){
	vector<LL> lis,lis_index;
	vector<LL> parent(v.size(),-1);
	lis.pb(v[0]);
	lis_index.pb(0);
	for(int i=1;i<v.size();i++){
		auto it=lower_bound(lis.begin(),lis.end(),v[i]);
		if(it==lis.end()){
			parent[i]=lis_index.back();
			lis.pb(v[i]);
			lis_index.pb(i);
		}
		else{
			int idx=it-lis.begin();
			if(idx>0)parent[i]=lis_index[idx-1];
			lis[idx]=v[i];
			lis_index[idx]=i;
		}
	}
	for(int i=lis_index.back();i>=0;i=parent[i])ans.pb(v[i]);
	reverse(ans.begin(),ans.end());
}
int main(){
	LL n;
	while(cin>>n){
		v.pb(n);
	}
	LIS();
	printf("%d\n-\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}