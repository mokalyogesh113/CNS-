import socket

c = socket.socket()

c.connect(('localhost',9998))

print("1. Send Hello ")
print("2. Calculator")
ch = input("Enter input  ")

c.send(ch.encode())

if ch=="1":
    c.send(bytes(input("Enter the message to send--> ") , 'utf-8'))
elif ch=='2':
    while(True):
        print("\n*******Menu*******")
        print("1.Addition")
        print("2.Subtraction")
        print("3.Multiplication")
        print("4.Division")
        print("5.Exit")
        choice = int(input("Enter Choice:- "))
        if(choice>0 and choice<=4):
            n1 = int(input("Enter First Number:- "))
            n2 = int(input("Enter Second Number:- "))

            c.send(str(choice).encode())
            c.send(str(n1).encode())
            c.send(str(n2).encode())

            ans = c.recv(1024).decode()

            print("\nAnswer is :- ",ans)
        elif choice==5:
            c.send(str(choice).encode())
            break
        else:
            print("\nWrong Choice")