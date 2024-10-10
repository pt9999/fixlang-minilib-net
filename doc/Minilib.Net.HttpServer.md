# `module Minilib.Net.HttpServer`

Simple HTTP server.
The interface is similar to `express` of Node.js.
- Insert a request handler on specific path
- Listen for incoming requests

# Types and aliases

## `namespace Minilib.Net.HttpServer`

### `type App = unbox struct { ...fields... }`

This type represents an application.

#### field `router : Minilib.Net.Router::Router (Minilib.Net.Request::Request -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response)`

#### field `backlog : Std::I64`

### `type RequestHandler = Minilib.Net.Request::Request -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response`

The request handler interprets an HTTP request and outputs an HTTP response to `response.@connection`.
It returns an HTTP response.

### `type Worker = unbox struct { ...fields... }`

The worker is responsible for processing a request. Specifically,
it reads one request from the socket, processes it, and writes a response to the socket.

#### field `app : Minilib.Net.HttpServer::App`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Net.HttpServer::App`

### `@backlog : Minilib.Net.HttpServer::App -> Std::I64`

Retrieves the field `backlog` from a value of `App`.

### `@router : Minilib.Net.HttpServer::App -> Minilib.Net.Router::Router (Minilib.Net.Request::Request -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response)`

Retrieves the field `router` from a value of `App`.

### `act_backlog : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Net.HttpServer::App -> f Minilib.Net.HttpServer::App`

Updates a value of `App` by applying a functorial action to field `backlog`.

### `act_router : [f : Std::Functor] (Minilib.Net.Router::Router (Minilib.Net.Request::Request -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response) -> f (Minilib.Net.Router::Router (Minilib.Net.Request::Request -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response))) -> Minilib.Net.HttpServer::App -> f Minilib.Net.HttpServer::App`

Updates a value of `App` by applying a functorial action to field `router`.

### `insert_handler : Std::String -> Std::String -> (Minilib.Net.Request::Request -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response) -> Minilib.Net.HttpServer::App -> Minilib.Net.HttpServer::App`

`app.insert_handler(method, path, handler)` inserts a handler
at `path` for `method`.

### `listen : Std::String -> Minilib.Net.HttpServer::App -> Std::IO::IOFail Minilib.Net.HttpServer::App`

`app.listen(server_host_port)` listens for incoming requests,
and respond to accepted connections.

This function sets the signal handler for SIGPIPE to SIG_IGN to avoid
abnormal program termination when writing to a closed socket.

### `make : () -> Minilib.Net.HttpServer::App`

`App::make()` creates an empty application.

### `mod_backlog : (Std::I64 -> Std::I64) -> Minilib.Net.HttpServer::App -> Minilib.Net.HttpServer::App`

Updates a value of `App` by applying a function to field `backlog`.

### `mod_router : (Minilib.Net.Router::Router (Minilib.Net.Request::Request -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response) -> Minilib.Net.Router::Router (Minilib.Net.Request::Request -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response)) -> Minilib.Net.HttpServer::App -> Minilib.Net.HttpServer::App`

Updates a value of `App` by applying a function to field `router`.

### `on : Std::String -> Std::String -> (Minilib.Net.Request::Request -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response) -> Minilib.Net.HttpServer::App -> Minilib.Net.HttpServer::App`

Alias of `insert_handler`.

### `set_backlog : Std::I64 -> Minilib.Net.HttpServer::App -> Minilib.Net.HttpServer::App`

Updates a value of `App` by setting field `backlog` to a specified one.

### `set_router : Minilib.Net.Router::Router (Minilib.Net.Request::Request -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response) -> Minilib.Net.HttpServer::App -> Minilib.Net.HttpServer::App`

Updates a value of `App` by setting field `router` to a specified one.

## `namespace Minilib.Net.HttpServer::Worker`

### `@app : Minilib.Net.HttpServer::Worker -> Minilib.Net.HttpServer::App`

Retrieves the field `app` from a value of `Worker`.

### `_finally : (() -> Std::IO ()) -> Std::IO::IOFail a -> Std::IO::IOFail a`

### `_not_found_handler : Minilib.Net.Request::Request -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response`

### `act_app : [f : Std::Functor] (Minilib.Net.HttpServer::App -> f Minilib.Net.HttpServer::App) -> Minilib.Net.HttpServer::Worker -> f Minilib.Net.HttpServer::Worker`

Updates a value of `Worker` by applying a functorial action to field `app`.

### `handle : Std::IO::IOHandle -> Std::String -> Minilib.Net.HttpServer::Worker -> Std::IO ()`

`worker.handle(connection, remote_addr)` receives an HTTP request from the socket connection,
then finds the request handler for the request, and call that handler.

### `make : Minilib.Net.HttpServer::App -> Minilib.Net.HttpServer::Worker`

Creates a worker for the application.

### `mod_app : (Minilib.Net.HttpServer::App -> Minilib.Net.HttpServer::App) -> Minilib.Net.HttpServer::Worker -> Minilib.Net.HttpServer::Worker`

Updates a value of `Worker` by applying a function to field `app`.

### `set_app : Minilib.Net.HttpServer::App -> Minilib.Net.HttpServer::Worker -> Minilib.Net.HttpServer::Worker`

Updates a value of `Worker` by setting field `app` to a specified one.