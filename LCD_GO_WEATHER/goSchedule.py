import urllib2
import time


#CONSTANTS
TRANSIT_PSEUDO = "<travel_mode>TRANSIT</travel_mode>"
DEPARTURE_PSEUDO = "<departure_time>"
#milton departure and union departure respectively
REQUEST_PSEUDO_1 = "http://maps.googleapis.com/maps/api/directions/xml?origin=L9T0J4&destination=M5J1E6&sensor=false&departure_time={}&mode=transit"
REQUEST_PSEUDO_2 = "http://maps.googleapis.com/maps/api/directions/xml?origin=M5J1E6&destination=L9T1N8&sensor=false&departure_time={}&mode=transit"
REFRESH_INTERVAL = 2


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


	while (True):

		time.sleep(REFRESH_INTERVAL)

		departureTime = getTime(REQUEST_PSEUDO_1)
		miltonTime = formatTime(departureTime)

		departureTime = getTime(REQUEST_PSEUDO_2)
		unionTime = formatTime(departureTime)

		if miltonTime:
			print miltonTime

		if unionTime:
			print unionTime


