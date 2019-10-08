import socket

# s = socket.socket(addr_family, type)
# Addr Families:
#   socket.AF_INET - IPv4
#   socket.AF_INET6 - IPv6
# Socket Types:
#   socket.SOCK_STREAM - TCP
#   socket.SOCK_DGRAM - UDP

# Use on client and server
# mysock.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR, 1)

# UDP SERVER
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("127.0.0.1", 8081))
s.listen(2)
conn, addr = s.accept()
data = conn.recv(1024).decode('ascii')
print(data)
conn.send("Message Received".encode())
