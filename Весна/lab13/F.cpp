#include <iostream>
#include <string>
#include <vector>

std::vector<int> zfunc(std::string& s){
	int n=s.length();
	std::vector<int> z(n,0);
	int l=0,r=0;
	for(int i=1;i<n;++i){
		if(i<=r)
			z[i]=std::min(r-i+1,z[i-l]);
		while(z[i]+i<n and s[z[i]]==s[i+z[i]])
			++z[i];
		if(i+z[i]-1>r){
			l=i;
			r=i+z[i]-1;
		}
	//	std::cout<<l<<" "<<r<<'\n';
	}
	return z;
}

int main(){
	std::string s;
	std::cin>>s;
	int n=s.length();
	std::vector<int> ans=zfunc(s);
	bool f=false;
	for(int i=0;i<ans.size();++i){
		if(i+ans[i]==n){
			f=true;
			std::cout<<n/i;
			break;
		}
	}
	if(not f) std::cout<<1;
}
