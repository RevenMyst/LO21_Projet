#include "Action.h"
#include "Litteral.h"

map<tuple<string, LitType, LitType>, Action*> Action::getActions()
{
    map <tuple<string, LitType, LitType>, Action*> actions;
    pair<tuple<string, LitType, LitType>, Action*> entry;
    tuple<string, LitType, LitType> t;

    t = make_tuple("+", INTLIT, INTLIT);
    entry.first = t;
    entry.second = new PlusSimpleAction();
    actions.insert(entry);

    t = make_tuple("+", REALLIT, INTLIT);
    entry.first = t;
    entry.second = new PlusSimpleAction();
    actions.insert(entry);

    t = make_tuple("+", REALLIT, REALLIT);
    entry.first = t;
    entry.second = new PlusSimpleAction();
    actions.insert(entry);

    t = make_tuple("+", INTLIT, REALLIT);
    entry.first = t;
    entry.second = new PlusSimpleAction();
    actions.insert(entry);

    return actions;
}

bool Action::exist(tuple<string, LitType, LitType> t)
{
    return getActions().count(t) > 0;
}



//additions simples : int + int, int + reel, reel + int, reel + reel
Litteral* PlusSimpleAction::exec(Litteral* l1, Litteral* l2)
{
    NumLit* lit1 = dynamic_cast<NumLit*>(l1);
    NumLit* lit2 = dynamic_cast<NumLit*>(l2);
    //si mantisse nulle le Reel est  simplifié à l'empilement
    return new RealLit(lit1->getValue() + lit2->getValue());
}

