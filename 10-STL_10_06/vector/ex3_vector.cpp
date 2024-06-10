#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int>::const_iterator it;
    vector<int>::iterator it2;
    vector<int> v2(10);
    cout << "v2. size ()= " << v2.size() << endl;
    cout << "v2. max_size ()= " << v2.max_size() << endl;
    if (v2.empty())
        cout << " vazio ... " << endl;
    else
    {
        for (it = v2.begin(); it != v2.end(); ++it)
            cout << *it << ' ';
        cout << endl;
        int x = 10;
        for (it2 = v2.begin(); it2 != v2.end(); ++it2)
        {
            *it2 = x;
            x += 10;
        }
        for (it = v2.begin(); it != v2.end(); ++it)
            cout << *it << ' ';
        cout << endl;
        v2.pop_back();
        v2.pop_back();
        cout << "2 x v2. pop_back (); " << endl;
        cout << "v2. size ()= " << v2.size() << endl;
        for (it = v2.begin(); it != v2.end(); ++it)
            cout << *it << ' ';
        cout << endl;
        v2.erase(v2.begin() + 1);
        cout << "v2. erase (v2. begin ()+1); " << endl;
        cout << "v2. size ()= " << v2.size() << endl;
        for (it = v2.begin(); it != v2.end(); ++it)
            cout << *it << ' ';
        cout << endl;
        // Apaga elementos de ind . 4 (5.) ate ind . 5 (6.)
        v2.erase(v2.begin() + 4, v2.begin() + 6);
        cout << "v2. erase (v2. begin ()+4 , v2. begin ()+6); " << endl;
        cout << "v2. size ()= " << v2.size() << endl;
        for (it = v2.begin(); it != v2.end(); ++it)
            cout << *it << ' ';
        cout << endl;
        it = v2.begin();
        for (int i = 0; i < v2.size(); ++i)
            cout << *(it + i) << ' ';
        cout << endl;
        for (int i = 0; i < v2.size(); ++i)
            cout << it[i] << ' ';
        cout << endl;
        for (int i = 0; i < v2.size(); ++i)
            cout << v2[i] << ' ';
        cout << endl;
    }
    return 0;
}