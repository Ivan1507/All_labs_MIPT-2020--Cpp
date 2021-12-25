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
		bool dp[len][N];
		for(int i=0;i<len;++i){
			for(int j=0;j<N;++j){
				dp[i][j]=false;
			}
		}
		dp[0][0]=true;
		for(int i=0;i<len;++i){
			for(int q=0;q<N;++q)
				std::cout<<dp[i][q]<<" ";
			std::cout<<'\n';
		}


		for(int i=0;i<tmp.length();++i){
			for(int q=0;q<N;++q){
				if(dp[i][q]){
					for(int r=0;r<M;++r){
						if(q==v[r].first)
							if(tmp[i]==v[r].second.second)
								dp[i+1][v[r].second.first]=true;
					}	
				}
			}
		}

		std::cout<<"after\n";
		for(int i=0;i<len;++i){
			for(int q=0;q<N;++q)
				std::cout<<dp[i][q]<<" ";
			std::cout<<'\n';
		}


		for(int q=0;q<N;++q){
			if(dp[len-1][q] && T[q]){
				ans=true;
				break;
			}
		}
		current_pos=0;
		std::cout<<"ans is "<<ans<<" ";
	}
}
