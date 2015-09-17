#include <bits/stdc++.h>
using namespace std;

#define icin(x) scanf("%d",&x)
#define lcin(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair	

typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<LL> v;

LL solve(){
	vector<pair<LL,LL> > lis,lds;
	vector<LL> vneg;
	for(auto _v:v)vneg.pb(-_v);
	
	lis.pb(mp(v[0],0));
	lds.pb(mp(vneg[0],0));
	int l1=1,l2=1,maxi=l1+l2-1;
	for(int i=1;i<v.size();i++){
		auto it1=lower_bound(lis.begin(),lis.end(),mp(v[i],0LL));
		auto it2=lower_bound(lds.begin(), lds.end(),mp(vneg[i],0LL));
		if(it1==lis.end()){
			l1=lis.size()+1;
			lis.pb(mp(v[i],i));
		}
		else{
			l1=it1-lis.begin()+1;
			*it1=mp(v[i],i);	
		}
		if(it2==lds.end()){
			l2=lds.size()+1;
			lds.pb(mp(vneg[i],i));
		}
		else{
			l2=it2-lds.begin()+1;
			*it2=mp(vneg[i],i);	
		}
		maxi = max(l1+l2-1,maxi);
	}
	return maxi;
}
int main(){
	int t;
	icin(t);
	while(t--){
		int n;
		icin(n);
		if(n==0){
			printf("0\n");
			continue;
		}
		v.resize(n);
		for(int i=0;i<v.size();i++)lcin(v[i]);
		reverse(v.begin(),v.end());
		printf("%lld\n",solve());
	}
	return 0;
}