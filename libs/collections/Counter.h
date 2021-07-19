#pragma once
#include "../commons.h"

template<typename K, typename V>
class Counter {
    map<K, V> m;
public:

    void add(K key, V delta) {
      m[key] += delta;
      if (delta < 0 && m[key] == 0) {
        m.erase(m.find(key));
      }
    }

    V operator[](const K &element) {
      return m[element];
    }

    int size() {
      m.size();
    }
};