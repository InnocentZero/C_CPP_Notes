# natas_levels

## Level 0

Password is in the comments.

## Level 1

Open inspect element through keyboard shortcut and remove the oncontextmenu line from the body tag.

## Level 2

When you view the source it shows a `files/pixel.png` element present on the page. That implies that there is a `file` folder in the server directory. Open the folder and see the file contents.

## Level 3

Open `robots.txt` and see the disallowed folder. This is checked by web crawlers to see what folders to _not_ index.

## Level 4

Change referer by setting up a proxy to localhost and then using mitmproxy.

## Level 5

Change cookie by setting up localhost proxy and using mitmproxy.

## Level 6

The PHP sauce has the file that has the secret word necessary for revealing the password.

## Level 7

Check the HTML. It has a comment stating the page that has the password. Use that as a query in the URL to view the page.

## Level 8

Check the PHP source they are providing. Obtain the string from the hexadecimal, reverse it, and do a `base64` decode on it.

## Level 9

Comment out the query and grep the file that has the password since the input goes unsantized to passthru.

## Level 10

Do the same as before. Asterisk, period and forward slashes are not there in the filtered characters.

## Level 11

`base64` decode the data cookie. XOR it with the given cookie to obtain the XOR key. Once the key is obtained use it to change the cookie value to yes and encrypt it. Then send that as the cookie.

## Level 12

Create a `.php` file to cat the password. Change the html to send a php through the form instead of a jpg. Send it and open it in the browser.

## Level 13

Add the JPEG magic bytes to the raw hexdump of the file. Then upload it.

## Level 14

Comment out the sql query ahead of the username.

## Level 15

```py
{{#include ./hacking/natas15.py}}
```

A `post` method can also be used for this.

natas 8: a6bZCNYwdKqN5cGP11ZdtPg0iImQQhAB
natas 11: 1KFqoJXi6hRaPluAmk8ESDW4fSysRoIg
natas 12: YWqo0pjpcXzSIl5NMAVxg12QxeC1w9QG

natas 14: qPazSJBmrmU7UQJv17MHk1PGC4DxZMEP

natas 16: TRD7iZrd5gATjj9PkPEuaOlfEjHqj32V
