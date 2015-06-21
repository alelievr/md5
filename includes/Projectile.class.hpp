#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP
# include <iostream>
# include <string>
# include "Ship.class.hpp"

class		Projectile : public Ship
{
	private:
		Projectile* _next;
		Projectile* _prev;

	public:
		Projectile(void);
		Projectile(int a0, int a1, int a2, int d, char a3);
		Projectile(const Projectile&);
		virtual ~Projectile(void);

		Projectile &	operator=(Projectile const & src);

		char	c;
		int		speed;
		Projectile*   getNext(void) const;
		void    setNext(Projectile*);
		void	move(void);

		Projectile*   getPrev(void) const;
		void    setPrev(Projectile*);

		void    append(Projectile*);
};

std::ostream &	operator<<(std::ostream & o, Projectile const & r);

#endif
