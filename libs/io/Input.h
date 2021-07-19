#pragma once
#include "../commons.h"

class Input {
private:
    std::istream *in;

public:
    Input(std::istream &in) : in(&in) {}
    inline int readInt() {
      return read<int>();
    }

    inline ll readLong() {
      return read<ll>();
    }

    inline vector<int> readIntArray(int size) {
      return readArray<int>(size);
    }

    inline void readArray() {}

    template<typename T, typename... Targs>
    inline void readArray(vector<T> &first, Targs &... args) {
      readSingleArray(first);
      if (sizeof...(args) != 0) {
        readArray(args...);
      }
    }

    inline vector<vector<int>> readIntTable(int rows, int cols) {
      return readTable<int>(rows, cols);
    }

    inline vector<vector<ll>> readLongTable(int rows, int cols) {
      return readTable<ll>(rows, cols);
    }

    inline vector<ll> readLongArray(int size) {
      return readArray<ll>(size);
    }

    inline vector<string> readStringArray(int size) {
      return readArray<string>(size);
    }

    inline string readString() {
      return read<string>();
    }

    inline double readDouble() {
      return read<double>();
    }

    bool eof() {
      return in->eof();
    }

private:
    template<typename T>
    inline T read() {
      T res;
      *in >> res;
      return res;
    }

    template<typename T>
    inline void readSingleArray(vector<T> &arr) {
      for (int i = 0; i < sz(arr); ++i)
        *in >> arr[i];
    }

    template<typename T>
    inline vector<T> readArray(int size) {
      vector<T> arr(size);
      for (int i = 0; i < size; ++i) *in >> arr[i];
      return arr;
    }

    template<typename T>
    inline vector<vector<T>> readTable(int rows, int cols) {
      vector<vector<T>> arr(rows, vector<T>(cols));
      for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
          *in >> arr[i][j];
      return arr;
    }
};

Input in(cin);