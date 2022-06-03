#ifndef __RANDOM_SUBSTITUTION_HPP__
#define __RANDOM_SUBSTITUTION_HPP__

#include <stdint.h>
#include <random>
#include <ostream>
#include <vector>
#include <map>

namespace thesis::random_substitution
{
	class Substitution
	{
	private:
	   std::mt19937 gen;
	   
	public:
	// Алфавит открытых текстов.
	   std::map<uint8_t, uint16_t> alphabet;
	// Алфавит подстановки (на каждом i-ом месте находится подстановка для i-ого символа алфавита открытых текстов)
	   std::vector<uint8_t> substitution;
	/***
	* Конструктор класса подстановки, принимает на вход два параметра:
	* alphabet_ - массив алфавита открытых текстов;
	* random_generator - генератор случайных значений.
	* Конструктор генерирует случайную перестановку алфавита для получения алфавита подстановки, алгоритм Фишера-Йетса.
	***/
	    Substitution(std::vector<uint8_t>& alphabet_, std::mt19937& random_generator);

	/***
	* Данный метод проводит подстановку данных массива на основе алфавитов.
	***/
	    std::vector<uint8_t> substitute(std::vector<uint8_t>& text); 
	/***
	* Данный метод выводит алфавиты в выбранный поток.
	***/
	    friend std::ostream& operator<<(std::ostream& os, const Substitution& sub);
	};
	
}
#endif