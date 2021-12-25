#include <iostream>
#include <vector>

bool check(int *T,int n,std::vector<int>& ends){
	for(int i=0;i<ends.size();++i){
		for(int j=0;j<n;++j){
			if(ends[i]==T[j])
				return true;
		}
	}
	return false;
}

bool check(int *T,int n,int cur){
	for(int i=0;i<n;++i){
		if(T[i]==cur)
			return true;
	}
	return false;
}

void step1(std::vector<std::pair<int,std::pair<int,char>>>& v,int M){
	for(int i=0;i<M;i++){
		if(v[i].second.second=='E'){
			int from=v[i].first;
			int comp=v[i].second.first;
			for(int j=0;j<M;++j){
				if(v[j].first==comp && v[j].second.second=='E'){
						int where=v[j].second.first;
						//std::cout<<from<<" "<<where<<'\n';
						v.push_back(std::make_pair(from,std::make_pair(where,'E')));
				}
			}
		}
	}
}

void step2(std::vector<std::pair<int,std::pair<int,char>>>& v,int M,bool *T){
	for(int i=0;i<M;++i){
		if(v[i].second.second=='E'&&T[v[i].second.first])
			T[v[i].first]=true;
	}
}

void step3(std::vector<std::pair<int,std::pair<int,char>>>& v,int M){
	for(int i=0;i<M;++i){
		if(v[i].second.second=='E'){
			int from=v[i].second.first;
			int f1=v[i].first;
			for(int j=0;j<M;++j){
				if(v[j].first==from){
					int where=v[j].second.first;
					char sym=v[j].second.second;
					v.push_back(std::make_pair(f1,std::make_pair(where,sym)));
				}
			}
		}
	}
}
void step4(std::vector<std::pair<int,std::pair<int,char>>>& v,int M){
	auto it=v.begin();
	for(int i=0;i<v.size();++i){
		if(v[i].second.second=='E')
			v.erase(it+i);	
	}
}

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
	bool T[N];
	for(int i=0;i<N;++i)
		T[i]=false;
	for(int i=0;i<t_end;i++){
		int x;
		std::cin>>x;
		T[x]=true;	
	}
	step1(v,M);
	M=v.size();
	step2(v,M,T);
	step3(v,M);
	M=v.size();
	step4(v,M);
	M=v.size();
	/*for(int i=0;i<M;++i){
		std::cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<"\n";
	}*/




	int k;
	std::cin>>k;
	int current_pos=0;
	while(k--){
		std::string tmp;
		std::cin>>tmp;
		bool ans=false;
		bool is=false;
		bool our=false;
		int len=tmp.length();
		bool dp[len+1][N];
		for(int i=0;i<=len;++i){
			for(int j=0;j<N;++j){
				dp[i][j]=false;
			}
		}
		dp[0][0]=true;
		//std::cout<<dp[0][0]<<" 123\n";
		/*for(int i=0;i<=len;++i){
			for(int q=0;q<N;++q)
				std::cout<<dp[i][q]<<" ";
			std::cout<<'\n';
		}*/


		for(int i=1;i<=tmp.length();++i){
			for(int q=0;q<N;++q){
				if(dp[i-1][q]){
					for(int r=0;r<M;++r){
						if(q==v[r].first)
							if(tmp[i-1]==v[r].second.second)
								dp[i][v[r].second.first]=true;
					}	
				}
			}
		}

		//std::cout<<"after\n";
		/*for(int i=0;i<=len;++i){
			for(int q=0;q<N;++q)
				std::cout<<dp[i][q]<<" ";
			std::cout<<'\n';
		}*/


		for(int q=0;q<N;++q){
			if(dp[len][q] && T[q]){
				ans=true;
				break;
			}
		}
		current_pos=0;
		std::cout<<ans<<" ";
	}
}
