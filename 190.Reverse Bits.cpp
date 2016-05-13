class Solution {
public:
	uint32_t reverseBits(uint32_t n)
	{
		for (int i = 0; i <= 15; ++i)
		{
			//uint32_t low = (n&(1 << i)) >> i;
			//uint32_t high = (n&(1 << (31 - i))) >> (31 - i);
			//uint32_t XOR = ((n&(1 << i)) >> i)^((n&(1 << (31 - i))) >> (31 - i));
			//n=(XOR<<i)^n^(XOR<<(31-i));
			n = ((((n&(1 << i)) >> i) ^ ((n&(1 << (31 - i))) >> (31 - i))) << i) ^ n ^ ((((n&(1 << i)) >> i) ^ ((n&(1 << (31 - i))) >> (31 - i))) << (31 - i));
		}
		return n;
	}
};

/*others solution*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};