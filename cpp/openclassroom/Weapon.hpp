#ifndef DEF_WEAPON
#define DEF_WEAPON

#include <iostream>
#include <string>

class Weapon
{
	public:

	Weapon();
	Weapon(std::string name, int damage);
	void change(std::string name, int damage);
	void display() const;
	int getDamage();

	private:

	std::string m_name;
	int m_damage;
};

#endif
