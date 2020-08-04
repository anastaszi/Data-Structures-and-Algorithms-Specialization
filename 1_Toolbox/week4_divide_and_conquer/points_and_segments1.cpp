#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::swap;

using namespace std;
/*
int* partition3(vector<int> &a, int l, int r, int *m) {
    int x = a[l];
    int m1 = l;
    int m2 = l;
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

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }
    
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int localArr[2];
    int* m = partition3(a, l, r, localArr);
    
    randomized_quick_sort(a, l, m[0] - 1);
    randomized_quick_sort(a, m[1] + 1, r);
}

int searchIndex(vector<int> &data, int left, int right, int point) {
    if (left > right)
        return left - 1;
    int middle = (right - left) / 2 + left;
    if (data[middle] == point)
        return middle;
    if (point > data[middle])
        return searchIndex(data, middle + 1, right, point);
    else
        return searchIndex(data, left, middle - 1, point);
}

*/

typedef struct Points {
    int p;
    char t;
} Point;

bool comparePoints (Point first, Point second) {
    if (first.p != second.p)
        return (first.p < second.p);
    return (first.t < second.t);
}

int bSearch(vector<int> &a, int left, int right, int point) {
    if (left > right)
        return -1;
    int middle = (right - left) / 2 + left;
    if (a[middle] == point)
        return middle;
    if (point > a[middle])
        return bSearch(a, middle + 1, right, point);
    return bSearch(a, left, middle - 1, point);
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    
    
    //fill coordinate vector
    vector<Point>coord;
    
    for(int i = 0; i < starts.size(); i++) {
        Point sPoint, ePoint;
        sPoint.p = starts[i];
        sPoint.t = 'l';
        ePoint.p = ends[i];
        ePoint.t = 'r';
        coord.push_back(sPoint);
        coord.push_back(ePoint);
    }
    
    for (int i = 0; i < points.size(); i++) {
        Point temp;
        temp.p = points[i];
        temp.t = 'p';
        coord.push_back(temp);
    }
    
    sort(coord.begin(), coord.end(), comparePoints);
    
    int segments = 0;
    vector<int>cntSorted;
    vector<int>cntData;
    
    for (int i = 0; i < coord.size(); i++) {
        if (coord[i].t == 'l')
            segments++;
        else if (coord[i].t == 'r')
            segments--;
        else {
            if (!cntSorted.size() || cntSorted.back() != coord[i].p) {
                cntSorted.push_back(coord[i].p);
                cntData.push_back(segments);
            }
        }
    }
    /*
    for (int i = 0; i < coord.size(); i++) {
        std::cout << coord[i].p << coord[i].t << std::endl;
    }
    
    for (int i = 0; i < cntSorted.size(); i++) {
        std::cout << cntSorted[i] << " -> " << cntData[i] << std::endl;
    }*/
    
    for (int i = 0; i < points.size(); i++) {
        int index = bSearch(cntSorted, 0 , cntSorted.size(), points[i]);
        cnt[i] = cntData[index];
    }
    
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
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
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
