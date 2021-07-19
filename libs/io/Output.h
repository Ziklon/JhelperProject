#pragma once
#include "../commons.h"

class Output {
private:
    std::ostream *out;

    template<typename T>
    inline void printSingle(const T &value) {
      *out << value;
    }

    template<typename T>
    inline void printSingle(const vector<T> &arr) {
      int size = sz(arr);
      for (int i = 0; i < size; ++i) {
        *out << arr[i];
        if (i + 1 != size)
          *out << ' ';
      }
    }

public:
    bool autoflush;

    Output(std::ostream &out, bool autoflush) : out(&out), autoflush(autoflush) {
      setPrecision(20);
    }

    inline void print() {}

    template<typename T, typename...Targs>
    inline void print(const T &first, const Targs &... args) {
      printSingle(first);
      if (sizeof...(args) != 0) {
        *out << ' ';
        print(args...);
      }
      if (autoflush) {
        flush();
      }
    }

    template<typename...Targs>
    inline void printLine(const Targs... args) {
      print(args...);
      *out << '\n';
      if (autoflush) {
        flush();
      }
    }

    void setOut(ostream &nOut) {
      out = &nOut;
      setPrecision(20);
    }

    inline void flush() {
      out->flush();
    }

    inline void setPrecision(int digits) {
      *out << fixed << setprecision(digits);
    }
};

Output out(std::cout, false);