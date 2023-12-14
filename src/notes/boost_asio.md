# boost asio

Networking and low level input/output programming.

An async connector example:

```cpp
using boost::asio;
// io_service provides IO functionality for asynchronous stuff
// like sockets, acceptors and stuff
io_service service;

//
ip::tcp::endpoint ep( ip::address::from_string("127.0.0.1"), 2001);
ip::tcp::socket sock(service);
sock.async_connect(ep, connect_handler);
service.run();
void connect_handler(const boost::system::error_code & ec) {
// here we know we connected successfully
// if ec indicates success
}
```

## `asio::io_context`

Boost.Asio defines `boost::asio::io_service`, a single class for an I/O service object. Every program based on Boost.Asio uses an object of type `boost::asio::io_service`. This can also be a global variable.

New versions of boost typdefs `io_context` to be `io_service`. `io_context` is the new thing it seems.

To prevent the `io_context` from running out of work, [here](https://www.boost.org/doc/libs/1_78_0/doc/html/boost_asio/reference/io_service.html#boost_asio.reference.io_service.stopping_the_io_context_from_running_out_of_work).

`io_context::run()`

The `run()` function blocks until all work has finished and there are no more handlers to be dispatched, or until the `io_context` has been stopped.

Returns the number of handlers that were executed.

If `run()` has nothing left to execute, it will return.

## `asio::ip::address`

This class contains stuff to deal with IP addresses. It has interfaces to specifically deal with [IPv4](./ipv4.md) and [IPv6](./ipv6.md)
Most important functions:

- `ip::address::from_string()`: Takes a string and returns an `ip::address` object.
- `ip::address::to_string()`: Takes an `ip::address` object and returns a string.
- `ip::address_v4::loopback()`: Returns the loopback address for IPv4. Similar is there for v6.
- `ip::address_v4::broadcast(addr, mask)`: Returns the broadcast address for the given address and mask.
- `ip::host_name()`: Returns the host name of the machine.

## `asio::ip::tcp`

This class is necessary for creation of TCP sockets.

### `tcp::acceptor`

Accepts a new socket connection. So if say one socket was initially there and then another socket is needed to be utilized, the first socket can be gracefully closed and exited and the second one can be used peacefully.

Constructor:

`acceptor::acceptor(const executor_type &e)` constructs a new acceptor without opening it. There are other overloads as well.

`acceptor::accept()`: Has two overloads

- One just accepts a new connection. That's it, its argument is a `tcp::socket`.
- Other overload takes a new connection and gives the detail of the other endpoint to the second argument of the type `tcp::endpoint`.

`acceptor::async_accept()`: Does the same as above but asynchronously.

`acceptor::open(const protocol_type& p)` && `acceptor::bind(const endpoint& e)`

Using this we first define what kind of a connection we want (ipv4 vs ipv6), and then bind the acceptor to a local endpoint.

For example:

```cpp
boost::asio::ip::tcp::acceptor acceptor(my_context);
boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 12345);
acceptor.open(endpoint.protocol());
acceptor.bind(endpoint);
```

## `tcp::socket`

A socket. It is an OS resource. Be careful while utilising it.

Constructor again takes an `io_context` to read and write.

Basically we don't need sockets unless we are going **really** low level. Which isn't really required.

An acceptor is basically an abstraction over the socket. It listens on an endpoint, and needs a new socket for each connection made to to the endpoint. It is the socket that then figures out the communication.

> NOTE: Sockets are not the networking sockets over here. This is because boost ppl had skill issues and actual sockets are actually represented as endpoints over here.


## `steady_timer`

Pretty much what you think it is. Acts as a timer, can be blocking (using the `wait()` method) or non-blocking (using the `async_wait()` method).

The `async_wait` method must take a completion handler (a function) whose sole parameter is of the type `const boost::system::error_code &`.

If the async operations are cancelled using the `cancel()` method, the handler is invoked with `boost::asio::error::operation_aborted` as the argument.
