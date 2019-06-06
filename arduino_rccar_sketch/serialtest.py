from serial import Serial
s = Serial(port='/dev/tty.usbmodem14301', baudrate=9600)

s.write(str.encode('f'))
print(str.encode('f'))
print('f')
a = s.read()
b = s.readline()