#include <iostream>
#include <sstream>

int main(int argc, char**argv) {
  std::stringstream ss;
  ss << 45 << "%";
  std::cout << ss.str() << "\n";
}
