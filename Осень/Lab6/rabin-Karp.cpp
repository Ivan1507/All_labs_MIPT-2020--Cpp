#include <string>
#include <vector>
#include <iostream>


int binpow(int a,int k){
	if(k==0)
		return 1;
	if(k%2==0){
		int b=binpow(a,k/2);
		return b*b;
	}
	else
		return binpow(a,k-1)*a;
}

int64_t hash(std::string s,long long p){
	int l=s.length();
	int64_t ans=0;
	int pi=13;
	for(int i=0;i<l;++i){
		ans+=(binpow(pi,l-i-1)*s[i])%p;
	}
	return ans;
}
int64_t hash1(std::string s,long long p,int n){
	int64_t ans=0;
	int pi=13;
	for(int i=0;i<n;++i){
		ans+=(binpow(pi,n-i-1)*s[i])%p;
	}
	return ans;
}

bool check(std::string& p,std::string& s,int start){
	for(int i=0;i<p.length();++i){
		if(p[i]!=s[start]) return false;
		++start;
	}
	return true;
}
	
int main(){
	long long E=1e9+7;
	std::string s,p;
	std::cin>>p>>s;
	int r=p.length();
	int64_t hashS=hash1(s,E,r);
	int64_t hashP=hash(p,E);
	int n=s.length();
	int m=p.length();
	int pi=13;
	int col=n-m;
	bool is=false;
	for(int i=0;i<=col;++i){
		if(hashS==hashP) {
			if(check(p,s,i)){
				std::cout<<i<<" ";
				is=true;
				}
		}
		hashS=(hashS*pi-binpow(pi,m)*s[i]+s[m+i]);
		//std::cout<<hashP<<" "<<hashS<<"\n";	
	}
	if(not is) std::cout<<-1;
}
