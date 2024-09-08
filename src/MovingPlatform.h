#ifndef MOVING_PLATFORM
#define MOVING_PLATFORM
	#include <Arduino.h>
//=============================================================================
// Драйверы 

	/* 
	* Для драйвера L298N,
	* добавте #define DRIVER_TYPE L298N перед подключением библиотеки
	*/
	#define L298N 0x01 

	/*
	* Для драйвера Ники Робот,
	* добавте #define DRIVER_TYPE NIKI перед подключением библиотеки
	*/
	#define NIKI 0x02 

	/* 
	* Для модуля LiveTronick NauRa,
	* добавьте #define DRIVER_TYPE NauRa перед подключением библиотеки
	*/
	#define NauRa 0x03

//=============================================================================
// Сборка библиотеки

	// Проверим выбор драйвера
	#ifndef DRIVER_TYPE
		#error Driver is not configured. Add #define DRIVER_TYPE in your code 
	#endif

	// Собираем
	#include <Interfaces.h>

	#if DRIVER_TYPE == L298N
		#include <drivers/DriverL298n.h>
	#endif

	#if DRIVER_TYPE == NIKI
		#include <drivers/NikiRobot.h>
	#endif

	#if DRIVER_TYPE == NauRa
		#include <drivers/DriverNauRA.h>
	#endif

	#include <Platform.h>

#endif