#include <iostream>
#include <sstream>

using namespace std;

class StringList {
private:
    class Node {
    public:
        string data;
        Node *prev, *next;
        Node(string d)
        {
            data = d;
            prev = next = nullptr;
        }
    };
    Node *head, *tail;

public:
    StringList();
    ~StringList();
    void add(string s);
    string str();
};

StringList :: StringList(){
    head = tail = nullptr;
}

StringList :: ~StringList(){
    while(head != nullptr){
        Node *atual = head; // guarda head em atual
        head = head->next; // head passa pro próximo
        delete atual; // deleta o atual (que recebeu o valor de head)
    }
}

void StringList :: add(string s){
    Node *novo = new Node(s);
    if (head = nullptr){
        head = tail = novo;
    } else {
        tail->next = novo;
        novo->prev = tail;
        tail = novo;
    }
}

string StringList :: str(){
    stringstream ss;
    Node *atual = head;
    while (head != nullptr){
        ss << atual->data << endl;
        atual = atual->next;
    }
    return ss.str();
}

int main(){
    return 0;
}