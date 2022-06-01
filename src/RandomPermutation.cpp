#include "RandomPermutation.hpp"

#include <algorithm>



namespace thesis::random_permutation 
{
	Permutation::Permutation(std::vector<uint16_t> content_, const size_t size_, std::mt19937& random_generator) : size(size_), gen(random_generator), content(content_)
	    {}
	
	void Permutation::permute()
	{
	    for( int i = size-1; i >= 0; i -= 1)
	    {
	    	std::uniform_int_distribution<int> distribution(0,i);
	    	int j = distribution(gen);
	    	std::swap(content[i], content[j]);
	    }
	}
	
	std::ostream& operator<<(std::ostream& os, const Permutation& pt)
	{
	    for( int i = 0; i < pt.size; i += 1)
	    	os << " " << pt.content[i];
	    os << std::endl;
	    return os;
	}

}