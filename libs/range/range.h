#pragma once

#include "../commons.h"

//https://github.com/whoshuu/cpp_range/blob/master/include/range.h

class NumberIterator : iterator<forward_iterator_tag, int> {
public:
    int v;

    NumberIterator(int v) : v(v) {}

    operator int &() { return v; }

    int operator*() { return v; }
};

class range : pair<int,int> {
public:
    range(int begin, int end) : pair<int,int>(begin, max(begin, end)) {}

    range(int n) : pair<int,int>(0, max(0, n)) {}

    NumberIterator begin() {
        return first;
    }

    NumberIterator end() {
        return second;
    }
};

range rangeIncl(int begin, int end) {
    return range(begin, end + 1);
}

range rangeIncl(int n) {
    return range(n + 1);
}
