#include "RomanDecimal.h"
#include <map>

// Function to calculate roman equivalent
nana::detail::native_string_type IntToRoman(int num)
{
    // storing roman values of digits from 0-9
    // when placed at different places
    nana::detail::native_string_type m[] = { nana::to_nstring(""), nana::to_nstring("M"), nana::to_nstring("MM"), nana::to_nstring("MMM") };
    nana::detail::native_string_type c[] = { nana::to_nstring(""),  nana::to_nstring("C"),  nana::to_nstring("CC"),  nana::to_nstring("CCC"),
        nana::to_nstring("CD"), nana::to_nstring("D"), nana::to_nstring("DC"), nana::to_nstring("DCC"), nana::to_nstring("DCCC"), nana::to_nstring("CM") };
    nana::detail::native_string_type x[] = { nana::to_nstring(""),  nana::to_nstring("X"),  nana::to_nstring("XX"),  nana::to_nstring("XXX"),
        nana::to_nstring("XL"), nana::to_nstring("L"), nana::to_nstring("LX"), nana::to_nstring("LXX"), nana::to_nstring("LXXX"), nana::to_nstring("XC") };
    nana::detail::native_string_type i[] = { nana::to_nstring(""),  nana::to_nstring("I"),  nana::to_nstring("II"),  nana::to_nstring("III"),
        nana::to_nstring("IV"), nana::to_nstring("V"), nana::to_nstring("VI"), nana::to_nstring("VII"), nana::to_nstring("VIII"), nana::to_nstring("IX") };

    // Converting to roman
    nana::detail::native_string_type thousands = m[num / 1000];
    nana::detail::native_string_type hundereds = c[(num % 1000) / 100];
    nana::detail::native_string_type tens = x[(num % 100) / 10];
    nana::detail::native_string_type ones = i[num % 10];

    nana::detail::native_string_type ans = thousands + hundereds + tens + ones;

    return ans;
}

// This function returns value
// of a Roman symbol
int RomanToDecimal(std::string& str)
{
    std::map<char, int> m;
    m.insert({ 'I', 1 });
    m.insert({ 'V', 5 });
    m.insert({ 'X', 10 });
    m.insert({ 'L', 50 });
    m.insert({ 'C', 100 });
    m.insert({ 'D', 500 });
    m.insert({ 'M', 1000 });
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        /*If present value is less than next value,
          subtract present from next value and add the
          resultant to the sum variable.*/
        if (m[str[i]] < m[str[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(i) + 1]])
        {
            sum += m[str[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(i) + 1]] - m[str[i]];
            i++;
            continue;
        }
        sum += m[str[i]];
    }
    return sum;
}