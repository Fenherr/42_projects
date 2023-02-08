#include <iostream>
#include <string>
#include "Character.hpp"

int main()
{
	Character character1("David");
	Character character2("Goliath", "Épée aiguisée", 20);
	Character character3("Jesus", "Magie sacrée", 20);

	character2.attack(character1);
	character1.drinkHealPotion(20);
	character2.attack(character1);
	character1.attack(character2);
	character2.attack(character1);
	character1.drinkHealPotion(20);
	while (character1.isAlive() && character2.isAlive())
	{
		character2.attack(character1);
		character3.attack(character2);
		character1.attack(character2);
	}

	character1.showStatus();
	std::cout << std::endl;
	character2.showStatus();
	std::cout << std::endl;
	character3.showStatus();

	if (!character1.isAlive())
		std::cout << std::endl << "Goliath a tué David" << std::endl;
	else
		std::cout << std::endl << "David a tué Goliath (avec l'aide de Jésus)" << std::endl;
	return (0);
}
