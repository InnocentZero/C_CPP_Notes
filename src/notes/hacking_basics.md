# hacking_basics

## Python Snippets

- hex to bytes to string

```python
hex_value = "4765656b73666f724765656b73"
byte_str = bytes.fromhex(hex_value)
result_str = byte_str.decode('utf-8')
```

- string to bytes

```python
byte_arr = str.encode("Foo")
```

- hex string to int

```python
x = int("deadbeef", 16)
x = int("0xdeadbeef", 0)
x = int("0xdeadbeef", 16)
```

- integer to binary/octal/hexadecimal

```python
bin(23)  
oct(31)
hex(26)
```

- basic pwntools template

```py
{{ #include ./hacking/sol.py }}
```

- connect to a netcat port

```python
io = remote("new.domain.name", 80)
io = remote("12.12.12.12", 5000)
```

- receive xyz after connecting

```python
io.recv(n) # nbytes
io.recvline() # till newline
io.recvuntil("string") #receive until the occurance of string
```

- send xyz after connecting

```python
io.send(b'bytes')
io.sendline(b'bytes') # also sends a newline
```

- convert an integer to 32/64 byte address little-endian

```python
pwn.p32(some_integer)
pwn.p64(some_integer)
```

- same as above, but big-endian, and signed

```python
pwn.p64(some_int, endian="big", sign=True)
```
