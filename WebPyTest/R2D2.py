import serial
import time
from flask import Flask
from flask import render_template, request


app = Flask(__name__)
ser = serial.Serial('/dev/ttyACM0', 9600)  # Check serial port

chk = "Connection Good"
webGood = "green"
webBad = "red"
fwd = "Forward"
rev = "Backward"
lft = "Left"
rite = "Right"
# backleft = "RevLeft"
# backright = "RevRight"
stp = "Stop"
i = 1

#
# Add image rec function
#

#
# Add training AI function --Train based on last action, so: dist_last -> command -> dist_now
#

#
# Add AI command function
#


# Needs to be fixed. Should return true or false value that the HTML uses to change values
def startup():
    if ser.inWaiting > 0:
        line = ser.readline()
        print line
        if line is 'Connection Check':
            ser.write('Connection Good'.encode('utf-8'))
            line = ser.readline()
            print line
            if 'Connection Good. Coming online' in line:
                ser.write(chk.encode())
                with open('templates/index.html', 'r') as file:
                    filedata = file.read()
                filedata = filedata.replace('<span style="color:red', '<span style="color:green')
                with open('test.html', 'w') as file:
                    file.write(filedata)
                print "Connection has been made"


@app.route("/")
def index():
    return render_template('index.html')


@app.route("/forward")
def forward():
	ser.write(fwd.encode())
	print("moving forward")
	return 'true'


@app.route("/backward")
def backward():
	ser.write(rev.encode())
	print("moving backward")
	return 'true'


@app.route("/left")
def left():
	ser.write(lft.encode())
	print("moving left")
	return 'true'


@app.route("/right")
def right():
	ser.write(rite.encode())
	print("moving right")
	return 'true'
	time.sleep(1)


@app.route("/stop")
def stop():
	time.sleep(5)
	ser.write(stp.encode())
	print("stoping")
	return 'true'


#  Add command in HTML_use: onclick { while(text=manual)...else make control bad visible }
@app.route("/auto")
def auto():
	print("Auto")
	return 'true'

if __name__ == "__main__":
	print "Start"
	app.run(host='0.0.0.0',port=5010)


# Create close function to change status back to red
