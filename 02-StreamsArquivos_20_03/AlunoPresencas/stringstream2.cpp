#include <iostream>
#include <sstream>	

using namespace std;

class Pessoa {
private:
  string nome;
  int idade;
public:
  Pessoa(string n = "", int i = 0) { nome = n;  idade = i; }

  string str() {
    stringstream ss;
    ss << nome << " (" << idade << " anos)";
    return ss.str();
  }

};

int main() {
  Pessoa p("Joao", 21);
  cout << p.str() << endl;
  return 0;
}
