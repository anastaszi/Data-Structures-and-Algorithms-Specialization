#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <sstream>
#include <string>

using std::vector;
using namespace std;

struct Segment {
  int start, end;
    bool visited = false;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
    //find min and max points
   int maxX = 0;
    int minX = INT_MAX;
    int remaining = segments.size();
    
    if (!remaining)
        return points;
  //write your code here
  for (size_t i = 0; i < segments.size(); ++i) {
      if(segments[i].start < minX)
          minX = segments[i].start;
      if (segments[i].end > maxX)
          maxX = segments[i].end;
  }
   
    vector<int> dots(maxX - minX);
    fill(dots.begin(), dots.end(), 0);
    for (size_t i = 0; i < segments.size(); ++i) {
        for (int j = segments[i].start; j <= segments[i].end; j++)
            dots[j - minX]++;
    }
 
    while (remaining) {
        int index;
        int maxDot = 0;
        for (int i = 0; i < (maxX - minX); i++) {
            if (dots[i] > maxDot) {
                maxDot = dots[i];
                index = i;
            }
        }
        
        for (size_t i = 0; i < segments.size(); i++) {
             if (!segments[i].visited && (segments[i].start <= (index + minX)) && (segments[i].end >= (index + minX)) ) {
                remaining--;
                segments[i].visited = true;
                for (int j = segments[i].start; j <= segments[i].end; j++) {
                    dots[j - minX]--;
                }
                
            }
        }
        points.push_back(index + minX);
        //find max dots, pushback point, markSegment visited && decreate remaining, update dots
    }
  return points;
}

int main() {
  int n;
    string myString;
    getline(cin, myString);
    stringstream(myString) >> n;
    vector<Segment> segments(n);
   
  for (size_t i = 0; i < segments.size(); i++) {
      getline(cin, myString);
      stringstream(myString) >> segments[i].start >> segments[i].end;
  }
 vector<int> points = optimal_points(segments);
 std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
    return 0;
}
