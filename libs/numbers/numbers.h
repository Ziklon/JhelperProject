#pragma once

#include "../commons.h"

template<typename T>
T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b != 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}

template<typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

template<typename T>
T power(const T a, ll b) {
  if (b == 0) {
    return 1;
  }
  if ((b & 1) == 0) {
    T res = power(a, b >> 1);
    return res * res;
  } else {
    return power(a, b - 1) * a;
  }
}

template<typename T>
T power(const T a, ll b, const ll md) {
  if (b == 0) {
    return 1;
  }
  if ((b & 1) == 0) {
    T res = power(a, b >> 1);
    return res * res % md;
  } else {
    return power(a, b - 1) * a % md;
  }
}