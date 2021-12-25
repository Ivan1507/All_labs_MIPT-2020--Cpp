#include <iostream>
#include <string>
class Checker {
	private:
		int64_t cap=10000;
		bool *used;
public:
    Checker():used(new bool[cap]{0}){}
    ~Checker(){
	delete[] used;
    }
	int hash(const std::string& s){
		int64_t p=13;
		int ans=1;
		for(int i=0;i<s.length();++i){
			ans+=(s[i]*p);
			p*=p;
		}
		return ans%cap;

	}
    void Add(const std::string& s){
		int ind=hash(s);
		used[ind]=true;
    }
    bool Exists(const std::string& s){
		int ind=hash(s);
		return used[ind];
    }
};

int main(){
	Checker c;
	c.Add("abaaaa");
	std::cout<<c.Exists("abaaaa");
}
