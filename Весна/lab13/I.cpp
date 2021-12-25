#include <iostream>


bool isprefix(std::string s,int n,int i,int k){
	for(int j=0;j<k;++j){
	//	std::cout<<i<<" "<<s[i]<<" "<<j<<" "<<s[j]<<'\n';
		if(s[i]!=s[j])
			return false;
		++i;
	}
	return true;
}

int period(std::string s){
	int n=s.length();
	for(int i=1;i<=n/2;++i){
		if(s[i]==s[0]){
			//std::cout<<k;
			for(int j=i;j<n;j+=i){
				//std::cout<<s[j]<<" ";
				if(not isprefix(s,n,j,i))
						return 1;
			}
			return n/i;
			

				}
	}
	return 1;
}

int main(){
	std::string s;
	std::getline(std::cin,s);
	std::cout<<period(s);
}
