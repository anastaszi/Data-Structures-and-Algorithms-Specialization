#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;

using namespace std;

bool sortCoordByX(pair<int, int>point1, pair<int, int>point2) {
    return point1.first < point2.first;
}

bool sortCoordByY(pair<int, int>point1, pair<int, int>point2) {
    return point1.second < point2.second;
}

double distance(pair<int, int>p1, pair<int, int>p2) {
    return sqrt(((double)p1.first - p2.first)*(p1.first - p2.first) + ((double)p1.second - p2.second)*(p1.second - p2.second));
}

double naive_distance(vector<pair<int, int>>coords, int size) {
    if (size == 2)
        return distance(coords[0], coords[1]);
    double d1 = distance(coords[0], coords[1]);
    double d2 = distance(coords[1], coords[2]);
    double d3 = distance(coords[0], coords[2]);
    return min(min(d1,d2),d3);
}

double segmentDist(vector<pair<int, int>>segment, int size, double minDist) {
    
    sort(segment.begin(), segment.end(), sortCoordByY);
    double x = minDist;
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && (segment[j].second - segment[i].second) < minDist; j++ ) {
            if (distance(segment[i], segment[j]) < x)
                x = distance(segment[i], segment[j]);
        }
    }
    return x;
}

double find_minimum(vector<pair<int,int>>coords, int size) {
    //cout << "size: " << size << endl;
    if (size <= 3) {
        return naive_distance(coords, size);
    }
    int middle = size / 2;
    vector<pair<int, int>>left(coords.begin(), coords.begin() + middle);
    vector<pair<int, int>>right(coords.begin() + middle, coords.end());
    
    double distLeft = find_minimum(left, left.size());
    double distRight = find_minimum(right, right.size());
    
    double minDist = min(distLeft, distRight);
    vector<pair<int, int>>closePoints;
    
    for (int i = 0; i < coords.size(); i++) {
        if (abs((double)coords[middle - 1].first - coords[i].first) < minDist)
            closePoints.push_back(coords[i]);
    }
   
    /*cout << minDist << endl;
    for (int i = 0; i < closePoints.size(); i++) {
        cout << "x: "<< closePoints[i].first << ", y: "<< closePoints[i].second << endl;
    }*/
    return min(minDist, segmentDist(closePoints, closePoints.size(), minDist));
}

double minimal_distance(vector<int> x, vector<int> y) {
    vector<pair<int, int>>coords;
    for (int i = 0; i < x.size(); i++) {
        coords.push_back(make_pair(x[i], y[i]));
    }
    
    sort(coords.begin(), coords.end(), sortCoordByX);
    /*for (int i = 0; i < coords.size(); i++) {
        cout << "x: "<< coords[i].first << ", y: "<< coords[i].second << endl;
    }
    */
    return find_minimum(coords, coords.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
