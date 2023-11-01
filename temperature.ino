float hysteresis = 0.3;

void getTemperature() {		// OK 
  if (sensorsTemperature.checkSensorReady()) {
	  
	for(int sensor = 0; sensor < sensorTemperatureCount; sensor++){
		currentTemperature[sensor] = sensorsTemperature.getTemperature(addresSensorTemperature[sensor]);
	}  
    
	showTemperature();
	CorrectionTemperature();
  }
}

void showTemperature() {	// OK 
	lcd.setCursor(5, 0);
		lcd.print(currentTemperature[0], 1);
	lcd.setCursor(5, 1);
		lcd.print(currentTemperature[1], 1);
}

void CorrectionTemperature() {	// OK
	lcd.setCursor(12, 0);
	if (currentTemperature[aquaTemperature] > (setTemperature + hysteresis)){	// 25.0+0.5=25.5
		digitalWrite(pinHeat, LOW);
		lcd.print(" ");
    }
    if (currentTemperature[aquaTemperature] < (setTemperature - hysteresis)){	// 25.0-0.5=24.5
		digitalWrite(pinHeat, HIGH);
		lcd.print(char(42));
    }
}
