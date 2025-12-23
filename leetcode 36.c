int removeDuplicates(int* num, int numSize) {
    if (numSize == 0) return 0;

    int k = 1; 
    for (int i = 1; i < numSize; i++) {
        if (num[i] != num[i - 1]) {
            num[k] = num[i];
            k++;
        }
    }

    return k; 
}
