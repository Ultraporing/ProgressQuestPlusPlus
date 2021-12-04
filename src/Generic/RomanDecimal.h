#ifndef ROMAN_DECIMAL_H
#define ROMAN_DECIMAL_H

#include <nana/deploy.hpp>

// Function to calculate roman equivalent
nana::detail::native_string_type IntToRoman(int num);

// This function returns value
// of a Roman symbol
int RomanToDecimal(std::string& str);

#endif // !ROMAN_DECIMAL_H
