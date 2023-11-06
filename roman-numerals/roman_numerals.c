#include "roman_numerals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    unsigned int base;
    const char* numeral;
    const int size;
} Roman_Numeral_Values_t;

static const Roman_Numeral_Values_t romanNumeralTable[]=
{
    { 1000, "M" , 1},
    { 900, "CM", 2},
    { 500, "D" , 1},
    { 400, "CD", 2},
    { 100, "C" , 1},
    { 90, "XC" , 2},
    { 50, "L" , 1},
    { 40, "XL" , 2},
    { 10, "X" , 1},
    { 9, "IX" , 2},
    { 5, "V" , 1},
    { 4, "IV" , 2},
    { 1, "I" , 1}
};

char *to_roman_numeral(unsigned int number)
{
    char *result = (char*)calloc(16, sizeof(char)); // The largest Roman Numerals would be a max of 15 bytes
    char *answer = result;

    for(size_t i = 0; i < sizeof(romanNumeralTable) / sizeof(romanNumeralTable[0]); i++){
        while (number >= romanNumeralTable[i].base){
            strcpy(result, romanNumeralTable[i].numeral);
            result += romanNumeralTable[i].size;
            number -= romanNumeralTable[i].base;
        }
    }
    free(result = NULL);
    return answer;
}
