#include "RandomPermutation.hpp"
#include "BitVector.hpp"

#include <iostream>

namespace rp = thesis::random_permutation;

int main(int argc, char **argv)
{
 
    size_t n = 8;
    uint8_t max_pt = std::pow(2, n) - 1;
    uint16_t potency = std::pow(2, n);
    std::vector<bool> mask_ = {1, 0, 1, 1, 0, 0, 0, 1};
    rp::BitVector mask (mask_);
    double delta_mean = 0;
    
    int loop = 1000;
    for (int i = 0; i < loop; i++) // прогон для усреднения
    {
    	  
	    double delta = 0;
	    for (uint8_t pt = 0; pt <= max_pt; pt += 1) // прогон по всем текстам
	    {
	    	    std::random_device rd;
    	    	    std::mt19937 gen(rd());
		    rp::BitVector bv (pt, n);
		    rp::Permutation perm(bv, n, gen);
		    //std::cout << "Content:         " << perm;
		    rp::Permutation no_perm (perm);
		    perm.permute();
		    //std::cout << "Permuted Content:" << perm;
		    //std::cout << std::endl;
		    if ((perm.content + mask) == (no_perm.content + mask))
		    	delta += 1;
		    if (pt == max_pt)
		    	break;
	    }
    delta = std::pow(delta/potency, 2);
    //std::cout << delta << std::endl; // среднее квадрата дельты по всем текстам
    delta_mean += delta;
    }
    std::cout << "Final delta: " << delta_mean/loop << std::endl;
    return 0;
}