#include <iostream>

int main(){
#ifdef COR
	std::cout<<"Hello!\n";
#else
	std::cout<<"Goodbue!\n";
#endif
}
