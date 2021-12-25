#include <iostream>
#include <vector>
#include <functional>


template<class RandomIt,class Comparator>
RandomIt Partition(RandomIt first,RandomIt last,Comparator comp){
	auto pivot=std::prev(last,1);
	auto i=first;
	for(auto j=first;j!=pivot;++j){
		if(comp(*j,*pivot))
			std::swap(*i++,*j);
	}
	std::swap(*i,*pivot);
	return i;
}


template<class T,class Comparator=std::less<T>>
void Sort(std::vector<T>* v,Comparator comp=Comparator{}){
	int n=v->size();
	if(n<=1)
		return;
	int middle=n/2;
	int lz=middle;
	int rz=n-middle;
	std::vector<T> left(v->begin(),v->begin()+middle);
	std::vector<T> right(v->begin()+middle,v->end());
	//std::cout<<left.size()<<" "<<right.size()<<"\n";
	Sort(&left);
	Sort(&right);
	int li=0;
	int ri=0;
	int bi=0;
	std::vector<T> buf(n);
	while(li<lz and ri<rz){
		if(comp(left[li],right[ri])){
			buf[bi++]=left[li++];
		}
		else
			buf[bi++]=right[ri++];
	}
	while(li<lz)
		buf[bi++]=left[li++];
	while(ri<rz)
		buf[bi++]=right[ri++];
	auto s=v->begin();
	for(int i=0;i<n;++i)
		*(s+i)=buf[i];

}


template<class RandomIt,class Comparator=std::less<typename std::iterator_traits<RandomIt>::value_type>>
void Sort(RandomIt first,RandomIt last,Comparator comp=Comparator{}){
	std::vector<typename std::iterator_traits<RandomIt>::value_type> v(first,last);
	Sort(&v,comp);
	/*if(last>first+1){
		RandomIt bound=Partition(first,last,comp);
		Sort(first,bound,comp);
		Sort(bound,last,comp);
	}*/

}




int main() {
    {
        std::vector < int32_t > a{4, 3, 2, 1};
        Sort(a.begin(), a.end(),std::less<int32_t>());
        for (auto i: a) { std::cout << i << " "; }
        // 1 2 3 4
        std::cout << "\n";
    }
    {
        std::vector < int32_t > a{4, 3,5, 2, 1};
        Sort(&a);
        for (auto i: a) { std::cout << i << " "; }
        // 1 2 3 4
        std::cout << "\n";
    }
    {
        std::vector < int32_t > a{1, 2, 3, 4};
        Sort(a.begin(), a.end(), std::greater< int32_t >());
        for (auto i: a) { std::cout << i << " "; }
        // 4 3 2 1
        std::cout << "\n";
    }
}
