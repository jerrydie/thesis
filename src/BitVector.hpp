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
	* Пустой конструктор класса битового вектора.
	***/
	    BitVector() : size(0) {}
	/***
	* Конструктор класса битового вектора, принимает на вход два параметра:
	* text - число, открытый текст;
	* size - размер двоичного массива данных, в который записывается текст.
	***/
	    BitVector(const uint8_t text, const size_t size_);
	/***
	* Конструктор класса битового вектора, принимает на вход один параметр:
	* content - двоичный массив данных.
	***/
	    BitVector(std::vector<bool>& content);
	    
 
	/***
	* Данный метод выводит массив в выбранный поток.
	***/
	    friend std::ostream& operator<<(std::ostream& os, const BitVector& bv);
	/***
	* Данный метод сравнивает два массива.
	***/
	    friend bool operator==(const BitVector& bv1, const BitVector& bv2);
	/***
	* Данный метод проводит побитовое сложение массивов (логическое или).
	***/
	    friend BitVector operator+(BitVector& bv, BitVector& mask);
	    
	};
	
}
#endif