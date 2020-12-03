#include "LitFactory.h"

#include "Litteral.h"

std::map<LitType, LitFactory*> LitFactory::getLitFactories(){
  std::map<LitType, LitFactory*>litteraux;
  std::pair<LitType, LitFactory*> entry;

  entry.first = INTLIT;
  entry.second = new INTFactory();
  litteraux.insert(entry);

  entry.first = RATIONALLIT;
  entry.second = new RATFactory();
  litteraux.insert(entry);

  entry.first = REALLIT;
  entry.second = new REALFactory();
  litteraux.insert(entry);

  entry.first = PROGLIT;
  entry.second = new PROGFactory();
  litteraux.insert(entry);

  entry.first = EXPLIT;
  entry.second = new EXPFactory();
  litteraux.insert(entry);

  entry.first = ATOMLIT;
  entry.second = new ATOMFactory();
  litteraux.insert(entry);

  return litteraux;
}

Operand* RATFactory::getLitteral(std::string str){
  using namespace std;
  string num = "", den = "";
  bool numBool = true;
  for (int i = 0; i < str.length(); i++) {
	  if (str[i] == '/') {
		  numBool = false;
	  }
	  else {
		  if (numBool) {
			  num.append(1, str[i]);
		  }
		  else {
			  den.append(1, str[i]);
		  }
	  }

  }
  return new RationalLit(stoi(num), stoi(den));
}

Operand* ATOMFactory::getLitteral(std::string str)
{
    return nullptr;
}

Operand* REALFactory::getLitteral(std::string str)
{
    return nullptr;
}

Operand* EXPFactory::getLitteral(std::string str)
{
    return nullptr;
}

Operand* PROGFactory::getLitteral(std::string str)
{
    return nullptr;
}

Operand* INTFactory::getLitteral(std::string str)
{
    return nullptr;
}
