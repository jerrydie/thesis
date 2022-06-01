#ifndef __RANDOM_PERMUTATION_HPP__
#define __RANDOM_PERMUTATION_HPP__

#include <stdint.h>
#include <random>
#include <ostream>
#include <vector>
#include "BitVector.hpp"

namespace thesis::random_permutation 
{
	class Permutation
	{
	private:
	   std::mt19937 gen; 
	   size_t size;
	   
	public:
	   BitVector content;
	/***
	* Конструктор класса перестановки, принимает на вход три параметра:
	* content - массив данных для перестановки значений;
	* size - размер массива данных;
	* random_generator - генератор случайных значений.
	***/
	    Permutation(BitVector& content_, const size_t size_, std::mt19937& random_generator);
	    
	 /***
	* Конструктор класса перестановки, принимает на вход существующий член класса.
	***/ 
	    Permutation(Permutation& perm): content(perm.content), size(perm.size), gen(perm.gen) {}

	/***
	* Данный метод проводит равновероятную перестановку данных внутри массива.
	***/
	    void permute(); 
	/***
	* Данный метод выводит массив в выбранный поток.
	***/
	    friend std::ostream& operator<<(std::ostream& os, const Permutation& pt);
	};
	
}
#endif