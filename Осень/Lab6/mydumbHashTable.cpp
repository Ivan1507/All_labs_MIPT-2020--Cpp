#include <iostream>
#include <vector>
#include <list>


class HashTable{
	private:
		int capacity;
		std::vector<std::list<std::pair<int,int>>> arr;
		double a=0.75;

	public:
		HashTable(int m):capacity(m),arr(m){}
		
		int hash(int key) const{
			return int(a*key)%capacity;
		}
		int search(int key,int value) const{
			int ind=hash(key);
			auto it=arr[ind].begin();
			auto en=arr[ind].end();
			int ans=value;
			while(it!=en){
				if(it->first==key){
					ans=it->second;
					break;
				}
				++it;
			}
			return ans;
		}
		void insert(int key,int value){//Обязательно проверять сам ключ, а не только хэш
			int ind=hash(key);
			auto it=arr[ind].begin();
			auto en=arr[ind].end();
			while(it!=en){
				if(it->first==key){
					it->second=value;
					return;
				}
				++it;
			}
			arr[ind].push_front(std::make_pair(key,value));
			return;
		}
		void erase(int key,int value){//Todo проверка на то, что вообще есть такой ключ 
			int ind=hash(key);
			auto it=arr[ind].begin();
			auto en=arr[ind].end();
			while(it!=en){
				if(it->first==key){
					arr[ind].erase(it);
					return;
				}
				++it;
			}
			return;
		}
		int get_arr() const{
			return arr.size();
		}
};

int main(){
	std::ios_base::sync_with_stdio(false);	
	std::cin.tie(nullptr);
	int n,m;
	std::cin>>n>>m;
	HashTable arrhash(10000000);
	for(int i=0;i<m;++i){
		int index,key,value;
		char op;
		std::cin>>index>>op>>key>>value;
		key=index+key*n;
		if(op=='?'){
			std::cout<<arrhash.search(key,value)<<'\n';
		}
		else if(op=='+'){
			arrhash.insert(key,value);
		}
		else arrhash.erase(key,value);
		
	}
}
