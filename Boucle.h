#ifndef BOUCLE_H
#define BOUCLE_H

using namespace std;


#include "variable.h"
class Pour : public Expression
{
protected:
    Expression *_init, *_condition, *_incremente, *_calcul;
public:
    Pour(Expression *init, Expression *cond, Expression *inc, Expression *calc);
    double eval() const
    {
        double res;
        _init->eval();
        while (_condition->eval() != 0.0)
        {
            res = _calcul->eval();
            _incremente->eval();
        }
        return res;
    }
    string str() const
    {
        return _nom + " (" + _init->str() + " ; " + _condition->str() + " ; "
               + _incremente->str() + ") { " + _calcul->str() + " }";
    }
};








/*
class boucle
{
    public:
        boucle();
        virtual ~boucle();
    protected:
    private:
};
*/
#endif // BOUCLE_H
