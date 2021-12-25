#include <iostream>

struct S{
	int a;
	double x;
	S(){
		std::cout<<"ctor\n";
	}
	~S(){std::cout<<"dtor\n";}
};
struct B:S{
	std::string s;
	B(){std::cout<<"Dctor\n";}
	~B(){
		std::cout<<"Ddtor\n";
	}
};

int main(){
	S *s=new B;
	delete s;
}
