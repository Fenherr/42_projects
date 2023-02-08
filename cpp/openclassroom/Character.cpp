#include <string>
#include "Character.hpp"

Character::Character(std::string name) :
	m_name(name),
	m_life(100),
	m_mana(100),
	m_weapon("Épée rouillée", 10)
{}

Character::Character(std::string name, std::string weaponName, int weaponDamage) :
	m_name(name),
	m_life(100),
	m_mana(100),
	m_weapon(weaponName, weaponDamage)
{}

Character::~Character()
{}

void Character::takeDamage(int nbDamage)
{
	m_life -= nbDamage;
	if (m_life < 0)
		m_life = 0;
}

void Character::attack(Character &target)
{
	target.takeDamage(m_weapon.getDamage());
}

void Character::drinkHealPotion(int quantity)
{
	m_life += quantity;
	if (m_life > 100)
		m_life = 100;
}

void Character::changeWeapon(std::string newWeaponName, int newWeaponDamage)
{
	m_weapon.change(newWeaponName, newWeaponDamage);
}

void Character::showStatus() const
{
	std::cout << m_name << std::endl;
	std::cout << "Vie : " << m_life << std::endl;
	std::cout << "Mana : " << m_mana << std::endl;
	m_weapon.display();
}

bool Character::isAlive() const
{
	return (m_life > 0);
}
