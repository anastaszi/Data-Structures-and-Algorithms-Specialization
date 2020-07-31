#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using std::vector;
using std::string;

using namespace std;

bool compFunction(string a, string b) {
    return atoi((a + b).c_str()) < atoi((b + a).c_str());
}
/*
bool compFunction1(string a, string b) {
    int lengthA = a.length();
    int lengthB = b.length();
    if (lengthA == 4 || lengthB == 4)
        return (lengthA == 4);
    if (lengthA == lengthB)
        return a < b;
    else if (lengthA + lengthB == 3)
        return (lengthA < lengthB) ? (a[lengthA - 1] < b[lengthA]) : (a[lengthB] < b[lengthB - 1]);
    else if (lengthA + lengthB == 4) {
        if (lengthA < lengthB)
            return (a[lengthA - 1] != b[lengthA]) ? (a[lengthA - 1] < b[lengthA]) : (a[lengthA - 1] < b[lengthA + 1]);
        return (a[lengthB] != b[lengthB - 1]) ? (a[lengthB] < b[lengthB - 1]) : (a[lengthB + 1] < b[lengthB - 1]);
        
    }
    if (lengthA < lengthB)
        return (a[lengthA - 1] != b[lengthA - 1]) ? (a[lengthA - 1] < b[lengthA - 1]) : (a[0] < b[lengthA]);
    return (a[lengthB - 1] != b[lengthB - 1]) ? (a[lengthB - 1] < b[lengthB - 1]): (a[lengthB] < b[0]);
}*/

string largest_number(vector<string> a) {
  //write your code here
    vector<string> stringArray[9];
    std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
      stringArray[a[i][0] - 49].push_back(a[i]);
  }
    for (int i = 8; i > -1; i--) {
       std::sort(stringArray[i].begin(), stringArray[i].end(), compFunction);
       for (int j = stringArray[i].size() - 1; j > -1; j--)
           ret << stringArray[i][j];
    }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
