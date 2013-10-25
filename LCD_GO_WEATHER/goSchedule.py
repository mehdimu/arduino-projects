import urllib2
import time

#request = "http://maps.googleapis.com/maps/api/directions/xml?origin=l9t5n9%20Station&departure_time={}&destination=M5J1E6&sensor=false&departure_time=1343605500&mode=transit"


currentTime = time.time()

response = urllib2.urlopen("http://maps.googleapis.com/maps/api/directions/xml?origin=L9T0J4&destination=M5J1E6&sensor=false&departure_time={}&mode=transit".format(int(time.time())))


html = response.read()
html = html.split()

#print html

travelModeIndex = html.index("<travel_mode>TRANSIT</travel_mode>")
departureTimeIndex = html[travelModeIndex:].index("<departure_time>")
departureTime = html[travelModeIndex + departureTimeIndex + 2]

print departureTime