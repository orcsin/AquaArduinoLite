void InitialVariable() {	// OK
	// for (byte sensor = 0; sensor < 4; sensor++) {
		// statusRelay[sensor] = EEPROM.read(0 + sensor);			// 1-4;
	// }
	
	setTemperature = EEPROM.read(4);
	
	InitLight();
}

void RecordEEPROM(){	// OK
  // EEPROM.write(0, 1);   // statusRelay[Food];
  // EEPROM.write(1, 1);   // statusRelay[Led];
  // EEPROM.write(2, 1);   // statusRelay[Air];
  // EEPROM.write(3, 1);   // statusRelay[Heat];
    
  EEPROM.write(4, 25);  // setTemperature (Water);

/****************************** Led Interval I *******************************/
  EEPROM.write(5, 50);  // MaxPwmValueLed;
    
  EEPROM.write(6, 15);  // turnOnDurationLed;
  EEPROM.write(7, 15);  // turnOffDurationLed;
  
  EEPROM.write(8, 6); 	// turnOnHoursLed[FIRST_INT];
  EEPROM.write(9, 0);   // turnOnMinutesLed[FIRST_INT];
  EEPROM.write(10, 7);  // turnOffHoursLed[FIRST_INT];
  EEPROM.write(11, 0);  // turnOffMinutesLed[FIRST_INT];
  
/****************************** Led Interval II *******************************/
  EEPROM.write(12, 100); // MaxPwmValueLed;
    
  EEPROM.write(13, 120); 	// turnOnDurationLed;
  EEPROM.write(14, 120); 	// turnOffDurationLed;
    
  EEPROM.write(15, 8); // turnOnHoursLed[SECOND_INT];
  EEPROM.write(16, 00); // turnOnMinutesLed[SECOND_INT];
  EEPROM.write(17, 19); // turnOffHoursLed[SECOND_INT];
  EEPROM.write(18, 00); // turnOffMinutesLed[SECOND_INT];
  
  InitialVariable();
}

