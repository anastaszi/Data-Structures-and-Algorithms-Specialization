#include <iostream>


int get_change(int m) {
    int n = 0;
    int change[] = {10, 5, 1};
    int size = *(&change + 1) - change;
    
    for (int i = 0; m > 0 && i < size; i++) {
        n += m / change[i];
        m %= change[i];
    }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
