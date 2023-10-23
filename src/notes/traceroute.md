# traceroute

A command line utility on Unix and NT (known as `tracert`) to know the hops and the IPs of the routers between the source and the destination.

Utilizes multiple [icmp](icmp.md) packets being sent towards the source with varied TTL numbers.

- First it will be set to 1, then each subsequent packet will have it incremented by 1.
- each time the router will send a reply with the **Time Exceeded in transit** command (Type = 11, Code = 0).

