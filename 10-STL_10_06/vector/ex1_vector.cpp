#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1; // vetor vazio de inteiros
    cout << "v1. size ()= " << v1.size() << endl;
    for (vector<int>::iterator it = v1.begin();
         it != v1.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    vector<int> v2(4, 100); // quatro ints com 100
    cout << "v2. size ()= " << v2.size() << endl;
    for (vector<int>::iterator it = v2.begin();
         it != v2.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    vector<int> v3(v2.begin(), v2.end()); // it. de v2
    cout << "v3. size ()= " << v3.size() << endl;
    for (vector<int>::iterator it = v3.begin();
         it != v3.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    vector<int> v4(v3); // uma copia de v3
    cout << "v4. size ()= " << v4.size() << endl;
    for (vector<int>::iterator it = v4.begin();
         it != v4.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    // o construtor tambem pode ser usado com arrays
    int myints[] = {16, 2, 77, 29};
vector <int > v5 ( myints , myints + sizeof ( myints ) / sizeof (cout << "O conteudo de v5 eh:";
for ( vector <int >:: iterator it = v5 . begin ();
it != v5 . end (); ++ it )
cout << ' ' << * it ;
cout << '\n';
cout << * v5 . begin () << endl ;
cout << v5 . begin ()[0] << endl ;
cout << v5 [0] << endl ;
cout << *( v5 . end () -1) << endl ;
cout << v5 [ v5 . size () -1] << endl ;
return 0;
}