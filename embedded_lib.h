#ifndef _EMBEDDED_LIB_
#define _EMBEDDED_LIB_
#include <stdint.h>

/*
 * Macro：UINT16_SWAP(i)
 *
 * Description：Convert 2 array entries (a[0], a[1]) into a 16 bit integer, where a[0] is
 *              the MSByte and a[1] is the LSByte
 *
 * Example: i = 0x1234;
 *       UINT16_SWAP(1)
 *       i = 0x3412
 */
#define UINT16_SWAP(i) (((uint16_t)((i) >> 8) & 0xff) | ((uint16_t)((i)&0xff) << 8))

/*
 * Macro：ARRAY_UINT16(a)
 *
 * Description：Convert 2 array entries (a[0], a[1]) into a 16 bit integer, where a[0] is
 *       the MSByte and a[1] is the LSByte
 *
 * Example: i, a[2]； a[0] = 0x01, a[1] = 0x02;
 *       ARRAY_UINT16(a)
 *       i = ARRAY_UINT16(a)
 *       i = 0x0102
 */
#define ARRAY_UINT16(a) (((uint16_t)((a)[0] & 0xff) << 8) | ((uint16_t)((a)[1] & 0xff) << 0))

/*
 * Macro：ARRAY_UINT16_L(a)
 *
 * Description：Convert 2 array entries (a[0], a[1]) into a 16 bit integer, where a[0] is
 *       the LSByte and a[1] is the MSByte
 *
 * Example: i, a[2]； a[0] = 0x01, a[1] = 0x02;
 *       ARRAY_UINT16_L(a)
 *       i = ARRAY_UINT16_L(a)
 *       i = 0x0201
 */
#define ARRAY_UINT16_L(a) (((uint16_t)((a)[0] & 0xff) << 0) | ((uint16_t)((a)[1] & 0xff) << 8))

/*
 * Macro：UINT16_ARRAY(i, a)
 *
 * Description：Copy an UINT_16 i into 2 array entries (a[0], a[1]), where a[0] is the MSByte
 *
 * Example: i = 0x0102, a[2];
 *       UINT16_ARRAY(i, a)
 *       a[0] = 0x01, a[1] = 0x02
 *
 */
#define UINT16_ARRAY(i, a)      \
  do {                          \
    (a)[0] = ((i) >> 8) & 0xff; \
    (a)[1] = ((i) >> 0) & 0xff; \
  } while (0);

/*
 * MacroARRAY_UINT32(a)
 *
 * Description：Convert 4 array entries (a[0], a[1], a[2] and a[3]) into a 32 bit integer, where a[0] is
 *       the MSByte and a[3] is the LSByte
 *
 * Example: i, a[4]； a[0] = 0x01, a[1] = 0x02, a[2] = 0x03, a[3] = 0x04 ;
 *       ARRAY_UINT32(a)
 *       i = ARRAY_UINT32(a)
 *       i = 0x01020304
 */
#define ARRAY_UINT32(a)                                                                                       \
  (((uint32_t)((a)[0] & 0xff) << 24) | ((uint32_t)((a)[1] & 0xff) << 16) | ((uint32_t)((a)[2] & 0xff) << 8) | \
   ((uint32_t)((a)[3] & 0xff) << 0))

/*
 * Macro：ARRAY_UINT32_L( a)
 *
 * Description：Convert 4 array entries (a[0], a[1], a[2] and a[3]) into a 32 bit integer, where a[0] is
 *       the LSByte and a[3] is the MSByte
 *
 * Example: i, a[4]； a[0] = 0x01, a[1] = 0x02, a[2] = 0x03, a[3] = 0x04 ;
 *       ARRAY_UINT32_L(a)
 *       i = ARRAY_UINT32_L(a)
 *       i = 0x04030201
 */
#define ARRAY_UINT32_L(a)                                                                                    \
  (((uint32_t)((a)[0] & 0xff) << 0) | ((uint32_t)((a)[1] & 0xff) << 8) | ((uint32_t)((a)[2] & 0xff) << 16) | \
   ((uint32_t)((a)[3] & 0xff) << 24))

/*
 * Macro：UINT32_ARRAY(i, a)
 *
 * Description：Copy an UINT_32 i into 4 array entries (a[0], a[1], a[2] and a[3]), where a[0] is the MSByte
 *
 * Example: i = 0x01020304, a[4];
 *       UINT32_ARRAY(i, a)
 *       a[0] = 0x01, a[1] = 0x02, a[2] = 0x03, a[3] = 0x04
 *
 */
#define UINT32_ARRAY(i, a)       \
  do {                           \
    (a)[0] = ((i) >> 24) & 0xff; \
    (a)[1] = ((i) >> 16) & 0xff; \
    (a)[2] = ((i) >> 8) & 0xff;  \
    (a)[3] = ((i) >> 0) & 0xff;  \
  } while (0);

/*
 * hex to string
 */
extern void hex2str(uint8_t *in, uint16_t len, uint8_t *out);

/*
* Generate an 8-bit random number, random from 0..255
*/
extern uint8_t random8(void);

/*
* Generate an 8-bit random number, random between 0 and lim
*/
extern uint8_t random8l(uint8_t lim);

/*
* Generate an 8-bit random number, random between min and lim
*/
extern uint8_t random8ml(uint8_t min, uint8_t lim);

/*
* Generate an 16-bit random number, random from 0..65535
*/
extern uint16_t random16(void);

/*
* Generate an 16-bit random number, random between 0 and lim
*/
extern uint16_t random16l(uint16_t lim);

/*
* Generate an 16-bit random number, random between min and lim
*/
extern uint16_t random16nl(uint16_t min, uint16_t lim);

/*
* To determine if a number is a power of two
*/
extern uint8_t is_power_of_2(uint64_t n);

/*
*Calculating the number of 1s in the binary representation of an unsigned long integer, Using the Brian Kernighan algorithm
*/
extern uint32_t count_ones(uint64_t n);

#endif  //_EMBEDDED_LIB_
