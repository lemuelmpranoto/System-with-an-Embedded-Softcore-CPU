inline int hw_mult(int x, int y) {

    // return the custom instruction with opcode 0 and inputs
    return __builtin_custom_inii(0x00, x, y);

}

