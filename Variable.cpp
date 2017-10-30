#include "variable.h"

Variable(const string& nom) : Expression(nom)
{

}

Variable(const string& nom, double init) : Expression(nom)
{
    _memoire[_nom] = init;
}
