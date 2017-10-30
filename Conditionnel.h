#ifndef CONDITIONNEL_H
#define CONDITIONNEL_H


class Conditionnel : public Expression
{
    Binaire *_cond;
    Expression *_opleft, *_opright;
public:
    Conditionnel(const string& nom, Binaire *cond, Expression *opleft, Expression *opright) : Expression(nom), _cond(cond), _opleft(opleft), _opright(opright) {}
    double eval() const;
};


#endif // CONDITIONNEL_H
