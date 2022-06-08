#include "Transform.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>


int main(int argc, char **argv)
{

    typedef typename std::iterator_traits<std::vector<bool>::iterator>::difference_type diff_t;
    typedef std::uniform_int_distribution<diff_t> distr_t;
    
    uint16_t radix = 2;
    size_t n = 8;
    uint32_t max_pt = std::pow(radix, n) - 1;
    uint32_t potency = std::pow(radix, n);
    
    std::random_device rd1;
    std::mt19937 gen1(rd1());
    std::uniform_int_distribution<uint32_t> distr(1, max_pt);
    uint32_t mask = distr(gen1);
    std::vector<bool> mask_ = thesis::split(mask, n);  
    
	
    double delta_mean = 0;
    int loop = 10000;
    
    for (int i = 0; i < loop; i++) // прогон для усреднения
    {
    	    std::random_device rd;
    	    std::mt19937 gen(rd());
    	    distr_t D;
	    double delta = 0;
	    thesis::Shuffle s (n, radix);
	    
	    for (uint32_t pt = 0; pt <= max_pt; pt += 1) // прогон по всем текстам
	    {
		    

		    uint32_t ct = s.shuffle_vector(pt);
		    //std::cout << ct << std::endl;
		    std::vector<bool> pt_ = thesis::split(pt, n);
		    std::vector<bool> ct_ = thesis::split(ct, n);
		    
		    /*
		    std::cout << "Plaintext: ";
		    for (int j = 0; j < pt_.size(); j += 1)
		    	std::cout << " " << std::setw(2) << (int)pt_[j];
		    std::cout << std::endl;
		    */
		    /*
		    std::cout << "Ciphertext:";
		    for (int j = 0; j < ct_.size(); j += 1)
		    	std::cout << " " << std::setw(2) << (int)ct_[j];
		    std::cout << std::endl;
		    */

		    //if (thesis::masking(mask_, ct_, mask_, pt_))
		    //{
		    //	delta += 1;
		    	
			/*    
		    	std::cout << "Plaintext: ";
			    for (int j = 0; j < pt_.size(); j += 1)
			    	std::cout << " " << std::setw(2) << (int)pt_[j];
			    std::cout << std::endl;
			    
			std::cout << "Ciphertext:";
		    for (int j = 0; j < ct_.size(); j += 1)
		    	std::cout << " " << std::setw(2) << (int)ct_[j];
		    std::cout << std::endl;
			*/
		    //}
		    
		    delta += thesis::masking(mask_, ct_, mask_, pt_);
		    
		    //if (pt == max_pt)
		    	//break;
	    }
	    delta = std::pow(2*delta/potency - 1, 2);
	    //delta = 2*delta/potency - 1;
	    //std::cout << "Delta: " << delta << std::endl; // среднее квадрата дельты по всем текстам
	    delta_mean += delta;
    
    }
    std::cout << "Mask1=2:   ";
    for (int j = 0; j < mask_.size(); j += 1)
    	std::cout << " " << std::setw(2) << (int)mask_[j];
    std::cout << std::endl;
    
    std::cout << "Final delta: " << delta_mean/loop << std::endl;
    return 0;
}