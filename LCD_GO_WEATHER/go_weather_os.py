#import serial
import time
import urllib2
from pywapi import get_weather_from_weather_com

#CONSTANTS
TRANSIT_PSEUDO = "<travel_mode>TRANSIT</travel_mode>"
DEPARTURE_PSEUDO = "<departure_time>"
#milton departure and union departure respectively
REQUEST_PSEUDO_1 = "http://maps.googleapis.com/maps/api/directions/xml?\
						 origin=L9T0J4&destination=M5J1E6&sensor=false&\
						 departure_time={}&mode=transit"
REQUEST_PSEUDO_2 = "http://maps.googleapis.com/maps/api/directions/xml?\
						 origin=M5J1E6&destination=L9T1N8&sensor=false&\
						 departure_time={}&mode=transit"
REFRESH_INTERVAL = 60
SERIAL_NAME = '/dev/ttyS4'
SERIAL_PORT = 9600
LOCATION_CODE = 'CAXX0289'

#helper functions
def getTime(request):

	currentTime = time.time()

	response = urllib2.urlopen(request.format(int(time.time())))

	html = response.read()
	html = html.split()

	try:
		travelModeIndex = html.index(TRANSIT_PSEUDO)
		departureTimeIndex = html[travelModeIndex:].index(DEPARTURE_PSEUDO)
	except ValueError:
		#request failed
		return None

	try:
		departureTime = html[travelModeIndex + departureTimeIndex + 2]
	except IndexError:
		return None

	return departureTime

def formatTime(TIME):
	#sample
	# <text>8:40am</text>

	if not TIME:
		return None

	try:
		beginBracket = TIME.index(">")
		endBracket = TIME[beginBracket: ].index("<")
	except ValueError:
		#index not found
		return None

	try:
		amPMtime = TIME[beginBracket + 1: endBracket + beginBracket]
	except IndexError:
		return None

	return amPMtime[: -2]


if __name__ == '__main__':
	#initialize the serial connection
	#ser = serial.Serial(SERIAL_NAME, SERIAL_PORT )

	#declare any variables
	oldTemp = oldFeel = lastMiltonTime = lastUnionTime = 0;

	while (True):

		#get go schedule
		departureTime = getTime(REQUEST_PSEUDO_1)
		miltonTime = formatTime(departureTime)

		departureTime = getTime(REQUEST_PSEUDO_2)
		unionTime = formatTime(departureTime)

		if miltonTime:
			print miltonTime

		if unionTime:
			print unionTime

		#get weather updates
		weather = get_weather_from_weather_com(LOCATION_CODE, units="metric")

		temp = weather['current_conditions']['temperature']
		feel = weather['current_conditions']['feels_like']

		print temp, feel

		#send updated data
		if (oldTemp != temp or oldFeel != feel):
			oldTemp = temp
			oldFeel = feel
			#tell the lcd that its temperature
			#dataSent = ser.write(temp)
			#print dataSent
			pass

		if (lastMiltonTime != miltonTime or lastUnionTime != unionTime):
			lastMiltonTime = miltonTime
			lastUnionTime = unionTime
			#tell the lcd that its schedules
			#dataSent = ser.write(temp)
			#print dataSent
			pass

		#refresh interval
		time.sleep(REFRESH_INTERVAL)