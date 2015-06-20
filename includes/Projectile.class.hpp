#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP
# include <iostream>
# include <string>
# include "ft_retro.h"

class		Projectile : public Ship
{
	private:

	public:
		Projectile(void);
		Projectile(int a0, int a1, int a2, char a3);
		Projectile(const Projectile&);
		~Projectile(void);

		Projectile &	operator=(Projectile const & src);
		char	c;
};

std::ostream &	operator<<(std::ostream & o, Projectile const & r);

#endif
