# minitalk
Communication between two processes with signals. Data is converted to binary and sent over. Server will then convert data back to more human friendly format and print it out.

### Usage:
```
git clone https://github.com/joonasmykkanen/minitalk
```
```
make
```
Run server, will print it's pid
```
./server
```
Run client and provide servers pid and the message
```
./client [SERVER_PID] [MESSAGE]
```
