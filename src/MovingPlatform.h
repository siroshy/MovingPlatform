#ifndef MOVING_PLATFORM
#define MOVING_PLATFORM

	#include <Interfaces.h> //Родительские классы
	
	//Драйверы 
	#define L298N 1
	#define NIKI  2
	#define NauRa 3

	#ifndef DRIVER_TYPE
		#error Driver is not configured. Add #define DRIVER_TYPE in your code 
	#endif

	//Для драйвера L298N,  добавте #define L298N перед подключением библиотеки
	#if DRIVER_TYPE == L298N
		#include <DriverL298n.h>
	#endif

	//Для драйвера Ники Робот, добавте #define NIKI перед подключением библиотеки
	#ifdef DRIVER_TYPE == NIKI
		#include <NikiRobot.h>
	#endif

	//Для LiveTronick NauRa, добавьте #define NauRa перед подключением библиотеки
	#ifdef DRIVER_TYPE == NauRA
		#include <DriverNauRA.h>
	#endif


	//Платформы
	#include <Platform.h>

#endif