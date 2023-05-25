#include <iostream>

class ASpell
{
	private:
		ASpell(ASpell const& cpy);
		ASpell & operator=(ASpell const & rhs);

	protected:
		std::string _name;
		std::string _effects;

	public:
		ASpell(std::string name, std::string effects);
		std::string getName() const;
		std::string getEffects() const;

		virtual ASpell *clone() const = 0;
};
