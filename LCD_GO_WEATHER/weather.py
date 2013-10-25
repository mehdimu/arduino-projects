import pywapi
from time import sleep



#ser = serial.Serial('/dev/ttyS4', 9600)
old_temp = 0
old_feel = 0

while (1):
	weather = pywapi.get_weather_from_weather_com('CAXX0289', units="metric")

	temp = weather['current_conditions']['temperature']
	feel = weather['current_conditions']['feels_like']

	if (old_temp != temp):
		old_temp = temp
		old_feel = feel

	print temp, feel
	sleep(5)
