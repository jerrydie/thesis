#ifndef __BIT_VECTOR_HPP__
#define __BIT_VECTOR_HPP__

#include <random>
#include <ostream>
#include <vector>

namespace thesis::random_permutation 
{
	class BitVector
	{	   
	public:
	    size_t size;
	    std::vector<bool> content;
	/***
	* Конструктор класса сперестановки, принимает на вход три параметра:
	* content - массив данных для перестановки значений;
	* size - размер массива данных;
	* random_generator - генератор случайных значений;
	* конструктор инициализирует соотвествующие private члены переданными параметрами.
	***/
	
	    BitVector();
	    BitVector(const uint8_t text, const size_t size_);
	    BitVector(std::vector<bool>& content);
	    

	/***
	* Данный метод проводит равновероятную перестановку данных внутри массива.
	***/ 
	/***
	* Данный метод выводит массив в выбранный поток.
	***/
	    friend std::ostream& operator<<(std::ostream& os, const BitVector& bv);
	    friend bool operator==(const BitVector& bv1, const BitVector& bv2);
	    
	};
	BitVector vector_xor(BitVector& bv, BitVector& mask);
	
}
#endif