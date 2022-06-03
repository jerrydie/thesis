#include "RandomPermutation.hpp"

#include <algorithm>



namespace thesis::random_permutation 
{
	Permutation::Permutation(BitVector& content_, const size_t size_, std::mt19937& random_generator) : size(size_), gen(random_generator), content(content_)
	    {}
	
	void Permutation::permute()
	{
	    for( int i = size-1; i >= 0; i -= 1)
	    {
	    	std::uniform_int_distribution<int> distribution(0,i);
	    	int j = distribution(gen);
	    	std::swap(content.content[i], content.content[j]);
	    }
	}
	
	std::ostream& operator<<(std::ostream& os, const Permutation& pt)
	{
	    os << " " << pt.content;
	    os << std::endl;
	    return os;
	}

}