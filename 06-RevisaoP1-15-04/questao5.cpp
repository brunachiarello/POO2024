#include <iostream>

using namespace std;

class Classe {
private:
    int a;

public:
    Classe(int b){
        a = b;
        ImprimeA();
    }

    ~Classe(){
        IncrementaA();
        ImprimeA();
    }

    void IncrementaA(){
        a++;
    }

    void ImprimeA(){
        cout << "[" << a << "]";
    }
};

int main(){
    Classe *classeX = new Classe(1);
    Classe classeY(10);
    return 0;
}
