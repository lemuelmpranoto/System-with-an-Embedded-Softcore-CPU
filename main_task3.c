#include <stdlib.h>
#include <stdio.h> 
/* NOTE: this file must be self-contained */

#define least_sig_word (volatile int *)0xa100;
#define most_sig_word (volatile int *)0xa104;

unsigned long long begin, end, result;

//int __builtint_custom_inii(int, int, int);      // custom instruction

inline int hw_mult(int x, int y) {
    /* your code using the custom instruction here */

    return __builtin_custom_inii(0x00, x, y);

}

inline unsigned long long hw_counter() {
    
    volatile unsigned long long ret;

    unsigned int low_word0 = *least_sig_word;
    unsigned int high_word0 = *most_sig_word;
    unsigned int low_word1 = *least_sig_word;
    unsigned int high_word1 = *most_sig_word;
    unsigned int low_word, high_word;

    if (low_word1 < low_word0) {
        low_word = low_word1;
    } else {
        low_word = low_word0;
    }

    if (high_word1 > high_word0) {
        high_word = high_word1;
    } else {
        high_word = high_word0;
    }

    ret = (unsigned long long) ( (unsigned long long) high_word << 32 | low_word);

    return ret;
}


int __attribute__((noinline)) measure(int min_i, int max_i) {
    register int i, j;
    j = 0;
    /* begin timing */
    begin = hw_counter();

    for (i = min_i; i < max_i; ++i) {
      j += hw_mult(i,i);
    }
    /* end timing */

    end = hw_counter();
    result = (end - begin) / 1000;

    return j;
}

void main() {
    measure(1000, 2000);
}

















// // start of code

// /* NOTE: this file must be self-contained */

// //==============================//
// //        Definitions           //
// //==============================//
// // multiplier address
// #define MULT_N 0x00
// // counter addresses
// #define count_pre   (volatile unsigned long long *)0x1500 // address for the count value before the multiplication
// #define count       (volatile unsigned long long *)0x1510 // final count value address
// #define product     (volatile unsigned long *)0x1520      // result of multiplication
// #define ADDR_BASE   (volatile unsigned long *)0xa100
// #define ADDR_HIGH   (volatile unsigned long *)0xa104
// // custom instruction function
// #define MULT(x,y) __builtin_custom_inii(MULT_N, (x), (y));

// //==============================//
// //      Function Prototypes     //
// //==============================//
// int __builtint_custom_inii(int, int, int);      // custom instruction
// extern inline unsigned long long hw_counter();  // count

// //******************************//
// //        Main function         //
// //******************************//
// int main (void) {
//     hw_counter();
//     return 0;
// }

// //******************************//
// //     HW Counter function      //
// //******************************//
// inline unsigned long long hw_counter() {

//   unsigned long temp_base; 
//   temp_base = *ADDR_BASE;
//   unsigned long long temp_high;
//   temp_high = *ADDR_HIGH; 

//   if (*ADDR_HIGH == temp_high) {
//     (*count_pre) = (temp_high << 32) | temp_base;
//   } else {
//     (*count_pre) = (temp_high << 32) | 0xffffffff;
//   }


//   // multiplication loop
//   for (int i = 0; i < 1000; i++) {
//     (*product) = MULT(i,i);
//   }

//   // corner cases
//   temp_base = *ADDR_BASE;
//   temp_high = *ADDR_HIGH;
  
//   if (*ADDR_HIGH == temp_high) {
//     (*count) = (temp_high << 32) | temp_base;
//   } else {
//     (*count) = (temp_high << 32) | 0xffffffff;
//   }

//   // compute the actual count value by subtracting the starting and final count values
//   // then dividing by the no. of iterations
//   (*count) = (*count) - (*count_pre);
//   (*count) = (*count) / 1000;

//   return (*count);
// }
