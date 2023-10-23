# dhcp

- Used for automatically assigning IP addresses to devices.
- Uses a client server architecture.

## Dynamic Allocation

- Router gets a range from network admin. Each client requests an address during network initialization. 
- Uses a lease concept with a controllable time period, so router can reclaim and reallocate the IP address to some other device.

## Automatic Allocation

- Like dynamic, but once an IP is allotted to a MAC address it is saved for the device. 
- It is preferential and not strict (ofc).

## Static/Manual Allocation

- MAC address to IP mapping. May fall back to other methods if this fails.

## Modus Operandi

- Uses UDP under the hood.
- Server listens on port 67, client listens on port 68.

### Server discovery

- Client broadcasts a **DHCPDISCOVER** message on the network subnet using destination address 255.255.255.255 or using the specific subnet broadcast address.
- Client may also request for the previously offered.

### Offer from the server

- IP address is reserved for the client.
- A **DHCPOFFER** is sent to the client.
- Information includes *offered* client IP, client address (the MAC Address), the subnet mask, lease period, and the Server IP.

### Request from the Client

- A **DHCPREQUEST** message is sent to the server requesting the offered address.
- Only one offer is requested if multiple servers offer it IPs.
- Before claiming, an Address Resolution Protocol request is broadcast on the subnet. No response means there are no conflicting IPs.

### Acknowledgement

- **DHCPACK** sent by the server. 
- Includes lease duration and other requested information.
- ARP is conducted (again). If conflicting, **DHCPDECLINE** is sent.

### Releasing

- Request to release the DHCP information and the client deactivates its IP address.
- Not mandatory as it's not known when the user would disconnect all of a sudden.

## IPv6

IPv6 protocol differs significantly for it to be its own protocol. Read [dhcpv6](dhcpv6.md)

<!---->

