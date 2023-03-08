#ifndef DEF_CHARACTER
#define DEF_CHARACTER

#include <iostream>
#include <string>

#include "Weapon.hpp"

class Character
{
	public:

	Character(std::string name);
	Character(Character const& copyChar);
	Character(std::string name, std::string weaponName, int weaponDamage);
	~Character();
	void takeDamage(int nbDamage);
	void attack(Character &target);
	void drinkHealPotion(int quantity);
	void changeWeapon(std::string newWeaponName, int newWeaponDamage);
	void showStatus() const;
	bool isAlive() const;

	private:

	std::string m_name;
	int m_life;
	int m_mana;
	Weapon* m_weapon;
};

#endif
