#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main(){
	int n;
	std::cin>>n;
	std::vector<int> v(n);
	char t;
	for(int i=0;i<n;++i)
		std::cin>>v[i];
	std::sort(v.begin(),v.end());
	int i,j,k;
	std::vector<std::string> ans;
	for(i=0;i<n;++i){
		if(i!=0&&v[i]==v[i-1]) continue;
		int j=i+1;
		int k=n-1;
		while(j<k){
			if(v[i]+v[j]+v[k]==0){
				std::string tmp=std::to_string(v[i])+" "+
					std::to_string(v[j])+" "+std::to_string(v[k]);
				//std::cout<<tmp;
				ans.push_back(tmp);
				++j;
				while(j<k && v[j]==v[j-1]) ++j;
			}
			else if(v[i]+v[j]+v[k]>0)
				--k;
			else ++j;
		}
	}
	for(auto i:ans)
		std::cout<<i<<" ";


}
