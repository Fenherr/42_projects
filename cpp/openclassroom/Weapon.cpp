#include <string>
#include "Weapon.hpp"

Weapon::Weapon()
{
	m_name = "Épée rouillée";
	m_damage = 10;
}

Weapon::Weapon(std::string name, int damage) :
	m_name(name),
	m_damage(damage)
{}

void Weapon::change(std::string name, int damage)
{
	m_name = name;
	m_damage = damage;
}

void Weapon::display() const
{
	std::cout << "Arme : " << m_name << " (Dégâts : " << m_damage << ")" << std::endl;
}

int Weapon::getDamage()
{
	return (m_damage);
}
