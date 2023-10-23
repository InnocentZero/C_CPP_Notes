# network_stack

- Just a list of protocols that you need to satisfy in order to be able to use connections.

## IP

- Has a header that contains source IP, destination IP, and other metadata that tells the next protocol as to where to send the data to.
- The payload contains the actual meaningful message for the next protocol.
- Has two categories- IPv4 and IPv6.
- [ipv4](ipv4.md) is a legacy mapping system. Has 32 bit addresses. Got exhausted lol.
- [ipv6](ipv6.md) is the new network system. Hasn't been completely destroyed.

## BGP

- BGP stands for Border Gateway Protocol. It is a routing protocol used by Internet Service Providers (ISPs) to exchange information about the paths that data packets should take to reach their destination on the internet.
- Has underlying TLS for communication.
- Used to communicate between two autonomous systems.
- Keeps sending 19 byte keep-alive messages to peers every 30 seconds (changeable) from port 179.
- The peers are pre-configured in the router.

## UDP (Unsolicited Dick Pics)

- Used for real time communication like VoIP and online gaming.
- Header contains Source port number (16 bits), destination port number (16 bits), length (16 bits) and the checksum (16 bits).
- The IPv4 pseudo header contains source address (32 bits), destination address (32 bits), zero padding (8 bits), protocol number (17 for UDP), UDP Length of the underlying message, and to this the UDP header is appended.
- The IPv6 pseudo header contains source address (128 bits), destination address (128 bits), UDP length (32 bits), zero padding (24 bits), protocol number (8 bits, 17 for UDP), followed by the appended UDP header.


