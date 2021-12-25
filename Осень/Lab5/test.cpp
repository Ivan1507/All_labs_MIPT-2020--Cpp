#include <iostream>
#include <map>

int main(){
	std::multimap<int,std::pair<char,int>> mymap;
	mymap.insert(std::make_pair(3,std::make_pair('a',3)));
	mymap.insert(std::make_pair(3,std::make_pair('b',3)));
	mymap.insert(std::make_pair(4,std::make_pair('b',3)));

	auto it=mymap.lower_bound(3);
	for(it;it!=mymap.end()&&it->first==3;++it){
		std::cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<"\n";
	}
}
