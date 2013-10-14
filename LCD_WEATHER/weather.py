import pywapi
import serial
from time import sleep

ser = serial.Serial('/dev/ttyS4', 9600)
old_temp = 0

while (1):
	weather = pywapi.get_weather_from_yahoo("CAXX0289" , units = 'metric' )
	temp = weather['condition']['temp']
	print temp
	if (old_temp != temp):
		old_temp = temp
		print ser.write(temp)
	sleep(60)
