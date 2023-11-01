const char textWelcome[ ] PROGMEM = "AquaLite";
const char textVersionProgram[ ] PROGMEM = "Ver 1.00";

const PROGMEM char textAqua[ ] 	= "Aqua-";
const PROGMEM char textRoom[ ]	= "Room-";
const PROGMEM char textH[ ]  	= "H";
const PROGMEM char textA[ ]		= "A";

const int delayAfterWelcome  = 3000;

void welcomeMenu(){							// OK
	lcd.clear();
	printText(4, 0, textWelcome);
	printText(4, 1, textVersionProgram);
	delay(delayAfterWelcome);
	showMenu();
}

void  showMenu(){
	lcd.clear();
	printText(0, 0, textAqua);
	printText(0, 1, textRoom);
	
	lcd.setCursor(9, 0);
		lcd.print(char(223));
	lcd.setCursor(9, 1);
		lcd.print(char(223));
		
	printText(11, 0, textH);
	// printText(14, 0, textA);
}

void showClock(){ 			// OK
	lcd.setCursor(11, 1);
		printDigits(now.hour());
	if (now.second()%10%2 == 0){
		lcd.print(char(58));
	} else {
		lcd.print(" ");
	}	
	printDigits(now.minute());
}

void printDigits(byte digits){ 			// OK
	if(digits < 10){
		lcd.print('0');
	}
	lcd.print(digits);
}

void printText(byte Xpos, byte Ypos, const char *text){ 	// OK
	lcd.setCursor(Xpos, Ypos);
	char myChar;
	byte len = strlen_P(text);
	for (byte i = 0; i < len; i++){
		myChar =  pgm_read_byte_near(text + i);
		lcd.print(myChar);
	}
}