#ifndef __RANDOM_PERMUTATION_HPP__
#define __RANDOM_PERMUTATION_HPP__

#include <stdint.h>
#include <random>
#include <ostream>
#include <vector>

namespace thesis::random_permutation 
{
	class Permutation
	{
	private:
	   std::mt19937 gen; 
	   size_t size;
	   std::vector<uint16_t> content;
	   
	public:
	/***
	* Конструктор класса сперестановки, принимает на вход три параметра:
	* content - массив данных для перестановки значений;
	* size - размер массива данных;
	* random_generator - генератор случайных значений;
	* конструктор инициализирует соотвествующие private члены переданными параметрами.
	***/
	    Permutation(std::vector<uint16_t> content, const size_t size, std::mt19937& random_generator);

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