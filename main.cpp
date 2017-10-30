#include <iostream>
#include "Expression.h"
#include "Binaire.h"
#include "Variable.h"
#include "Conditionnel.h"
#include "Boucle.h"

using namespace std;

// Le code ne compile pas car il y a un problème de liens entre les fichiers que nous n'avons pas résolu

void main()
{
    cout << "\tPROJET CHAMI - MADERN" << endl;
    cout << "Premiere partie" << endl;
    Cos *c = new Cos(new Constante(M_PI/3.0));
    cout << *c << " = " << c->eval() << endl;

    cout << "Deuxieme partie" << endl;
    Somme *s = new Somme( new Constante(1.0),
                          new Produit(new Constante(2.0),
                                      new Sin(new Constante(M_PI/6.0))
                                     )
                        );
    cout << *s << " = " << s->eval() << endl;
    Superieur comp(s, new Constante(1.8));
    cout << comp << " = " << (bool)comp.eval() << endl;
    Expression::toutLiberer();

    cout << "Troisieme partie" << endl;
    Variable x("x", 3.0);
    Variable y("y");
    cout << x << " = " << x.eval() << endl;
    cout << y << " = " << y.eval() << endl;
    Expression *exp = new Somme( new Constante(1.0),
                                 new Produit(new Constante(2.0), new Variable("x")));
    Affectation *a = new Affectation(new Variable("y"), exp);
    cout << *a << " = " << a->eval() << endl;
    cout << y << " = " << y.eval() << endl;
    Variable::effacerMemoire();
    cout << y << " = " << y.eval() << endl;

    cout << "Quatrieme partie" << endl;
    Conditionnel *test =
        new Conditionnel(new InferieurEgal(new Variable("x"), new Constante(0.0)),
                         new Cos(new Variable("x")),
                         new Cos(new Produit(new Constante(2.0), new Variable("x"))));
    Variable *x = new Variable("x", M_PI/3.0);
    cout << *x << " = " << x->eval() << endl;
    cout << *test << " = " << test->eval() << endl;
    x->set( -M_PI/3.0);
    cout << *x << " = " << x->eval() << endl;
    cout << *test << " = " << test->eval() << endl;
    Variable::effacerMemoire();
    Expression::toutLiberer();

// Factorielle

    Pour *factorielle = new Pour(new Variable("y"), i, new Difference(i, new Constante(1)), new Produit(x, new Somme(x, new Constante(1))));
    cout << factorielle->str() << endl;
    cout << factorielle->eval() << endl;*/


    return 0;
}







/*
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
*/
