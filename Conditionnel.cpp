#include "Conditionnel.h"
Conditionnel(const string& nom, Binaire *cond, Expression *opleft, Expression *opright) : Expression(nom), _cond(cond), _opleft(opleft), _opright(opright)
{

}

double Conditionnel::eval() const
{
    return ((_cond->eval()) ? _op1->eval() : _op2->eval());
}
