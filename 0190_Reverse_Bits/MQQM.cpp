/*
  题目：
  前后颠倒给定的 32 位无符号整数的二进制位。
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {       
        uint32_t ret = 0;        
        for(int i = 1; i<=32 ; i++){
            ret = ret << 1;
            ret += n & 1;              
            n = n >> 1;  
        }
        return ret;
    }
};
