#ifndef SHIP_HPP
# define SHIP_HPP
# include <iostream>
# include <string>

class		Ship
{
	protected:
		bool	display;

	private:
		std::string	_name;
		int	_x;
		int	_y;
		int	_HP;
		int	_MHP;
		int	_index;

	public:
		Ship(std::string a0, int a1, int a2, int a3, int a4);
		Ship(const Ship & src);
		~Ship(void);

		Ship &	operator=(Ship const & src);

		int			direction;

		virtual void	fire(void);
		virtual void	die(void);
		virtual void	move(int x, int y);

		std::string	getName(void) const;
		void	setName(std::string tmp);
		
		int	getX(void) const;
		void	setX(int tmp);
		
		int	getY(void) const;
		void	setY(int tmp);
		
		int	getHP(void) const;
		void	setHP(int tmp);
		
		int	getMHP(void) const;
		void	setMHP(int tmp);

		int	getIndex(void) const;
		void	setIndex(int i);

		void	setDisplay(bool status);

		int	genIndex(void);
};

std::ostream &	operator<<(std::ostream & o, Ship const & r);

#endif
