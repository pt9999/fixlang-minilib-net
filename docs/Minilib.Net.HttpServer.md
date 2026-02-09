# Minilib.Net.HttpServer

Defined in minilib-net@0.7.0

Simple HTTP server.
The interface is similar to `express` of Node.js.
- Insert a request handler on specific path
- Listen for incoming requests

## Values

### namespace Minilib.Net.HttpServer::App

#### insert_handler

Type: `Std::String -> Std::String -> Minilib.Net.HttpServer::RequestHandler -> Minilib.Net.HttpServer::App -> Minilib.Net.HttpServer::App`

`app.insert_handler(method, path, handler)` inserts a handler
at `path` for `method`.

#### listen

Type: `Std::String -> Minilib.Net.HttpServer::App -> Std::IO::IOFail Minilib.Net.HttpServer::App`

`app.listen(server_host_port)` listens for incoming requests,
and respond to accepted connections.

This function sets the signal handler for SIGPIPE to SIG_IGN to avoid
abnormal program termination when writing to a closed socket.

#### make

Type: `() -> Minilib.Net.HttpServer::App`

`App::make()` creates an empty application.

#### on

Type: `Std::String -> Std::String -> Minilib.Net.HttpServer::RequestHandler -> Minilib.Net.HttpServer::App -> Minilib.Net.HttpServer::App`

Alias of `insert_handler`.

### namespace Minilib.Net.HttpServer::Worker

#### handle

Type: `Std::IO::IOHandle -> Std::String -> Minilib.Net.HttpServer::Worker -> Std::IO ()`

`worker.handle(connection, remote_addr)` receives an HTTP request from the socket connection,
then finds the request handler for the request, and call that handler.

#### make

Type: `Minilib.Net.HttpServer::App -> Minilib.Net.HttpServer::Worker`

Creates a worker for the application.

## Types and aliases

### namespace Minilib.Net.HttpServer

#### App

Defined as: `type App = unbox struct { ...fields... }`

This type represents an application.

##### field `router`

Type: `Minilib.Net.Router::Router Minilib.Net.HttpServer::RequestHandler`

##### field `backlog`

Type: `Std::I64`

#### RequestHandler

Defined as: `type RequestHandler = Minilib.Net.Request::Request -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response`

The request handler interprets an HTTP request and outputs an HTTP response to `response.@connection`.
It returns an HTTP response.

#### Worker

Defined as: `type Worker = unbox struct { ...fields... }`

The worker is responsible for processing a request. Specifically,
it reads one request from the socket, processes it, and writes a response to the socket.

##### field `app`

Type: `Minilib.Net.HttpServer::App`

## Traits and aliases

## Trait implementations