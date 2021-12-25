#include <iostream>
#include <stack>


int main(){
	std::string p;
	std::getline(std::cin,p);
	std::stack<int> s;
	char op;
	std::string tmp;
	int64_t ans=0;
	bool used=false;
	for(int i=0;i<p.length();++i){
		if((p[i]=='+'||p[i]=='/'||p[i]=='*')||(p[i]=='-'&&(p[i+1]=='\0'||p[i+1]==' '))){
			int j=s.top();
			s.pop();
			int k=s.top();
			s.pop();
			switch(p[i]){
				case '+':
					k+=j;	
					break;
				case '-':
					k-=j;
					break;
				case '*':
					k*=j;
					break;
				case '/':
					k/=j;
					break;

			}
			s.push(k);
			//std::cout<<p[i]<<" "<<ans<<" ";	
		}
		else if(p[i]!=' ')
			tmp+=p[i];
		else{
			//std::cout<<tmp<<" "; 
			if(tmp.size()) s.push(std::atoi(tmp.c_str()));
			tmp="";
			//std::cout<<s.size();
			//std::cout<<s.top()<<" ";
			
		}
		
		

			

	}
	std::cout<<s.top();
	/*while(not s.empty()){
		std::cout<<s.top()<<" ";
		s.pop();
	}*/

}
