import serial


ser = serial.Serial('/dev/ttyACM0', 9600)  # Check serial port

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
                with open('test.html', 'r') as file:
                    filedata = file.read()
                filedata = filedata.replace('red', 'green')
                with open('test.html', 'w') as file:
                    file.write(filedata)
                print "Connection has been made"
