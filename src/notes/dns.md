# dns

DNS is the domain name system. It is a methodical
address-book kinda thing that returns the location of the nearest
server for that domain name.

It differs from a contact book in the sense that it can return the nearest
server instead of having a fixed server. In that sense,
it is like a `multimap` instead of a `map` if we talk about it in STL terms.

## Domain Name Space and Mode of Operation

The tree is separated into zones beginning with the root zone.
The first query is sent to the root zone that responds with
another zone that it thinks _may_ have the **record** for the domain name.

This can continue recursively unless the request
receives an **authoritative** answer (AA bit in the responses set to 1).

The zones can be divided by creating many additional
zones and authority is _delegated_ over to the child zones.
The parent ceases to be authoritative for the new zone.

This setup is obviously better than a single server
holding all the records for multiple reasons:

- Enables lower load on the servers
- Enables faster lookup times.
- Ease of adding new zones and new records without disturbing existing ones.

### DNS Resolvers

Client side of the DNS is called a resolver.
It initiates and queries requests and can use a variety of methods
like _recursive_, _non-recursive_ and _iterative_.
There are also caching DNS resolvers that do what you think they do;
they cache values locally and reduce lookup times and upstream loads.

A non-recursive resolver simply means that it will either get the
query response from an authoritative server or gives a partial result.

A recursive is the regular one, where a server
may generate more requests on behalf of the resolver.
An iterative server is one where the query responses lead it
to the next server in chain till it reaches an authoritative one.

An example of this is [systemd-resolved](https://wiki.archlinux.org/title/Systemd-resolved).
Typically applications on linux check `/etc/resolv.conf` for checking domain
name servers for the network. `resolved.service` symlinks it to one of the two files,
`/run/systemd/resolve/stub-resolv.conf` or `/run/systemd/resolve/resolv.conf`.

`stub-resolv` points to the local DNS _server_ created by systemd.
It operates on 127.0.0.53.
Also, to set global DNS, you need to edit `/etc/systemd/resolved.conf`.

## Domain Name syntax and internationalization

- Divided into _labels_ that are concatenated by dots.
- The full domain name can have a total of 253 characters.
- Each label represents a subdomain. The hierarchy descends from right to left.
- It can have a maximum of 127 levels of divisions in the subdomains.
- Each subdivision can have a total of 63 characters.
- Can only contain letters, digits, and hyphens. This is called as the **LDH** rule.
- They are interpreted in a case independent manner. Can't start or end with hyphens either.
- To map non-ascii characters to domain names [punycode](https://wikiless.org/wiki/Punycode?lang=en) is used.

## Transport Protocols

- UDP on port 53
- TCP on port 53
- TLS over port 853
  - More secure than DNS over HTTPS, as it encrypts not just browser traffic but all traffic.
- HTTPS over port 443
  - It appears to be regular HTTPS traffic but is actually easily filterable using _cough cough_ machine learning models.

### DNSSEC

DNS security extension. It signs the DNS data of every zone use public key cryptography. The zone owner has the private key that is kept to himself. The public key is distributed along with the records.

If the signatures match, it means that the data obtained is authentic. The public key authenticity is maintained by signing it with the parent zone's private key.
