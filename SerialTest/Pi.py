import serial


ser = serial.Serial('/dev/ttyACM0', 9600)  # Check serial port-> 
# ser = serial.Serial('YOUR PORT', 9600)
# use "ls /dev/tty*" in terminal to get a list of ports

chk = "Connection Good"


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
                print "Connection has been made"
