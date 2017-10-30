#include "Expression.h"

using namespace std;

Expression(const string& nom) : _nom(nom)
{
    _pool.insert(this);

    // cout << "enregistrer" << _nom << endl;

}
Expression::~Expression()
{
    _pool.erase(this);

    // cout << "liberer" << _nom << endl;

}
