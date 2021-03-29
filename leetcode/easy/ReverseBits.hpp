/*
 * @Author: gary.wang
 * @Date: 2021-03-29 20:37:44
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-03-29 20:39:07
 *

    Reverse bits of a given 32 bits unsigned integer.

    Note:

    Note that in some languages such as Java, there is no unsigned integer type.
    In this case, both input and output will be given as a signed integer type.
    They should not affect your implementation, as the integer's internal
    binary representation is the same, whether it is signed or unsigned.
    In Java, the compiler represents the signed integers using 2's complement
    notation. Therefore, in Example 2 above,
    the input represents the signed integer -3 and the output represents the signed integer -1073741825.
 *
 */
#include "../ITest.h"

class ReverseBits : public ITest {
  private:
    const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

  public:
    // 位运算分治...
    uint32_t reverseBits(uint32_t n) {
        n = n >> 1 & M1 | (n & M1) << 1;
        n = n >> 2 & M2 | (n & M2) << 2;
        n = n >> 4 & M4 | (n & M4) << 4;
        n = n >> 8 & M8 | (n & M8) << 8;
        return n >> 16 | n << 16;
    }
    void test() {}
};