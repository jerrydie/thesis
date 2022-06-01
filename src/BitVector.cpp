#include "BitVector.hpp"

#include <algorithm>



namespace thesis::random_permutation 
{
	BitVector::BitVector(std::vector<bool>& content_) : size(content_.size()), content(content_)
	    {}
	BitVector::BitVector() : size(0)
	    {}
	BitVector vector_xor(BitVector& bv, BitVector& mask)
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

}