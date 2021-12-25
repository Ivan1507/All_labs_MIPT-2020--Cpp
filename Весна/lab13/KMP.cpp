#include <iostream>
#include <vector>
#include <string>

std::vector<int> kmp(std::string& s){
	int n=s.length();
	std::vector<int> pi(n,0);
	for(int i=1;i<n;++i){
		int x=pi[i-1];
		bool f=false;
		while(x>0 and s[i]!=s[x])
			x=pi[x-1];
		
		if(s[i]==s[x]) 
			x+=1;
		pi[i]=x;
	}
	return pi;
}


int main(){
	std::string s,t;
	std::cin>>t>>s;
	int n=t.length();
	t.push_back('#');
	t+=s;
	//std::cout<<t<<" \n";
	bool used=false;
	int le=n+1;
	std::vector<int> ans=kmp(s);
	for(int i=0;i<ans.size();++i){
		std::cout<<ans[i]<<" ";
	}
}
