#ifndef __TRANSFORM_HPP__
#define __TRANSFORM_HPP__

#include <stdint.h>
#include <vector>
#include <random>

namespace thesis
{

	/***
	* Метод, принимающий на вход число и желаемый размер массива.
	* Возвращает двоичный массив заданного размера.
	***/
	std::vector<bool> split(uint32_t num, std::size_t size_);
	
	/***
	* Метод, принимающий на вход число, желаемый размер массива и систему счисления.
	* Возвращает массив в нужной системе заданного размера.
	***/
	std::vector<uint8_t> split(uint32_t num, std::size_t size_, uint16_t radix);
	
	
	/***
	* Метод, принимающий на вход две маски и два текста.
	* Возвращает true, если выполняется линейное соотношение с заданными масками, false в противном случае.
	***/
	bool masking (std::vector<bool>& mask1, std::vector<bool>& text1, std::vector<bool>& mask2, std::vector<bool>& text2);
	
	

	class Shuffle
	{

		std::vector<uint32_t> shuffle;
		std::size_t size;
		void RandomPermutation();
		
		public:
		Shuffle(std::size_t size, uint8_t radix);
		uint32_t shuffle_text(uint32_t pt);
		
		
	};
}
#endif