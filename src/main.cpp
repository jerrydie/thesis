#include "Transform.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>


int main(int argc, char **argv)
{

    
    uint16_t radix = 2;
    size_t n = 24;
    uint32_t max_pt = std::pow(radix, n)/2 - 1;
    uint32_t potency = std::pow(radix, n)/2;
    
    std::cout << "Data length: " << n << ", Data potency: " << potency << std::endl;
    std::cout << "|Mask                                        " << "|Mean square delta"           
    	<< "\n" << std::setw(33) << "|--------------------------------------------" << std::setw(33) << "|--------------------------------------------\n";
    	

    //uint32_t mask = distr(gen1);
    for (uint32_t mask = 1; mask < 3; mask += 1)
    {
	    std::vector<bool> mask_ = thesis::split(mask, n);  
	    
		
	    double delta_mean = 0;
	    int loop = 100;
	    
	    for (int i = 0; i < loop; i++) // прогон для усреднения
	    {

		    double delta = 0;
		    thesis::Shuffle s (n, radix);
		    
		    for (uint32_t pt = 0; pt <= max_pt; pt += 1) // прогон по всем текстам
		    {
			    

			    uint32_t ct = s.shuffle_text(pt);
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
			    
			    delta += thesis::masking(mask_, ct_, mask_, pt_);
			    
		    }
		    delta = std::pow(2*delta/potency - 1, 2);
		    delta_mean += delta;
	    
	    }
	    std::cout << "|";
	    for (int j = 0; j < mask_.size(); j += 1)
	    	std::cout << " " << std::setw(2) << (int)mask_[j];
	    
	    std::cout << "        |" << std::setw(42) << delta_mean/loop << std::endl;
    }
    return 0;
}