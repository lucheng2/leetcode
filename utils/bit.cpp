int getBit(char c, int i) {
    return (c>>i) & 1;
}

void setBit(char &c, int i, int v) {
    if(v)
        c |= (1<<i);
    else
        c &= ~(1<<i);
}

void flipBit(char &c, int i) {
    c ^= (1<<i);
}

