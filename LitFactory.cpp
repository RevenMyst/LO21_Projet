#include "LitFactory.h"
#include "Litteral.h"
#include "Operator.h"
#include "Computer.h"
#include <regex>

std::vector<LitFactory*> LitFactory::getLitFactories()
{
	std::vector<LitFactory*>litteraux;

	litteraux.push_back(new INTFactory());

	litteraux.push_back(new REALFactory());

	litteraux.push_back(new ATOMFactory());

	litteraux.push_back(new PROGFactory());

	litteraux.push_back(new EXPFactory());

	//litteraux.push_back(new RATFactory());
	//La commande ne peux creer directement une litterale rationnelle

	return litteraux;
}


bool RATFactory::isTypeLit(std::string str)
{
	return std::regex_match(str, std::regex("-?[0-9]+/-?[0-9]+"));
}

Operand* RATFactory::getLitteral(std::string str){
  using namespace std;
  string num = "", den = "";
  bool numBool = true;
  for (size_t i = 0; i < str.length(); i++) {
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

bool ATOMFactory::isTypeLit(std::string str)
{
	return std::regex_match(str, std::regex("([A-Z]+[0-9]*)+"));
}

Operand* ATOMFactory::getLitteral(std::string str)
{
	//return new AtomLit(str);
	return nullptr;
}

bool REALFactory::isTypeLit(std::string str)
{
	return std::regex_match(str, std::regex("-?[0-9]*\\.[0-9]*"));
}

Operand* REALFactory::getLitteral(std::string str)
{
    return nullptr;
}

bool EXPFactory::isTypeLit(std::string str)
{
	return std::regex_match(str, std::regex("'([A-Z]+[0-9]*)+'"));;
}

Operand* EXPFactory::getLitteral(std::string str)
{
	return new ExpLit(str);
}

bool PROGFactory::isTypeLit(std::string str)
{
	return str[0] == '[' && str[str.size() - 1] == ']';
}

Operand* PROGFactory::getLitteral(std::string str)
{
	ProgLit* lit = new ProgLit();
	std::vector<std::string> tab = Computer::parse(str);
	for (std::string s : tab) {
		lit->addOperand(Computer::createOperand(s));
	}
	return lit;
}

bool INTFactory::isTypeLit(std::string str)
{
	return std::regex_match(str, std::regex("[0-9]+"));
}

Operand* INTFactory::getLitteral(std::string str)
{
    return new IntLit(stoi(str));
}


