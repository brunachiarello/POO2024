#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int>::const_iterator it;
    vector<int> v1;
    cout << "v1. size ()= " << v1.size() << endl;
    cout << "v1. max_size ()= " << v1.max_size() << endl;
    if (v1.empty())
        cout << " vazio ... ";
    else
        for (it = v1.begin(); it != v1.end(); ++it)
            cout << *it << ' ';
    cout << endl;
    cout << "v1. push_back (12); " << endl;
    v1.push_back(12);
    cout << "v1. push_back (34); " << endl;
    v1.push_back(34);
    cout << "v1. push_back (56); " << endl;
    v1.push_back(56);
    cout << "v1. size ()= " << v1.size() << endl;
    for (it = v1.begin(); it != v1.end(); ++it)
        cout << *it << ' ';
    cout << endl;
    return 0;
}
