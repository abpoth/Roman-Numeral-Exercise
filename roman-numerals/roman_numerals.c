#include "roman_numerals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    u_int16_t base;
    const char* numeral;
} Roman_Numeral_Values_t;

static const Roman_Numeral_Values_t romanNumeralTable[]=
{
    { 1000, "M"},
    { 900, "CM"},
    { 500, "D"},
    { 400, "CD"},
    { 100, "C"},
    { 90, "XC"},
    { 50, "L"},
    { 40, "XL"},
    { 10, "X"},
    { 9, "IX"},
    { 5, "V"},
    { 4, "IV"},
    { 1, "I"}
};

char *to_roman_numeral(unsigned int number)
{
    char *result = calloc(16, sizeof(char)); // The largest Roman Numerals would be a max of 15 bytes
    char *answer = result;

    for(size_t i = 0; i < sizeof(romanNumeralTable) / sizeof(romanNumeralTable[0]); i++){
        while (number >= romanNumeralTable[i].base){
            strcpy(result, romanNumeralTable[i].numeral);
            result += strlen(romanNumeralTable[i].numeral);
            number -= romanNumeralTable[i].base;
        }
    }

    free(result = NULL);
    return answer; 
}
