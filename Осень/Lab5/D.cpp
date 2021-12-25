#include <iostream>
#include <vector>


int main(){
	int A;
	std::cin>>A;
	int N;
	std::cin>>N;
	int M;
	std::cin>>M;
	std::vector<std::pair<int,std::pair<int,char>>> v(M);
	for(int i=0;i<M;i++){
		int x,y;
		char A;
		std::cin>>x>>y>>A;
		v[i]=std::make_pair(x,std::make_pair(y,A));

	}
	int t_end;
	std::cin>>t_end;
	int Ts[t_end];
	for(int i=0;i<t_end;i++)
		std::cin>>Ts[i];
	int k;
	std::cin>>k;
	int current_pos=0;
	while(k--){
		std::string tmp;
		std::cin>>tmp;
		bool ans=false;
		bool is=false;
		for(int i=0;i<tmp.length();++i){
			is=false;
			for(int k=0;k<M;++k){
				if(v[k].first==current_pos){
					//std::cout<<v[k].second.second<<" "<<tmp[i]<<"\n";
					if(v[k].second.second==tmp[i]){
						is=true;
						current_pos=v[k].second.first;
						break;
					}
				}
			}
			if(not is)
				break;
			std::cout<<current_pos<<" ";
		}
		//std::cout<<current_pos<<"\n";
		if(is){
		for(int j=0;j<t_end;j++){
			if(Ts[j]==current_pos){
				ans=true;
				break;
			}
		}
		}

		current_pos=0;
		std::cout<<ans<<" ";
	}
}
