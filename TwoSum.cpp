#include <iostream>
#include <unordered_map>
#include <vector>

namespace Two {
void findingSum(std::vector<int> sum, int total);

void run() {
  std::vector<int> sum;
  int input;
  int total;

  while (std::cin >> input) {
    if (input == -1) {
      break;
    }
    sum.push_back(input);
  }
  std::cin >> total;
  findingSum(sum, total);
}

void findingSum(std::vector<int> sum, int total) {

  for (int i = 0; i < sum.size(); i++) {
    std::cout << sum[i];
    // or do for( int m :sum)
  }
  std::cout << std::endl;
  std::unordered_map<int, int> map; // key=int, value=int

  // finding the solution
  for (int i = 0; i < sum.size(); i++) {
    int temp = 0;
    int sums = sum[i];
    map[sums] = i; // (value,  location)

    // std::cout << "here is the map value" << map[sums] << ',' << i <<
    // std::endl;

    temp = total - sum[i]; // total looking for - current number

    //  std::cout << "here is the map temp value" << map[temp] << ',' << temp<<
    //  std::endl;

    // if found it will not make it to the end
    auto o = map.find(temp);
    if (o != map.end()) {
      std::cout << "[" << o->second << "," << i << ']' << std::endl;
    }
  }
  /*
      if(map.find(temp)!=m.end()){
            ans.push_back(i);
            ans.push_back(m[second]);
            break;
        }

  */

  std::cout << std::endl;
}
} // namespace Two
int main() {
  Two::run();
  return 0;
}