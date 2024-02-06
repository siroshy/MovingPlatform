# MovingPlatform

Библиотека предназначена для управления колесной платформой,
которая приводится в движение  электромоторами через различные драйверы.
Главной идеей библиотеки является програмная заменяемость реализаций
работы с драйверами моторов, при неизменной реализации управления 
движением платформы.
Реализовано это наследованием классов драйверов от одного родительского
класса InterDriver.

Список реализованных драйверов:

Драйвер на микросхеме L298N:
Перед подключением библиотеки нужно вписать:

	#define L298N
Конструктор этого драйвера имеет вид:

	DriverL298n(int IN1pin, int IN2pin, int ENpin)

Драйвер в робототехническом конструкторе НикиРобот
Перед подключением библиотеки нужно вписать:

	#define NIKI
Конструктор этого драйвера имеет вид:

	Niki(int IN1pin, int ENpin);

Для драйверов объявлены несколько стандартных функций, которые наследуются.
Например:
Функция установки направления движения с 4 вариантами

	void setDirection(int dir);  
	/*
	0 - Отпущено,
	1 - Вперед,
	2 - Назад,
	3 - Активный тормоз
	*/

Если необходимо инвертировать вращение мотора,
нужно передать этой функции TRUE

	void invDir(bool inv); // true - обратное направление, false - прямое направление
Для корректировки скорости вращения мотора, можно передать этой функции значение
смещения. Положительное значение приведет к ускорению мотора, 
отрицательное - к замедлению.

	void speedOffset(int offset);

Для управления платформой, классы платформ наследуются от базового класса InterPlatform.
Доступные методы и настройки для платформы:

	void setSpeed(int speed); //Устанавливает скорость всех типов движения

Основные функции движения:
		  
	void stop(); //Остановка
	void moveFwrd(); //Движение вперед
	void movebwrd(); //Движение назад
	void turnLft(); //Поворот налево движением вперед
	void turnRht(); //Поворот направо движением вперед
	void turnBackLft(); //Поворот налево движением назад
	void turnBackRht(); //Поворот направо движением назад
	void circleLft(); //Вращение против часовой стрелки
	void circleRht(); //Вражение по часовой стрелки
	void diffSpeed(int L, int R); 
	//Вращение каждым мотором со своей заданной
	//скоростью в диапазоне -255 ... 255 (+/- отражает направление)
	//Если скорость положительна,
	//вращение будет вперёд, отрицательно - 
	//назад. При этом мощность будет взята по модулю.

 
