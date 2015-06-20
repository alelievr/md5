/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadSounds.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:37:20 by alelievr          #+#    #+#             */
/*   Updated: 2015/06/20 23:20:45 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmod.hpp"
#include "ft_retro.h"

FMOD::Sound *	getSoundData(FMOD::Sound *sound, int i)
{
	static FMOD::Sound *	s[0xF0] = {NULL};

	if (i > 0xF0)
		return (NULL);
	if (sound)
		s[i] = sound;
	return (s[i]);
}

void			fmod_exit(void)
{
	std::cout << "Failed to play mp3" << std::endl;
	exit(0);
}

void			loadSounds(void)
{
	FMOD::System *	Syst;
	FMOD::Sound *	sound;

	if (FMOD::System_Create(&Syst) != FMOD_OK)
		fmod_exit();
	if (Syst->init(32, FMOD_INIT_NORMAL, 0) != FMOD_OK)
		fmod_exit();
	if (Syst->createSound("mp3/laser.mp3", FMOD_CREATESAMPLE, 0, &sound) != FMOD_OK)
		fmod_exit();
	getSoundData(sound, SOUND_LASER);
	if (Syst->createSound("mp3/explosion.mp3", FMOD_CREATESAMPLE, 0, &sound) != FMOD_OK)
		fmod_exit();
	getSoundData(sound, SOUND_EXPLOSION);
}

void			playSound(int index)
{
	static FMOD::System *	Syst = NULL;
	static FMOD::Channel *	Chan = NULL;
	FMOD::Sound *			s;

	if (Syst == NULL)
	{
		if (FMOD::System_Create(&Syst) != FMOD_OK)
			fmod_exit();
		if (Syst->init(32, FMOD_INIT_NORMAL, 0) != FMOD_OK)
			fmod_exit();
	}
	if (!(s = getSoundData(NULL, index)))
		return ;
	if (Syst->playSound(s, NULL, false, &Chan) != FMOD_OK)
		fmod_exit();
}

void			playBackground(void)
{
	FMOD::System *		Syst = NULL;
	FMOD::Channel *		Chan = NULL;
	FMOD::Sound *		s;

	if (Syst == NULL)
	{
		if (FMOD::System_Create(&Syst) != FMOD_OK)
			fmod_exit();
		if (Syst->init(32, FMOD_INIT_NORMAL, 0) != FMOD_OK)
			fmod_exit();
	}
	if (Syst->createSound("mp3/background.mp3", FMOD_LOOP_NORMAL, 0, &s) != FMOD_OK)
		fmod_exit();
	if (Syst->playSound(s, NULL, false, &Chan) != FMOD_OK)
		fmod_exit();
}
/*

#include <unistd.h>
int		main(void)
{
	loadSounds();
	playBackground();
	sleep(1);
	playSound(SOUND_LASER);
	usleep(1100000);
	playSound(SOUND_EXPLOSION);
	sleep(3);
	while (42)
		;
}*/
