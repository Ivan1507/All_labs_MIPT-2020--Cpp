#include <iostream>
#include <vector>
#include <math.h>

bool isprime(int n){
if(n<2) return false;
if(n==2) return true;
for(int i=2;i<=sqrt(n);i++){
	if(n%i==0) return true;
}
return false;

}
int NOD(int a,int b){
	return b?NOD(b,a%b):a;
}

bool check(std::vector<int>& v,int n,std::vector<int>& is){
	for(int i=0;i<n-1;i++){
		if(is[i]){
			for(int j=i+1;j<n;j++)
				if(NOD(v[i],v[j])!=1) return true;
			}	
	}
	return false;
}
void print(const std::vector<int>& v){
	for(auto i:v)
		std::cout<<i<<" ";
	std::cout<<'\n';
}
void generate(std::vector<int> p,std::vector<int> tmp,int top,int l,int s,int& ans){
	if(top==l){
		//print(tmp,l);
		bool is[5];
	}
	else{
		for(int i=s;i<p.size();i++){
			tmp.push_back(p[i]);
			s+=1;
			generate(p,tmp,top+1,l,s,ans);
			tmp.pop_back();
		}
	}
}
int main(){
	std::ios_base::sync_with_stdio(false);	
	std::cin.tie(nullptr);
	int n;
	std::cin>>n;
	std::vector<int> p(n);
	std::vector<int> is(n);
	for(int i=0;i<n;i++){
		std::cin>>p[i];
		if(isprime(p[i])) is[i]=1;
		else is[i]=0;	
	}
	int64_t ans=0;
	for(int k=0;k<(1<<n);++k){
			std::vector<int> tmp;
			std::vector<int> tmp_is;
			for(int j=0;j<n/2;++j){
				if(k&(1<<j)){
					tmp.push_back(p[j]);
					tmp_is.push_back(is[j]);
				}
			}
			//print(tmp);
			if(not check(tmp,tmp.size(),tmp_is)) ans+=1;
			//std::cout<<ans<<" \n";
	}
	
	//std::cout<<ans<<'\n';
	
	std::cout<<ans<<'\n';


}
