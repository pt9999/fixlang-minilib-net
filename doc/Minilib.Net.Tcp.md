# `module Minilib.Net.Tcp`

IPv4 TCP Socket operations.

Features:
- IP address, port number
- Resolves IP address from hostname
- IPv4 Socket address
- IPv4 TCP Socket

Tested platform: x86_64-linux-gnu, aarch64-linux-gnu
WARNING: IPv6 is not supported yet.

# Types and aliases

## `namespace Minilib.Net.Tcp`

### `type BufferedSocket = unbox struct { ...fields... }`

This type is a structure that wraps a `Socket` and maintains a write buffer, a read buffer and an EOF flag.

#### field `socket : Minilib.Net.Tcp::Socket`

#### field `write_buf : Std::Array Std::U8`

#### field `read_buf : Std::Array Std::U8`

#### field `eof : Std::Bool`

### `type IpAddress = unbox struct { ...fields... }`

This type represents IPv4 ip address,
eg. 127.0.0.1, 192.168.0.1 etc.

#### field `addr : Std::Array Std::U8`

### `type Port = unbox struct { ...fields... }`

This type reprents IPv4 port number, 0-65535.

#### field `port : Std::U16`

### `type Socket = unbox struct { ...fields... }`

This type represents an IPv4 socket.
It consists of a socket file descriptor.
The socket file descripter is closed automatically when Socket is deallocated.

#### field `data : Std::FFI::Destructor Std::FFI::CInt`

## `namespace Minilib.Net.Tcp::SocketAddress`

### `type SocketAddress = unbox struct { ...fields... }`

This type represents IPv4 ip address and port number.

#### field `dtor : Std::FFI::Destructor Std::Ptr`

# Traits and aliases

# Trait implementations

### `impl Minilib.Net.Tcp::IpAddress : Std::FromString`

### `impl Minilib.Net.Tcp::IpAddress : Std::ToString`

### `impl Minilib.Net.Tcp::Port : Std::FromString`

### `impl Minilib.Net.Tcp::Port : Std::ToString`

### `impl Minilib.Net.Tcp::Socket : Std::ToString`

### `impl Minilib.Net.Tcp::SocketAddress::SocketAddress : Std::ToString`

# Values

## `namespace Minilib.Net.Tcp`

### `connect_to_tcp_server : Std::String -> Std::IO::IOFail Minilib.Net.Tcp::Socket`

Connects to a remote TCP server as a client.
The first argument is `{host}:{port}`, where `{host}` is an IP Address (eg. `192.168.0.1`),
or a FQDN host name (eg. `www.example.com`), and `{port}` is a port number (eg. `8080`).
If the port number is omitted, the default port number is 80.

### `listen_tcp_server : Std::String -> Std::I64 -> Std::IO::IOFail Minilib.Net.Tcp::Socket`

Listens at the specified address as a server.

The first argument is `{host}:{port}`, where `{host}` is an IP Address (typically, `127.0.0.1`),
or a FQDN host name (typically, `localhost`), and `{port}` is a port number (eg. `8080`).
If the port number is omitted, the default port number is 80.

The second argument (`backlog`) is the maximum length to which the queue of pending connections
for the socket may grow.

## `namespace Minilib.Net.Tcp::BufferedSocket`

### `_BUFSIZE : Std::I64`

### `flush : Minilib.Net.Tcp::BufferedSocket -> Std::IO::IOFail Minilib.Net.Tcp::BufferedSocket`

Sends the contents of the writer buffer to the socket and cleans the write buffer.

### `make : Minilib.Net.Tcp::Socket -> Minilib.Net.Tcp::BufferedSocket`

Makes a `BufferedSocket` from a `Socket`.

### `read_line : Minilib.Net.Tcp::BufferedSocket -> Std::IO::IOFail (Std::String, Minilib.Net.Tcp::BufferedSocket)`

Reads out a line (ie. a string that ends with a newline) from the read buffer.
When the read buffer does not contain a newline, it will read some bytes upto
_BUFSIZE from the socket, and search for a newline again.
When the connection is closed, the return value may or may not contain a newline.
The next call of `read_line()` returns an empty string, which represents that the connection is closed.

### `write_str : Std::String -> Minilib.Net.Tcp::BufferedSocket -> Std::IO::IOFail Minilib.Net.Tcp::BufferedSocket`

Writes a string to the write buffer. The contents of the write buffer is not sent
until the size of the write buffer is equal to or greater than `_BUFSIZE`, or `flush()` is called.

## `namespace Minilib.Net.Tcp::IpAddress`

### `_resolve_ipaddress_v4 : Std::String -> Std::IO::IOFail Minilib.Net.Tcp::IpAddress`

### `from_U32 : Std::U32 -> Minilib.Net.Tcp::IpAddress`

Converts U32 to an `IpAddress`, for example 0x7f000001_U32 -> 127.0.0.1.

### `from_array : Std::Array Std::U8 -> Minilib.Net.Tcp::IpAddress`

Converts a byte array to an `IpAddress`. The length of the byte array must be 4.

### `resolve : Std::String -> Std::IO::IOFail Minilib.Net.Tcp::IpAddress`

Resolve a hostname such as "127.0.0.1" or "www.example.com".

### `to_U32 : Minilib.Net.Tcp::IpAddress -> Std::U32`

## `namespace Minilib.Net.Tcp::Port`

### `from_U16 : Std::U16 -> Minilib.Net.Tcp::Port`

### `to_U16 : Minilib.Net.Tcp::Port -> Std::U16`

## `namespace Minilib.Net.Tcp::Socket`

### `_unsafe_from_fd : Std::FFI::CInt -> Std::IO::IOFail Minilib.Net.Tcp::Socket`

Creates `Socket` from a file descriptor of a socket.
The socket will be automatically closed when `Socket` is deallocated.

### `accept : Minilib.Net.Tcp::Socket -> Std::IO::IOFail (Minilib.Net.Tcp::Socket, Minilib.Net.Tcp::SocketAddress::SocketAddress)`

Waits for an incoming connection request. If an incoming connection arrives, accept it,
and returns a socket of accepted connection and the remote socket address.

### `accept_fd : Minilib.Net.Tcp::Socket -> Std::IO::IOFail (Std::FFI::CInt, Minilib.Net.Tcp::SocketAddress::SocketAddress)`

Same as `accept()`, except that it returns the accepted socket's file descriptor instead of `Socket`.

### `bind : Minilib.Net.Tcp::SocketAddress::SocketAddress -> Minilib.Net.Tcp::Socket -> Std::IO::IOFail ()`

Assigns an IPv4 ip address and a port number to the socket.

### `borrow_fd_io : (Std::FFI::CInt -> Std::IO a) -> Minilib.Net.Tcp::Socket -> Std::IO a`

Call an IO action with a file descriptor of a socket.

### `connect : Minilib.Net.Tcp::SocketAddress::SocketAddress -> Minilib.Net.Tcp::Socket -> Std::IO::IOFail ()`

Connects to the specified address.

### `listen : Std::I64 -> Minilib.Net.Tcp::Socket -> Std::IO::IOFail ()`

Listens the socket for incoming connection requests.
The first argument (backlog) is the maximum length to which the queue of pending connections for sockfd may grow.

### `make_tcp_socket : () -> Std::IO::IOFail Minilib.Net.Tcp::Socket`

Creates new tcp socket.
The socket will be automatically closed when `Socket` is deallocated.

### `recv : Std::I64 -> Minilib.Net.Tcp::Socket -> Std::IO::IOFail (Std::Array Std::U8)`

Receives messages from a socket.
The first argument is the maximum number of bytes to receive.
If no message are available at the socket, `recv()` waits for a message to arrive.
Returns the number of bytes received.
When the socket has been shutdown, the return value will be 0.

### `send : Std::Array Std::U8 -> Minilib.Net.Tcp::Socket -> Std::IO::IOFail Std::I64`

Transmits a message to another socket.
May be used only when the socket is in a connected state.
Returns the number of bytes sent.

### `setsockopt_reuseaddr : Minilib.Net.Tcp::Socket -> Std::IO::IOFail ()`

## `namespace Minilib.Net.Tcp::SocketAddress`

### `_unsafe_from_sockaddr_in : Std::Ptr -> Minilib.Net.Tcp::SocketAddress::SocketAddress`

Creates a `SocketAddress` from an allocated pointer to `struct sockaddr_in`.

### `get_ipaddress : Minilib.Net.Tcp::SocketAddress::SocketAddress -> Minilib.Net.Tcp::IpAddress`

Extracts an ip address from the socket address.

### `get_port : Minilib.Net.Tcp::SocketAddress::SocketAddress -> Minilib.Net.Tcp::Port`

Extracts a port number from the socket address.

### `make : Minilib.Net.Tcp::IpAddress -> Minilib.Net.Tcp::Port -> Minilib.Net.Tcp::SocketAddress::SocketAddress`

Creates a `SocketAddress` from an ip address and a port.

### `resolve : Std::String -> Std::IO::IOFail Minilib.Net.Tcp::SocketAddress::SocketAddress`

Splits the first argument into a host name and a port number, then resolves the host
name to an ip address, then creates a `SocketAddress` from the ip address and
the port number.

The first argument is `{host}:{port}`, where `{host}` is an IP Address (eg. `192.168.0.1`),
or a FQDN host name (eg. `www.example.com`), and `{port}` is a port number (eg. `8080`).
If the port number is omitted, the default port number is 80.