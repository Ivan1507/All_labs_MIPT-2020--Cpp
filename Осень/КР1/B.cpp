#include <iostream>
#include <string>
#include <queue>
#include <stack>

bool foo(std::string& s){
	int n=s.length();
	if(n==0) return true;
	std::queue<std::string> que;
	bool is=false;
	std::string tmp;
	for(int i=0;i<n;++i){
		if(is){
			tmp+=s[i];
		}
		if(s[i]=='<')
			is=true;
		else if(s[i]=='>'){
			is=false;
			tmp.pop_back();
			que.push(tmp);
			tmp="";
		}
	}
	if(que.size()&1==1) return false;
	//int t=0;
	std::stack<std::string> sp;
	bool isstart=false;
	while(not que.empty()){
		std::string tmp1=que.front();
		if(tmp1[0]=='/'){
			isstart=true;
			if(sp.empty()) return false;
			std::string tmp2=sp.top();
			tmp1.erase(0,1);
			//std::cout<<tmp1<<" "<<tmp2<<'\n';
			if(tmp1!=tmp2){
				//std::cout<<"123\n";
					return false;
			}
			sp.pop();
		}
		else{
			if(sp.empty()&& isstart) return false;
			sp.push(tmp1);

		}
		que.pop();
	}
	return sp.empty();
}

int main(){
	std::string s;
	std::getline(std::cin,s);
	if(foo(s)) std::cout<<"YES\n";
	else std::cout<<"NO\n";
}
