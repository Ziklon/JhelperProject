#pragma once
#include "commons.h"

inline int bitCount(unsigned x) {
  return __builtin_popcount(x);
}

inline int bitCount(ull x) {
  return __builtin_popcount(x);
}

inline int highestOneBit(unsigned x) {
  return 1 << (31 - __builtin_clz(x | 1));
}

inline bool isSubset(unsigned set, unsigned subSet) {
  return (set & subSet) == subSet;
}