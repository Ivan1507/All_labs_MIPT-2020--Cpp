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

std::vector<int64_t> hash(std::string s){
	std::vector<int64_t> ans;
	int64_t pans=0;
	int n=s.length();
	int pi=13;
	int count=0;
	for(int i=0;i<n;++i){
		if(count==10){
			ans.push_back(pans);
			pans=(pans*pi-binpow(pi,10)*s[i-10]+s[i]);
		}
		else{
		++count;
		pans+=(binpow(pi,10-count)*s[i]);
		}
		

	}
	return ans;
}

int main(){
	std::string s;
	std::getline(std::cin,s);
	std::vector<int64_t> hashes=hash(s);
	int n=hashes.size();
	for(auto i:hashes)
		std::cout<<i<<" ";
	std::vector<std::string> anses;
	for(int i=0;i<n-10;++i){
		for(int j=i+10;j<n;++j){
			if(hashes[i]==hashes[j])
				anses.push_back(s.substr(i*10,(i+1)*10));
		}
	}
	for(auto i:anses)
		std::cout<<i<<" ";
}
