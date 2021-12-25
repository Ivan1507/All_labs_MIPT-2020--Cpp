#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <queue>


bool search(std::queue<std::pair<int,int>> q,int x,int y){
	while(not q.empty()){
		std::pair<int,int> par=q.front();
		if(par.first==x&&par.second==y)
			return true;
		q.pop();
	}
	return false;
}

void print(std::queue<std::pair<int,int>> q){
	while(not q.empty()){
		std::pair<int,int> par=q.front();
		std::cout<<par.first<<" "<<par.second<<"\n";
		q.pop();
	}
}

int main(){
	int n,t,l;
	std::cin>>n>>t>>l;
	bool T[n];
	bool used[n];
	for(int i=0;i<n;++i){
		T[i]=false;
		used[i]=false;
	}
	for(int i=0;i<t;++i){
		int x;
		std::cin>>x;
		T[x]=true;
	}
	std::multimap<int,std::pair<char,int>> mymap;
	for(int i=0;i<n*l;++i){
		int s1,s2;
		char sym;
		std::cin>>s1>>sym>>s2;
		mymap.insert(std::make_pair(s2,std::make_pair(sym,s1)));
	}
	/*for(auto it:mymap){
		std::cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<'\n';
	}*/

	std::queue<std::pair<int,int>> Q;
	std::vector<std::vector<int>> dis(n,std::vector<int>(n,0));
	for(int i=0;i<n-1;++i){
		for(int j=i+1;j<n;++j){
			if((T[i]&&not T[j])){
				dis[i][j]=dis[j][i]=1;
				Q.push(std::make_pair(j,i));	
				//Q.push(std::make_pair(i,j));

			}
			else if(not T[i]&&T[j]){
				dis[i][j]=dis[j][i]=1;	
				Q.push(std::make_pair(i,j));	
				Q.push(std::make_pair(j,i));

			}
		}
	}
//	print(Q);
//	std::cout<<"--------\n";
	while(not Q.empty()){
		std::pair<int,int> par=Q.front();		
		char c='a';
		for(int s=0;s<l;++s){
			auto it=mymap.lower_bound(par.first);
			for(it;it!=mymap.end()&&it->first==par.first;++it){
				if(it->second.first==c){
					auto it1=mymap.lower_bound(par.second);
					for(it1;it1!=mymap.end()&&it1->first==par.second;++it1){
						if(it1->second.first==c){
							int i=it->second.second;
							int j=it1->second.second;
							if(not dis[i][j]){
								dis[i][j]=dis[j][i]=1;
								Q.push(std::make_pair(i,j));
								Q.push(std::make_pair(j,i));
							}
						}
					}
				}
			}
			++c;
		}
		Q.pop();
	}
	int ans=2;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(i>j){
				if(not dis[i][j]) ++ans;
			}
		}
		//std::cout<<'\n';
	}
	ans-=2;
	std::cout<<n-ans<<'\n';


}
