
#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>


//     TEMPLATE FUNCTIONS
// use cases are in main()

template <typename T>
T maxof ( const T & a, const T & b ) {
    return ( a > b ? a : b );
}
//   the function below is an example of what is made at compile time
// when maxof<int>(a, b) is called
int maxof(const int & a, const int & b) {
	return (a > b ? a : b);
}

// template variable and its use case is below
template<typename T>
constexpr T pi = T(3.1415926535897932385L);

template<typename T>
T area_of_circle(const T& radius) {
	return radius * radius*pi<T>;
}


//   tsum function adds any type and returns 
// the type of the parameters that it is passed
template <typename lT, typename rT>
auto tsum(const lT&lhs, const rT& rhs) {
	return lhs + rhs;
}


template <typename T>
void tprintVec(const std::vector<T>&v) {
	if (v.empty()) { return; }
	for (const T& i : v) { std::cout << i << ", "; }
	std::cout << std::endl;
}


int main(int argc, char** argv) {
    int a = 3;
	int b = 12;
    
    std::cout << "max is " << maxof<int>( a, b ) << std::endl;
	//below we let the compiler deduce the type for the maxof template function
	std::cout << "max is " << maxof(a, b) << std::endl;


	std::cout.precision(20);
	std::cout << pi<long double> << " " << area_of_circle<long double>(3) << std::endl;
	
	const char * cstr = "this is a c-string";
	const std::string sclass = std::string("this is a string class string");

	// const char*
	auto x = "this is a c-string";
	// the decltype(x) declares varaiable y the same type as x
	decltype(x) y;

	std::cout << "type of a is " << typeid(a).name() << std::endl;
	std::cout << "type of cstr is " << typeid(cstr).name() << std::endl;
	std::cout << "type of sclass is " << typeid(sclass).name() << std::endl;
	std::cout << "type of x is " << typeid(x).name() << std::endl;
	std::cout << "type of y is " << typeid(y).name() << std::endl;

	// 'it' below, is given type string iterator
	for (auto it = sclass.begin(); it != sclass.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	//   same as the above for loop except using a range based for loop
	// the auto in the for loop is grabing the type of the elements in the container "sclass"
	// c is type char
	for (auto c : sclass) {
		std::cout << c << " ";
	}
	std::cout << std::endl;  


	auto z = tsum < std::string, const char*>(sclass, cstr);
	std::cout << "z is " << z << std::endl;
	std::cout << "type of z is: " << typeid(z).name() << std::endl;

	std::vector<int> v1 = { 1, 2, 3, 4, 5 };
	tprintVec<int>(v1);
	// below, the compiler automatically deduces type
	tprintVec(v1);

	std::string pause;
	std::cin >> pause;
    return 0;
}
