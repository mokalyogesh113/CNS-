import socket
import time

UDP_IP = "127.0.0.1"
UDP_PORT = 5005

file_name = input("Enter The file name :- ")
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.sendto(file_name, (UDP_IP, UDP_PORT))

print ("Sending ",file_name," ...")
f = open(file_name, "r")
data= f.read(1024)
while(data):
    if sock.sendto(data.encode(),(UDP_IP, UDP_PORT)):
        data = f.read(1024)
        time.sleep(0.02) # Give receiver a bit time to save
sock.close()
f.close()