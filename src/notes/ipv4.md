# ipv4

- 32 bit addresses divided into 8 bit blocks.
- Has private address range and multicast address range.

## Classful networking

- 0xxxxxxx.x.x.x is one network. Called class A.
  - Has 128 possible networks. Size of network is 2<sup>24</sup>
  - Has subnet mask equal to 8.
- Similarly 10xxxxxx.x.x.x is another network. Class B.
  - Has 2<sup>14</sup> networks. Network size decreases inversely.
  - Has subnet mask equal to 16.
    -Similarly class C has subnet of 24.
- Only allowed for 254 networks.

> Fun fact: ARPAnet was 10.x.x.x

## private address range

| Block Size | Range                         | Bit mask | Classful description            |
| ---------- | ----------------------------- | -------- | ------------------------------- |
| 24-bit     | 10.0.0.0 - 10.255.255.255     | 8        | One class A network             |
| 20 bit     | 172.16.0.0 - 172.31.255.255   | 12       | 16 contiguous class B networks  |
| 12 bit     | 192.168.0.0 - 192.168.255.255 | 16       | 256 contiguous class C networks |

### Loopback interface

- Special case of private addresses.
- Packets never leave the host.
- 127.0.0.0/8 is the address space reserved for ipv4.

### IP Broadcast

- In IPv4 it has a special address. This was used by interfaces to send messages to all networks connected to a particular subnet.
- In [dhcp](dhcp.html#server-discovery), if the broadcast address of the subnet is not defined, then a **DHCPDISCOVER** message is sent to the address _255.255.255.255_.
- This again does the same job of keeping the broadcast message within the same subnet.
- The broadcast address is otherwise calculated as follows: - Take the first _subnet_ bits of the network. Let them be as they are. - Change the remaining trailing bits to 1.
<!---->

##

- [2023-09-25](2023-09-25.md)
  - Checking the script by linking [ipv4](ipv4.md).

##

- [tcp](tcp.md)
  - Transmission Control Protocol. Originated along with [ipv4](ipv4.md) and hence the entire system is called TC/IP.
