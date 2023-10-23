# icmp

Used by network devices such as routers to send error messages back. Typically used for network diagnostic tools such as [traceroute](traceroute.md).

- If the time to live (TTL) reaches 0 at any node (each node that processes TTL decrements it by 1), then the packet is discarded and the **ICMP tile exceeded in transit** is sent back to the source.

- The header contains a 1 byte _type_, 1 byte _code_, 2 byte _checksum_, and 4 bytes for rest of the header.

## Control Codes:

- Redirect: Asks the sender to send the traffic through some other node in the network.

  - The code contains the reason for which the Redirect was done.
  - The next 4 bytes contain the IP address where it must be redirected.
  - Following data contains the IP header and the first 8 bytes of the OG datagram for verification by the source.
  - Type = 5

- Time exceeded: Quite literally. Code can specify why time limit exceeded, in transit or in fragment reassembly.

  - Type = 11

- Timestamp: Used for time sync. Type = 13, code = 0.

  - Identifier and Sequence number, 2 bytes each, are used to match the request with the reply.
  - Has 3 4 byte Timestamps, `orginate` when this was sent, and the other two are not used.

- Timestamp reply: Quite literally. Type = 14, Code = 0.

  - Identifier and sequence number as before.
  - Same Timestamp format, first one is when the timestamp was sent by the other party, second one was when it was received by us, third one was when the reply was sent.

- Destination unreachable: Can have 15 different codes. Never sent for IP Multicast.
  - Type = 3.
  - Code field can be 0 - 15.
  - Checksum ( 4 bytes)
  - next 4 bytes are unused.
  - Next 4 bytes are only relevant for a specific error when packet fragmentation is required but **DONT FRAGMENT** flag is active.
  - After that IP header and first 8 bytes of datagram data for senders verification.
