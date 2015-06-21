#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

# define BIT_ON(x, y) (x = x | (1 << y))
# define BIT_OFF(x, y) (x &= ~(1 << y))
# define BIT_TEST(x, y) (((x & (1 << y)) == 0) ? 0 : 1)

# define INTER_FIRE_ENEMY		4000000
# define INTER_MOVE_ENEMY		2000000
# define INTER_MOVE_OBSTACLE	2000000
# define INTER_MOVE_PROJECTILE	70000
# define INTER_MOVE_PLAYER		20000
# define INTER_FIRE_PLAYER		700000
# define INTER_OBSTACLE_APEAR	2000000
# define INTER_ENEMY_APEAR		5500000

# define BOSS_TICK_APEAR		90000000

# define SOUND_LASER 0
# define SOUND_EXPLOSION 1

# define KEY_LEFT	68
# define KEY_RIGHT	67
# define KEY_TOP	65
# define KEY_BOT	66
# define KEY_FIRE	32

# define MASK_SHIP_LOW		"|   |\n" \
							"|_^_|\n" \
							" ^ ^ \n"
# define MASK_SHIP_MEDIUM	"   /\\  \n" \
							"  (  )  \n" \
							"  (  )  \n" \
							" /|/\\|\\\n" \
							"/_||||_\\\n"
# define MASK_OBSTACLE		{"/\\\n\\/\n", "**\n**\n", "++\n++\n", "##\n##\n"}
# define MASK_ENEMYSHIP		{"=!=\n" \
							 "| |\n",\
\
							 "/**\\\n" \
							 "|  |\n", \
\
							 "|-o-|\n", \
\
							 "|   |\n" \
							 "|-o-|\n" \
							 "|   |\n"}
# define MASK_BOSS_1		"" \
"                           |-----------|                                       \n" \
"           i               |===========|                       \n" \
"           |               |,---------.|                      __--~\\__--.\n" \
"    #---,'""""`-_   `n     |`---------'|    `n    `n     ,--~~  __-/~~--'_____.\n" \
"       |~~~~~~~~~|---~---/=|___________|=\\---~-----~-----| .--~~  |  .__|     |\n" \
"     -[|.--_. ===|#####|-| |@@@@|+-+@@@| |]=###|/-++++-[| ||||___+_.  | `===='-.\n" \
"     -[|'==~'    |#####|-| |@@@@|+-+@@@| |]=###|\\-++++-[| ||||~~~+~'  | ,====.-'\n" \
"       |_________|---u---\\=|~~~~~~~~~~~|=/---u-----u-----| '--__  |  '~~|     |\n" \
"        \\       /=-   `    |,---------.|      `     `    `--__  ~~-\\__--.~~~~~'\n" \
"----=:===\\     /           |`---------'|                      ~~--_/~~--'\n" \
"      --<:\\___/--          |===========|\n" \
"                            |-----------|\n" \
"                            |___________|\n" \
# define MASK_EXPLOSION		{"# *  " \
							 " $** " \
							 "$ * #", \
							 "* $ #" \
							 " *#  " \
							 "#   #"}

# include <iostream>
# include <string>
# include <unistd.h>
# include <ncurses.h>
# include <sys/ioctl.h>
# include "Ship.class.hpp"
# include "GameStatus.class.hpp"
# include "PlayerShip.class.hpp"
# include "EnemyShip.class.hpp"
# include "Obstacle.class.hpp"
# include "Projectile.class.hpp"

std::string		sgetl(std::string s);
int		get_key( GameStatus& );
int		display( GameStatus& );
//int		menu(GameStatus& gs);
//int		get_choice(GameStatus& gs, int li, int co, ...);
void	resize( GameStatus& );
void			debug(std::string d);

/* Sound functions: */
void		loadSounds(void);
void		playSound(int index);
void		playBackground(void);

#endif
