#include "RandomSubstitution.hpp"

#include <algorithm>
#include <iostream>



namespace thesis::random_substitution
{	
	Substitution::Substitution(std::vector<uint8_t>& alphabet_, std::mt19937& random_generator)
		: gen(random_generator), substitution(alphabet_)
	{
		for( int i = 0; i < alphabet_.size(); i += 1)
		{
			alphabet[alphabet_[i]] = i;
		}
		
		
		for( int i = substitution.size() - 1; i >= 0; i -= 1)
		{
		    	std::uniform_int_distribution<int> distribution(0,i);
		    	int j = distribution(gen);
		    	std::swap(substitution[i], substitution[j]);
	    	}
	}

	std::vector<uint8_t> Substitution::substitute(std::vector<uint8_t>& text)
	{	
		std::vector<uint8_t> cipher_text;
		
		for (uint8_t t : text)
		{
			cipher_text.push_back(substitution[alphabet[t]]);
		}

		return cipher_text;
	}
	
	std::ostream& operator<<(std::ostream& os, const Substitution& sub)
	{
		os << "Alphabet         :";
		for(auto& [key, value] : sub.alphabet)
			os << " " << (int)key;
		os << std::endl;
		
		os << "Permuted alphabet:";
		for(auto s : sub.substitution)
			os << " " << (int)s;
		os << std::endl;
		return os;
	}
	

}