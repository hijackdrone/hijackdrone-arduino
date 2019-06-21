from serial import Serial
import time

s = Serial(port='/dev/tty.usbmodem14101', baudrate=9600)

time.sleep(3)
s.write(str.encode('f\n'))
print(str.encode('f\n'))
a=s.read()
print(a)
# time.sleep(3)
# s.write(str.encode('l\n'))
# print(str.encode('l\n'))

# time.sleep(3)
# s.write(str.encode('r\n'))
# print(str.encode('r\n'))

# time.sleep(3)
# s.write(str.encode('b\n'))
# print(str.encode('b\n'))

# time.sleep(3)
# s.write(str.encode('p\n'))
# print(str.encode('p\n'))

# a = s.read()
# b = s.readline()