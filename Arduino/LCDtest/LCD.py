import serial

ser1=serial.Serial("COM3",9600)

print("Enter the text you want the LCD to display...")
while 1==1:
    a=input()
    print("Displaying '",a,"'")
    ser1.write(a.encode())
    print("\n")
