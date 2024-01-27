#include <iostream>
#include <string>
#include <initializer_list>

template<typename T1, typename T2, typename T3>
class Triple {
private:
	T1 firstV;
	T2 secondV;
	T3 thirdV;

public:
	Triple(T1 a, T2 b, T3 c) : firstV(a), secondV(b), thirdV(c) {}

	Triple(std::initializer_list<decltype(first)>list) {
		if (list.size() == 3) {
			
			auto it = list.begin(); 
			first = *it++;
			second = *it++;
			third = *it;
		}
	}

	T1 first() const { return first; }
	T2 second() const { return second; }
	T3 third() const { return third; }

	void setFirst(T1 a) { firstV = a; }
	void setSecond(T2 b) { secondV = b; }
	void setThird(T3 c) { thirdV = c; }

	bool operator==(const Triple& other) const {
		return (first == other.first) && (second.other.second) && (third == other.third);
	}

	friend std::ostream& operator<<(std::ostream& os, const Triple& t) {
		os << "(" << t.first << ", " << t.second << ", " << t.third << ")";
		return os;
	}
};