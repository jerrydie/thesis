#include "RandomPermutation.hpp"
#include "BitVector.hpp"

#include <iostream>

#define n 8
namespace rp = thesis::random_permutation;

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    uint8_t max_pt = std::pow(2, n) - 1;
    for (uint8_t pt = 0; pt <= max_pt; pt += 1)
    {
    	std::vector<bool> arr;
    	uint8_t pt_copy = pt;
    	for (size_t j = n-1; j >= 0; j -= 1)
    	{
    		if (pt_copy == 0)
    		{
    			arr.resize(n, 0);
    			break; 
    		}
    		arr.push_back(pt_copy%2);
    		pt_copy = pt_copy / 2;
    	}

	    rp::BitVector bv (arr);
	    rp::Permutation perm(bv, n, gen);
	    std::cout << "Content:         " << perm;
	    perm.permute();
	    std::cout << "Permuted Content:" << perm;
	    std::cout << std::endl;
	    
	    if (pt == max_pt)
	    	break;
	}
    return 0;
}