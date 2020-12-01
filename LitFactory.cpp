#include "LitFactory.h"

std::map<std::string, LitFactory*> LitFactory::getLitFactories(){
  std::map<std::string, OpeFactory*>litteraux;
  std::pair<std::string, OpeFactory*> entry;

  entry.first = "INTLIT"
  entry.second = new INTFactory();
  litteraux.insert(entry);

  entry.first = "REALLIT"
  entry.second = new REALFactory();
  litteraux.insert(entry);

  entry.first = "RATIONALLIT"
  entry.second = new RATFactory();
  litteraux.insert(entry);

  entry.first = "REALLIT"
  entry.second = new REALFactory();
  litteraux.insert(entry);

  entry.first = "PROGLIT"
  entry.second = new PROGFactory();
  litteraux.insert(entry);

  entry.first = "EXPLIT"
  entry.second = new EXPFactory();
  litteraux.insert(entry);

  return litteraux;
}

bool LitFactory::isLit(std::string Lit){
  return getLitFactories().count(Lit) > 0;
}
