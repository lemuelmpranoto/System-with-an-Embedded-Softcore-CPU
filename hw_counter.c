#define least_sig_word (volatile int *)0xa100;
#define most_sig_word (volatile int *)0xa104;

inline unsigned long long hw_counter() {
    
    volatile unsigned long long ret;

    // assigning addresses to the variables
    unsigned int low_word0 = *least_sig_word;
    unsigned int high_word0 = *most_sig_word;
    unsigned int low_word1 = *least_sig_word;
    unsigned int high_word1 = *most_sig_word;
    unsigned int low_word, high_word;

    // dealing with corner cases in the case where its overflowing
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

    // returning concatenation of two 32 bit integers into a 64 bit long
    ret = (unsigned long long) ( (unsigned long long) high_word << 32 | low_word);

    return ret;
}