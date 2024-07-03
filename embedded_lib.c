#include "embedded_lib.h"

// X(n+1) = (2053 * X(n)) + 13849)
#define FASTLED_RAND16_2053 ((uint16_t)(2053))
#define FASTLED_RAND16_13849 ((uint16_t)(13849))
uint16_t rand16seed = 1337;

uint64_t a_ = 0, b_ = 0;
  
void hex2str(uint8_t *in, uint16_t len, uint8_t *out) {
  static const char hex[] = "0123456789abcdef";
  uint16_t i, j;

  for (i = 0, j = 0; i < len; i++) {
    out[j++] = hex[(in[i] & 0xf0) >> 4];
    out[j++] = hex[in[i] & 0xf];
  }
}

uint8_t random8(void) {
  rand16seed = (rand16seed * FASTLED_RAND16_2053) + FASTLED_RAND16_13849;
  return (uint8_t)(((uint8_t)(rand16seed & 0xFF)) + ((uint8_t)(rand16seed >> 8)));
}

uint8_t random8l(uint8_t lim) {
  uint8_t r = random8();
  r = (r * lim) >> 8;
  return r;
}

uint8_t random8ml(uint8_t min, uint8_t lim) {
  uint8_t delta = lim - min;
  uint8_t r = random8(delta) + min;
  return r;
}

uint16_t random16(void) {
  rand16seed = (rand16seed * FASTLED_RAND16_2053) + FASTLED_RAND16_13849;
  return rand16seed;
}

uint16_t random16l(uint16_t lim) {
  uint16_t r = random16();
  uint32_t p = (uint32_t)lim * (uint32_t)r;
  r = p >> 16;
  return r;
}

uint16_t random16nl(uint16_t min, uint16_t lim) {
  uint16_t delta = lim - min;
  uint16_t r = random16(delta) + min;
  return r;
}

uint8_t is_power_of_2(uint64_t n) {
  return (n != 0 && ((n & (n - 1)) == 0));
}

uint32_t count_ones(uint64_t n) {
  uint32_t count = 0;
  while (n >0 ) {
      count ++;
      n &= (n-1);
  }
  return count;
}


uint32_t rand32() {
  // The generator usually returns an uint64_t, truncate it.
  //
  // It is noted in this paper (https://arxiv.org/abs/1810.05313) that the
  // lowest 32 bits fail some statistical tests from the Big Crush
  // suite. Use the higher ones instead.
  return rand64() >> 32;
}

double rand_double() {
  uint64_t x = rand64();
  // From https://vigna.di.unimi.it/xorshift/.
  // 53 bits of mantissa, hence the "hexadecimal exponent" 1p-53.
  return (x >> 11) * 0x1.0p-53;
}


void insecure_random_generator() {
  a_ = rand64();
  b_ = rand64();
}

uint64_t rand64() {
  // Using XorShift128+, which is simple and widely used. See
  // https://en.wikipedia.org/wiki/Xorshift#xorshift+ for details.
  uint64_t t = a_;
  const uint64_t s = b_;

  a_ = s;
  t ^= t << 23;
  t ^= t >> 17;
  t ^= s ^ (s >> 26);
  b_ = t;

  return t + s;
}
