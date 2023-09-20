#include "embedded_lib.h"

// X(n+1) = (2053 * X(n)) + 13849)
#define FASTLED_RAND16_2053 ((uint16_t)(2053))
#define FASTLED_RAND16_13849 ((uint16_t)(13849))
uint16_t rand16seed = 1337;

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