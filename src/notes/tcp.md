# tcp

Transmission Control Protocol. Originated along with [ipv4](ipv4.md) and hence the entire system is called TC/IP. It's IP Protocol Number is 6.

- IP packets may be lost, duplicated or out of order due to network congestion. TCP's job is to rectify these errors.

- Since it focuses on reliable connection rather than fast connection it may take a lot of time to deliver the addresses.

- The sender keeps a timer and the receiver returns an acknowledgement on receiving the packet. If the timer expires before the acknowledgement is received, the packet is dropped immediately.

- Contains checksum verifications and sequence numbers to maintain data integrity.

- Can also selectively receive packets in broken sequences, say 1000-2000 and then 3000-3089. In this case, a flag called **SACK** (Selective Acknowledgement) can be set to 1, that allows the receiver to receive discontinuous blocks like these.

- Usually TCP waits for the full packet to be created before it it sent. However, **PSH** flag can be used for sending data immediately without waiting for the buffer to get full.

## Vulns

- TCP Veto: Add a malicious packet in between with a sequence number same as the one going to arrive next. The next one is silently dropped a duplicate one. This isn't highly controllable but very resistant to detection.

- Sequence prediction attacks: Create an entire sequence of packets and hijack the network to pretend you are the host.
