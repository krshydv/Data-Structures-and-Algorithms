class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;

        // Create a mask with all 1s that has the same number of bits as n
        int mask = 0;
        int temp = n;
        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        // XOR with mask flips all the bits
        return n ^ mask;
    }
};