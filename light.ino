void InitLight(){
		for (byte interval = 0; interval < quantityInterval; interval++) {
			ledInterval[interval].initData();
		}
}

void ControlLight(){
	float pwmNow = 0.0;
	float pwmTemp = 0.0;

	for (byte interval = 0; interval < quantityInterval; interval++) {
		// Serial.print("pwmNow - ");
			// Serial.println(ledInterval[interval].getCurrentPwmValue());
		if(ledInterval[interval].getCurrentPwmValue() > pwmNow){ 
			pwmNow = ledInterval[interval].getCurrentPwmValue();
		}
	}
	if(pwmNow != pwmTemp)
	{
		lcd.setCursor(13, 0);
		lcd.print(pwmNow);
	}
	analogWrite(pinLed, pwmNow * 2.5);
	// Serial.print("pwmNow - ");
	// Serial.println(pwmNow);
}
