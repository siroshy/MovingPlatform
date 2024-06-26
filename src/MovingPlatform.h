#ifndef MOVING_PLATFORM
#define MOVING_PLATFORM

	#include <Interfaces.h> //Родительские классы
	
	//Драйверы 
	//Для драйвера L256N, добавте define L256N перед подключением библиотеки
	#ifdef L298N
		#include <DriverL298n.h>
	#endif
	//Для драйвера Ники Робот, добавте define NIKI перед подключением библиотеки
	#ifdef NIKI
		#include <NikiRobot.h>
	#endif

	#ifdef NauRA
		#include <DriverNauRA.h>
	#endif

	//Платформы
	#include <Platform.h>

#endif