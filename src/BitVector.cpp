#include "BitVector.hpp"

#include <algorithm>



namespace thesis::random_permutation 
{
	BitVector::BitVector(std::vector<bool>& content_) : size(content_.size()), content(content_)
	    {}

	BitVector::BitVector(const uint8_t text, const size_t size_)
	{
		size = size_;
		uint8_t text_copy = text;
	    	for (size_t j = size-1; j >= 0; j -= 1)
	    	{
	    		if (text_copy == 0)
	    		{
	    			content.resize(size, 0);
	    			break; 
	    		}
	    		content.push_back(text_copy%2);
	    		text_copy = text_copy / 2;
	    	}
	}
	BitVector operator+(BitVector& bv, BitVector& mask)
	{
	    std::vector<bool> res;
	    for( int i = 0; i < bv.size; i += 1)
	    {
	    	res.push_back(bv.content[i] || mask.content[i]);
	    }
	    BitVector r (res);
	    return r;
	}
	
	std::ostream& operator<<(std::ostream& os, const BitVector& bv)
	{
	    for( int i = 0; i < bv.size; i += 1)
	    	os << " " << (int)bv.content[i];
	    return os;
	}
	
	bool operator==(const BitVector& bv1, const BitVector& bv2)
	{
		for (int i = 0; i < bv1.size; i += 1)
			if (bv1.content[i] != bv2.content[i]) return false;
		return true;
	}

}