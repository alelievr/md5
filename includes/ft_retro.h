#ifndef FT_RETRO_H
# define FT_RETRO_H

# define BIT_ON(x, y) (x = x | (1 << y))
# define BIT_OFF(x, y) (x &= ~(1 << y))
# define BIT_TEST(x, y) (((x & (1 << y)) == 0) ? 0 : 1)

# define SOUND_LASER 0
# define SOUND_EXPLOSION 1

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
"                           |-----------|\n" \
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
"                           |-----------|\n" \
"                           |___________|\n" \
# define MASK_EXPLOSION		{"# *  " \
							 " $** " \
							 "$ * #", \
							 "* $ #" \
							 " *#  " \
							 "#   #"}

# include <iostream>
# include <string>
# include "Ship.class.hpp"
# include "PlayerShip.class.hpp"
# include "EnemyShip.class.hpp"
# include "Obstacle.class.hpp"
# include "Projectile.class.hpp"
# include "GameStatus.class.hpp"

std::string		sgetl(std::string s);

/* Sound functions: */
void		loadSounds(void);
void		playSound(int index);
void		playBackground(void);

#endif
