#include <iostream>
#include <vector>
#include <string>



bool check(std::string& s,std::string& t,int start){
	int l=s.length();
	int r=start;
	//for(int i=0;i<l/8;++i){
		//std::cout<<s[i]<<" "<<t[start]<<" "<<s[l-i-1]<<" "<<t[r+l-i-1]<<'\n';
		//if(not(s[i]==t[start]&&s[l-i-1]==t[r+l-i-1]))
			//return false;
		//++start;
	//}
	if(not (s[l/2]==t[start+l/2]&&s[1]==t[start+1]&&s[l-2]==t[start+l-2]))
		return false;
	return true;
}

int main(){

	std::string s, t; // входные данные
	std::cin>>s>>t;
// считаем все степени p
const int p = 31;
std::vector<long long> p_pow (std::max (s.length(), t.length()));
p_pow[0] = 1;
for (size_t i=1; i<p_pow.size(); ++i)
	p_pow[i] = p_pow[i-1] * p;

// считаем хэши от всех префиксов строки T
std::vector<long long> h (t.length());
for (size_t i=0; i<t.length(); ++i)
{
	h[i] = (t[i] - 'a' + 1) * p_pow[i];
	if (i)  h[i] += h[i-1];
}


// считаем хэш от строки S
long long h_s = 0;
for (size_t i=0; i<s.length(); ++i)
	h_s += (s[i] - 'a' + 1) * p_pow[i];

	int c=s.length();
	int g=t.length();
// перебираем все подстроки T длины |S| и сравниваем их
bool is=false;
for (size_t i = 0; i <=g-c; ++i)
{
	long long cur_h = h[i+s.length()-1];
	if (i)  cur_h -= h[i-1];
	// приводим хэши к одной степени и сравниваем
	if (cur_h == h_s * p_pow[i]){
		if(check(s,t,i)){
			is=true;
			std::cout<<i<<" ";
		}
	}
}
if(not is) std::cout<<-1;
}
