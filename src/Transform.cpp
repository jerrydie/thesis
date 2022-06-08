#include "Transform.hpp"
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <cmath>
#include <random>


namespace thesis
{
	    
	std::vector<uint8_t> split(uint32_t num, std::size_t size_, uint16_t radix)
	{
		uint32_t cp = num;
		std::vector<uint8_t> arr;
		while(cp > 0)
		{
			arr.push_back(cp%radix);
			cp = cp / radix;
		}
		arr.resize(size_, 0);
		return arr;
	}

	std::vector<bool> split(uint32_t num, std::size_t size_)
	{
		uint32_t cp = num;
		std::vector<bool> arr;
		while(cp > 0)
		{
			arr.push_back(cp%2);
			cp = cp / 2;
		}
		arr.resize(size_, 0);
		return arr;
	}
	
	
	bool masking (std::vector<bool>& mask1, std::vector<bool>& text1, std::vector<bool>& mask2, std::vector<bool>& text2)
	{
		std::size_t bits1 = 0;
		std::size_t bits2 = 0;
		for (int i = 0; i < mask1.size(); i += 1)
		{
			bits1 += (mask1[i] && text1[i]);
			bits2 += (mask2[i] && text2[i]);
		}
		return ((bits1 & 1) == (bits2 & 1));
			
	}
	
	void Shuffle::RandomPermutation(){

	    uint32_t size_(1 << size);

	    static std::random_device rdev;
	    static std::mt19937 e(rdev());
	    static std::uniform_int_distribution<uint32_t> getAddr(0,size_-1);

	    int i;
	    int addr;
	    bool *x = new bool[size_];

	    for (i = 0; i != size_; ++i)
		x[i] = shuffle[i] = 0;

	    for (i = 0; i != size_; ++i){
		do{
		    addr = getAddr(e);
		}while(x[addr] != 0);
		shuffle[addr] = i;
		x[addr] = 1;
	    }

	    delete[] x;
	}

	Shuffle::Shuffle(std::size_t size, uint8_t radix) : size(size) // std::mt19937& g, distr_t& D, 
	{
		for(int i = 0; i < std::pow(radix, size); i += 1)
			shuffle.push_back(i);
			
		RandomPermutation();
	}
	
	uint32_t Shuffle::shuffle_text(uint32_t pt)
	{
		uint32_t ct = shuffle[pt];
		return ct;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	



}