#include <iostream>
#include <sstream>
using namespace std;
int main () {
  string aux = "string de teste ";
  stringstream ss;
  ss << "120 42 377 6 5 20\n";
  ss << aux;
  ss << 10;
  ss << "\n\tteste\n";
  ss << "final de string";
  cout << "resultado: " << ss.str();
  cout << endl;
  return 0;
}
