#include "Transform.hpp"
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <cmath>
#include <random>


namespace thesis
{
	typedef typename std::iterator_traits<std::vector<bool>::iterator>::difference_type diff_t;
	typedef std::uniform_int_distribution<diff_t> distr_t;
	typedef typename distr_t::param_type param_t;
	    
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
	
	uint32_t aggregate(std::vector<uint8_t>& arr, uint16_t radix)
	{
		uint32_t num = 0;
		for (int i = 0; i < arr.size(); i += 1)
		{
			num += arr[i] * std::pow(radix, i);
		}
		return num;
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
	
	void RandomPermutation(std::size_t inLen, std::vector<uint32_t>& function){

	    uint32_t size(1 << inLen);

	    static std::random_device rdev;
	    static std::mt19937 e(rdev());
	    static std::uniform_int_distribution<uint32_t> getAddr(0,size-1);

	    int i;
	    int addr;
	    bool *x = new bool[size];

	    for (i = 0; i != size; ++i)
		x[i] = function[i] = 0;

	    for (i = 0; i != size; ++i){
		do{
		    addr = getAddr(e);
		}while(x[addr] != 0);
		function[addr] = i;
		x[addr] = 1;
	    }

	    delete[] x;
	}

	Shuffle::Shuffle(std::size_t size, uint8_t radix) : size(size) // std::mt19937& g, distr_t& D, 
	{
		for(int i = 0; i < std::pow(radix, size); i += 1)
			shuffle.push_back(i);
			
		RandomPermutation(size, shuffle);
		/*
		std::vector<uint32_t>::iterator first = shuffle.begin();
		std::vector<uint32_t>::iterator last  = shuffle.end();
		diff_t n = last - first;
		for(diff_t i = n - 1; i > 0; i -= 1)
		{
			using std::swap;
			swap(first[i], first[D(g, param_t(0, i))]);
		}
		*/
	}
	
	uint32_t Shuffle::shuffle_vector(uint32_t pt)
	{
		uint32_t ct = shuffle[pt];
		return ct;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	



}