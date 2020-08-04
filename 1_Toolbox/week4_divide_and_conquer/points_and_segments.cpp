#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

long long* partition3(vector<long long> &a, long long l, long long r, long long *m) {
    long long x = a[l];
    long long m1 = l;
    long long m2 = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] < x) {
            m1++;
            swap(a[i], a[m1]);
            m2++;
            if (m1 < m2)
                swap(a[i], a[m2]);
        }
        else if (a[i] == x) {
            m2++;
            swap(a[i], a[m2]);
        }
    }
    swap(a[l], a[m1]);
    m[0] = m1;
    m[1] = m2;
    return m;
}

void randomized_quick_sort(vector<long long> &a, long long l, long long r) {
    if (l >= r) {
        return;
    }
    
    long long k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    long long localArr[2];
    long long* m = partition3(a, l, r, localArr);
    
    randomized_quick_sort(a, l, m[0] - 1);
    randomized_quick_sort(a, m[1] + 1, r);
}

long long searchIndex(vector<long long> &data, long long left, long long right, long long point) {
    if (left > right)
        return left - 1;
    long long middle = (right - left) / 2 + left;
    if (data[middle] == point)
        return middle;
    if (point > data[middle])
        return searchIndex(data, middle + 1, right, point);
    else
        return searchIndex(data, left, middle - 1, point);
}

vector<long long> fast_count_segments(vector<long long> &starts, vector<long long> &ends, vector<long long> points) {
  vector<long long> cnt(points.size());
    randomized_quick_sort(starts, 0, starts.size() - 1);
    randomized_quick_sort(ends, 0, ends.size() - 1);
    for (long long i = 0; i < points.size(); i++)
    {
        //std::cout << "=========[POINT]: " << points[i] << std::endl;
        int left = searchIndex(starts, 0, starts.size(), points[i]);
        //std::cout << " ===> left1: " << left;
        left = (left == starts.size()) ? left : left + 1;
        //std::cout << " left2: " << left << " <==== "<<std::endl;
        int right = searchIndex(ends, 0, ends.size(), points[i]);
        //std::cout << " ===> right1: " << right;
        if (right == -1)
            right = ends.size();
        else if (right == ends.size())
            right = 0;
        else
            right = ends.size() - right - (points[i] != ends[right]);
        //right = (right == -1) ? ends.size() : (int)ends.size() - right;
       // std::cout << " right2: " << right << " <==== "<< std::endl;
        cnt[i] = left + right - starts.size();
    }
  return cnt;
}

vector<long long> naive_count_segments(vector<long long> starts, vector<long long> ends, vector<long long> points) {
  vector<long long> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<long long> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<long long> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<long long> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
