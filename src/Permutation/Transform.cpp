#include "Transform.hpp"
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <cmath>


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
		for (int i = 0; i < mask1.size(); i += 1)
		{
			if( (mask1[i] && text1[i]) ^ (mask2[i] && text2[i]) )
				return false;
		}
		/*
			if ((mask1[i] && mask2[i] && (text1[i] != text2[i]))   || 
				(mask1[i] && !(mask2[i]) && (text1[i] != 0)) ||
				(mask2[i] && !(mask1[i]) && (text2[i] != 0)) )
				return false;
		*/
		/*
			if(mask1[i])
			{
				if(mask2[i])
				{
					if(text1[i] != text2[i])
						return false;
				}
				else
				{
					if(text1[i] != 0)
						return false;
				}
			}
			else
			{
				if(mask2[i])
				{
					if(text2[i] != 0)
						return false;
				}
			}
		}
		*/
		return true;
	}
}