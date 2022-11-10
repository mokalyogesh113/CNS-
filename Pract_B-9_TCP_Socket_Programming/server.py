

#  Main
import socket

s = socket.socket()

s.bind(('localhost' , 9998))
print("Socket Created Waiting For Connection...")

s.listen(2)


while True:
    c , addr = s.accept()

    print("Client Connected to ",addr)

    choice = int(c.recv(1024).decode())
    
    if choice==1:
        msg = c.recv(1024).decode()
        print("Message from the client:- " , msg)

    if choice==2:
        ch1 = int(c.recv(1024).decode())
        n1 = int(c.recv(1024).decode())
        n2 = int(c.recv(1024).decode())

        ans = 0

        if(choice == 1):
            ans = n1+n2
        elif choice==2:
            ans = n1-n2
        elif choice==3:
            ans = n1*n2
        elif choice==4:
            ans = n1/n2
        elif choice==5:
            break

        c.send(bytes(str(ans),"utf-8"))


    c.close()
