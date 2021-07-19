#pragma once
#include "../commons.h"
template<typename num_t, num_t defaultValue = 0>
class SegmentTree {
    const int size;
    vector<num_t> tree;
    function<num_t(num_t, num_t)> joinValue;

public:
    SegmentTree(vector<num_t> &arr, const function<num_t(num_t, num_t)> &joinValue) :
        size(arr.size()), joinValue(joinValue) {
      this->tree = vector<num_t>(size * 4);
      build(0, 0, size - 1, arr);
    }

    num_t query(int start, int end) {
      assert(start <= end && start >= 0 && end < size);
      return query(0, 0, size - 1, start, end);
    }

    void update(int at, num_t val) {
      assert(at >= 0 && at < size);
      update(0, 0, size - 1, at, val);
    }

private:
    void build(int node, int start, int end, vector<num_t> &arr) {
      if (start == end) {
        tree[node] = arr[start];
        return;
      }
      int mid = (start + end) / 2;
      build(2 * node + 1, start, mid, arr);
      build(2 * node + 2, mid + 1, end, arr);
      tree[node] = joinValue(tree[2 * node + 1], tree[2 * node + 2]);
    }


    void update(int node, int start, int end, int idx, num_t val) {
      if (start == end) {
        tree[node] = val;
        return;
      }
      int mid = (start + end) / 2;
      if (idx <= mid) update(2 * node + 1, start, mid, idx, val);
      else update(2 * node + 2, mid + 1, end, idx, val);
      tree[node] = joinValue(tree[2 * node + 1], tree[2 * node + 2]);
    }

    num_t query(int node, int start, int end, int l, int r) {
      if (start > r || end < l) return defaultValue;
      if (l <= start && end <= r) return tree[node];
      int mid = (start + end) / 2;
      num_t left = query(2 * node + 1, start, mid, l, r);
      num_t right = query(2 * node + 2, mid + 1, end, l, r);
      return joinValue(left, right);
    }
};