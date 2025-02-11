#ifndef BITWISE_UTILS_H
#define BITWISE_UTILS_H

#include <stdbool.h>
#include <stdint.h>

void print_bits_u32(uint32_t n, bool has_newline);
void print_bits_u8(uint8_t n, bool has_newline);

uint8_t u8_from_string(const char *s);
uint32_t u32_from_string(const char *s);

# endif // BITWISE_UTILS_H
