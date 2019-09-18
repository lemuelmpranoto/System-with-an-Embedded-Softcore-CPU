#include <stdlib.h>
#include <stdio.h> 

#define least_sig_word (volatile unsigned long *)0xa100;
#define most_sig_word (volatile unsigned long*)0xa104;

unsigned long long begin, end, result;

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
      j += i * i;
    }
    /* end timing */

    end = hw_counter();
    result = (end - begin) / 1000;

    return j;
}

void main() {
    measure(1000, 2000);
}