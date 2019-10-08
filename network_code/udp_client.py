from socket import *

s = socket(AF_INET, SOCK_STREAM)

s.connect(('127.0.0.1', 8081))
s.send("hello there".encode())
s.send("hiiiiiii".encode())
s.send(("#"*1020).encode())
data = s.recv(1024).decode('ascii')
print(data)