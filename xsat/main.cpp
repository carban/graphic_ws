#include <iostream>
#include <vector>

using namespace std;


void printVector(vector<int> v){
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << " ";
}

int is3SAT(vector<int> v)
{
    return v.size() == 3;
}

vector<int> make3SAT(vector<int> clauses[], int i, int vars)
{
    vector<int> v = clauses[i];
    int s = v.size(), k = 0, c = 0;
    if (s == 1)
    {
        k = 2;
        c = 4;

        cout << v[0] << " " << vars + k << " " << vars + k - 1 << endl;
        cout << v[0] << " -" << vars + k << " " << vars + k - 1 << endl;
        cout << v[0] << " " << vars + k << " -" << vars + k - 1 << endl;
        cout << v[0] << " -" << vars + k << " -" << vars + k - 1 << endl;

    }
    else if (s == 2)
    {

    }
    else if (s > 3)
    {

    }
}

int main()
{
    int vars = 6;
    int clauses = 3;

    vector<int> a[3];

    vector<int> k1;
    k1.push_back(1);
    k1.push_back(-2);
    k1.push_back(3);

    vector<int> k2;
    k2.push_back(2);
    k2.push_back(4);
    k2.push_back(5);

    vector<int> k3;
    k3.push_back(4);
    //k3.push_back(6);

    a[0] = k1;
    a[1] = k2;
    a[2] = k3;

    for(int i = 0; i < clauses ; i++){
        printVector(a[i]);
        cout << endl;
    }

    cout << "=====================" << endl;

    for (int i = 0; i < clauses ; i++)
    {
        if (a[i].size() < 3)
        {
            // cout << i <<" Is not 3SAT" << endl;
            a[i] = make3SAT(a, i, vars);
            // clauses = newclauses3SAT(clauses, i, vars)
        }
    }

    return 0;
}
