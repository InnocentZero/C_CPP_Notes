# dhcpv6

- Fundamentally different from DHCP.
- Still uses UDP.
- Client listens on UDP port 546, servers and relay channels listen on port 547.

## Identifiers

- DUID: Used by the client to get the IP address of the server.

## Example of operation

In this example, without rapid-commit present, the server's link-local address is `fe80::0011:22ff:fe33:5566` and the client's link-local address is `fe80::aabb:ccff:fedd:eeff`.

- Client sends a solicit from `[fe80::aabb:ccff:fedd:eeff]:546` to multicast address `[ff02::1:2]:547`.
- Server replies with an advertise from `[fe80::0011:22ff:fe33:5566]:547` to `[fe80::aabb:ccff:fedd:eeff]:546`.
- Client replies with a request from `[fe80::aabb:ccff:fedd:eeff]:546` to `[ff02::1:2]:547`.
- Server finishes with a reply from `[fe80::0011:22ff:fe33:5566]:547` to `[fe80::aabb:ccff:fedd:eeff]:546`.
