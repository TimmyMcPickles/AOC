#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream file("../input.txt");
  std::vector<int> list1, list2;
  int x, y;
  int distance = 0;

  while (file >> x >> y) {
    list1.push_back(x);
    list2.push_back(y);
  }

  std::sort(list1.begin(), list1.end());
  std::sort(list2.begin(), list2.end());

  for (int i = 0; i < list1.size(); i++) {
    distance += abs(list1[i] - list2[i]);
  }

  std::cout << distance << std::endl;

  return 0;
}
