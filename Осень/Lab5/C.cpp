#include <vector>
#include <string>
#include <iostream>

template<class T>
using vec=std::vector<T>;

void func(vec<std::pair<char,std::pair<int,char>>>& v,int& pos,char find){
	for(int i=(pos-1)*4;i<pos*4;++i){
		if(v[i].second.second==find){
			std::cout<<v[i].first;
			pos=v[i].second.first;
			break;
		}
	}
}


int main(){
	int n;
	std::cin>>n;
	vec<std::pair<char,std::pair<int,char>>> table(n*4);
	for(int i=0;i<n*4;++i){
		int x,y;
		char A,B;
		std::cin>>x>>A>>y>>B;
		table[i]=std::make_pair(A,std::make_pair(y,B));
	}
	//for(int i=0;i<n*4;i++)
	//	std::cout<<i+1<<" "<<table[i].first<<" "<<table[i].second.first<<" "<<table[i].second.second<<"\n";
	std::string k;
	std::cin>>k;
	int pos=1;
	//std::cout<<k<<'\n';
	for(int i=0;i<k.length();++i){
		func(table,pos,k[i]);
		//std::cout<<pos<<" ";
	}
}
