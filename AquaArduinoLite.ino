#include <OneWire.h>
#include <DS18B20Lib.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#include <EEPROM.h>
#include <LightControl.h>

#define pinTemperature	2
#define pinFood			3
#define pinHeat			7
#define pinFilter		8
#define pinLed			11

#define timeDown 0
#define timeUp   1

//**************** Declaration devices ****************//
LiquidCrystal_I2C lcd(0x27,16,2);

//*********************** Time *************************//
RTC_DS3231 rtc;
DateTime now;

//********************** Light ************************//
DateTime LightControl::timeNow;
const byte quantityInterval = 1;
LightControl ledInterval[quantityInterval] = {12};

//******************** Temperature ********************//
typedef uint8_t DeviceAddress[8];
OneWire oneWire(pinTemperature);
DS18B20Lib sensorsTemperature(&oneWire);

DeviceAddress addresSensorTemperature[] = {
	{0x28, 0xFF, 0xBE, 0xD9, 0x64, 0x15, 0x02, 0xA3 },	// external DS18B20
    {0x28, 0xFF, 0x01, 0x4C, 0x54, 0x16, 0x04, 0xB5}	// internal DS18B20
};

const byte sensorTemperatureCount=sizeof(addresSensorTemperature)/sizeof(DeviceAddress);

float currentTemperature[sensorTemperatureCount];
byte setTemperature;

#define aquaTemperature	0

void setup() {
	pinMode(pinHeat, OUTPUT);
	pinMode(pinFilter, OUTPUT);
	digitalWrite(pinFilter, HIGH);
	Serial.begin(9600);
	Wire.begin(); 		// Инициализируем часы
	rtc.begin();		// 		--//--
	// rtc.adjust(DateTime(2019, 04, 03, 21, 27, 00));
	lcd.init();			// Инициализируем дисплей
	lcd.backlight();	// Включаем подсветку экрана
	sensorsTemperature.begin();
	InitialVariable();
	// RecordEEPROM();
	Serial.println("Welcome()");
	welcomeMenu();		// Показываем меню;
}

void loop() {
	now = rtc.now(); 			// Считываем текущее время;
	showClock();
	getTemperature();
	ControlLight();
	checkTimeCorrection();
}

void checkTimeCorrection(){
	
	int _year = now.year();
	byte _month = now.month();
	byte _day = now.day();
	byte _hour = now.hour();
	byte _minute = now.minute();
	byte _second = now.second();
	
	if (_month == 3 && _day>=25 && now.dayOfTheWeek() == 0 && _hour == 3 && _minute == 0 && _second == 0){
		timeCorrection(timeUp, _year, _month, _day, _hour);
	}
	
	if (_month == 10  && _day>=25 && now.dayOfTheWeek() == 0 && _hour == 4 && _minute == 0 && _second == 0){
		timeCorrection(timeDown, _year, _month, _day, _hour);
	}
}
//********************** End ************************//

void timeCorrection(bool _correction, int _year, byte _month, byte _day, byte _hour){
	if(_correction){
		_hour++;
	} else {
		_hour--;
	}

	rtc.adjust(DateTime(_year, _month, _day, _hour, 0, 0));
}
