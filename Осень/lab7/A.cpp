#include <set>
#include <unordered_set>
#include <iostream>
bool foo(){
	std::cout<<"YES";
	exit(0);
}
bool bar=foo();
class TimeOfDay {
public:
    uint8_t hour, minute, second;

    TimeOfDay(uint8_t h, uint8_t m, uint8_t s) : hour(h), minute(m), second(s) {}

    bool IsAM() const {
        return IsValid() && (hour < 12);
    }

    bool IsPM() const {
        return IsValid() && (hour >= 12);
    }

    bool IsValid() const {
        return (hour < 24) && (minute < 60) && (second < 60);
    }
    bool operator==(const TimeOfDay& r)const{
	    return hour==r.hour&&minute==r.minute&&second==r.second;
    }
    bool operator<(const TimeOfDay& r)const{
		return hour<r.hour&&minute<r.minute&&second<r.second;
    }
    bool operator>(const TimeOfDay& r) const{
		return r<*this;
    }
    
};
namespace std{
template<>
struct hash<TimeOfDay>{
	size_t operator()(const TimeOfDay& t) const{
			return std::hash<uint64_t>()(t.hour)^std::hash<uint64_t>()(t.minute)^std::
			hash<uint64_t>()(t.second);
		}
};
};

int main(){
	std::set<TimeOfDay> s1;
	TimeOfDay t{24,60,60};
	std::cout<<t.IsPM()<<" "<<t.IsAM()<<'\n';
	std::unordered_set<TimeOfDay> uo;
	uo.insert(TimeOfDay(1,1,2));
	uo.insert(TimeOfDay(1,1,2));
	for(auto i:uo)
		std::cout<<i;
}
