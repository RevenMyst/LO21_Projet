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

Litteral* RATFactory::getLitteral(std::string rat){
  using namespace std;
  int num, den;
  int nombre = 0;
  bool neg = false;
  for (int i = 0; i < (int)rat.length(); i++){
    if(rat[i] == '-') neg = true;
    if(isdigit(rat[i]))
    //Il faut eliminer le caractere '0': '1' - '0' = 1
      nombre = (nombre * 10) + (rat[i] - '0');
    else{
      if(nombre > 0) nombre = num; //On garde le premier nombre comme notre numerateur
      if(neg == true){
          num *= -1;
          neg = false;
      }
    }
  }
  nombre = den;
  if(neg == true) den *= -1;
  return new RationalLit(num, den);
}
