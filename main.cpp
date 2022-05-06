#include <string>
#include <iostream>
#include "lab.hpp"
#include "rabin_karp_search.cpp"

int main(){
	//lab2::asig1();
	//lab2::asig2();
	//lab2::asig3();
	//lab2::asig4();
	rabin_karp::my_tuple vec = rabin_karp::search("hello", "/home/meneses/Documents/algo_analisis/tests/rabin_karp/test_1.txt", 256);
	for(auto x : vec){
		std::cout<< "ROW: "<< std::get<0>(x) << "  " << "COLUMN: " << std::get<1>(x) << std::endl;
	}

	return 0;	
}
