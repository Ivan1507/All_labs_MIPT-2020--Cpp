#include <vector>
#include <string>
#include <iostream>

template<class T>
using vec=std::vector<T>;

void func(vec<vec<char>>& v,int& pos,char find){
	for(int i=(pos-1)*4;i<pos*4;++i){
		if(v[i][3]==find){
			std::cout<<v[i][1];
			pos=v[i][2];
			break;
		
		}
	}
}


int main(){
	int n;
	std::cin>>n;
	vec<vec<char>> table(n*4,vec<char>(4));
	for(int i=0;i<table.size();++i){
		for(int j=0;j<table[i].size();++j){
			std::cin>>table[i][j];
			std::cout<<table[i][j]<<" ";
		}
		std::cout<<'\n';
	}
	std::string k;
	std::getline(std::cin,k);
	std::cout<<"Out kod is "<<k<<"\n";
	int pos=1;
	//std::cout<<"123";
	for(int i=0;i<k.length();++i){
		std::cout<<k[i]<<" ";
		func(table,pos,k[i]);
	}
}
