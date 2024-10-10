# `module Minilib.Net.Request`

HTTP request and response.
- Parses HTTP request headers and query strings, POST data
  (currently only `application/x-www-form-urlencoded` is supported)
- Writes response back to client

# Types and aliases

## `namespace Minilib.Net.Request`

### `type Header = (Std::String, Std::String)`

A type that represents a header. The header is a tuple of field name and field value.
Note that the field name is case-insensitive (RFC9112).

### `type Headers = unbox struct { ...fields... }`

A collection of headers.

#### field `iter : Std::Iterator (Std::String, Std::String)`

### `type Request = unbox struct { ...fields... }`

A type that represents an HTTP request.

#### field `connection : Std::IO::IOHandle`

#### field `remote_addr : Std::String`

#### field `method : Std::String`

#### field `request_target : Std::String`

#### field `http_version : Std::String`

#### field `headers : Minilib.Net.Request::Headers`

#### field `path : Std::String`

#### field `query : Std::Array (Std::String, Std::String)`

#### field `body : Std::Array Std::U8`

### `type Response = unbox struct { ...fields... }`

A type that represents an HTTP response.

#### field `request : Minilib.Net.Request::Request`

#### field `connection : Std::IO::IOHandle`

#### field `http_version : Std::String`

#### field `status : Std::I64`

#### field `reason : Std::String`

#### field `headers : Minilib.Net.Request::Headers`

#### field `headersSent : Std::Bool`

# Traits and aliases

# Trait implementations

### `impl Minilib.Net.Request::Headers : Std::ToString`

### `impl Minilib.Net.Request::Request : Std::ToString`

# Values

## `namespace Minilib.Net.Request`

### `_CONTENT_TYPE_ALIASES : HashMap::HashMap Std::String Std::String`

Content-Type (MIME type) aliases

### `_STATUS_REASON : HashMap::HashMap Std::I64 Std::String`

RFC9110
HTTP status and reason-phrase

## `namespace Minilib.Net.Request::Headers`

### `@iter : Minilib.Net.Request::Headers -> Std::Iterator (Std::String, Std::String)`

Retrieves the field `iter` from a value of `Headers`.

### `act_iter : [f : Std::Functor] (Std::Iterator (Std::String, Std::String) -> f (Std::Iterator (Std::String, Std::String))) -> Minilib.Net.Request::Headers -> f Minilib.Net.Request::Headers`

Updates a value of `Headers` by applying a functorial action to field `iter`.

### `append : Std::String -> Std::String -> Minilib.Net.Request::Headers -> Minilib.Net.Request::Headers`

`headers.append(name, value)` appends a new field `(name, value)` to the current headers collection.
The field name is converted to lowercase.
It will not be removed even if a field with the same name already exists,

### `empty : Minilib.Net.Request::Headers`

An empty collection of headers.

### `find : Std::String -> Minilib.Net.Request::Headers -> Std::Option Std::String`

`headers.find(name)` finds the field with name `name`.
The field name is converted to lowercase.

### `mod_iter : (Std::Iterator (Std::String, Std::String) -> Std::Iterator (Std::String, Std::String)) -> Minilib.Net.Request::Headers -> Minilib.Net.Request::Headers`

Updates a value of `Headers` by applying a function to field `iter`.

### `set : Std::String -> Std::String -> Minilib.Net.Request::Headers -> Minilib.Net.Request::Headers`

`headers.set(name, value)` sets the value of the field named `name` to `value`.
The field name is converted to lowercase.
If a field with the same name already exists, it will be removed first.

### `set_iter : Std::Iterator (Std::String, Std::String) -> Minilib.Net.Request::Headers -> Minilib.Net.Request::Headers`

Updates a value of `Headers` by setting field `iter` to a specified one.

### `to_iter : Minilib.Net.Request::Headers -> Std::Iterator (Std::String, Std::String)`

`headers.to_iter` returns an iterator of headers.

## `namespace Minilib.Net.Request::Request`

### `@body : Minilib.Net.Request::Request -> Std::Array Std::U8`

Retrieves the field `body` from a value of `Request`.

### `@connection : Minilib.Net.Request::Request -> Std::IO::IOHandle`

Retrieves the field `connection` from a value of `Request`.

### `@headers : Minilib.Net.Request::Request -> Minilib.Net.Request::Headers`

Retrieves the field `headers` from a value of `Request`.

### `@http_version : Minilib.Net.Request::Request -> Std::String`

Retrieves the field `http_version` from a value of `Request`.

### `@method : Minilib.Net.Request::Request -> Std::String`

Retrieves the field `method` from a value of `Request`.

### `@path : Minilib.Net.Request::Request -> Std::String`

Retrieves the field `path` from a value of `Request`.

### `@query : Minilib.Net.Request::Request -> Std::Array (Std::String, Std::String)`

Retrieves the field `query` from a value of `Request`.

### `@remote_addr : Minilib.Net.Request::Request -> Std::String`

Retrieves the field `remote_addr` from a value of `Request`.

### `@request_target : Minilib.Net.Request::Request -> Std::String`

Retrieves the field `request_target` from a value of `Request`.

### `_parse_header : Std::String -> Std::Result Std::String (Std::String, Std::String)`

### `_parse_query_string : Std::String -> Std::IO::IOFail (Std::Array (Std::String, Std::String))`

### `_parse_request_line : Std::String -> Std::Result Std::String (Std::String, Std::String, Std::String)`

### `act_body : [f : Std::Functor] (Std::Array Std::U8 -> f (Std::Array Std::U8)) -> Minilib.Net.Request::Request -> f Minilib.Net.Request::Request`

Updates a value of `Request` by applying a functorial action to field `body`.

### `act_connection : [f : Std::Functor] (Std::IO::IOHandle -> f Std::IO::IOHandle) -> Minilib.Net.Request::Request -> f Minilib.Net.Request::Request`

Updates a value of `Request` by applying a functorial action to field `connection`.

### `act_headers : [f : Std::Functor] (Minilib.Net.Request::Headers -> f Minilib.Net.Request::Headers) -> Minilib.Net.Request::Request -> f Minilib.Net.Request::Request`

Updates a value of `Request` by applying a functorial action to field `headers`.

### `act_http_version : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Net.Request::Request -> f Minilib.Net.Request::Request`

Updates a value of `Request` by applying a functorial action to field `http_version`.

### `act_method : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Net.Request::Request -> f Minilib.Net.Request::Request`

Updates a value of `Request` by applying a functorial action to field `method`.

### `act_path : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Net.Request::Request -> f Minilib.Net.Request::Request`

Updates a value of `Request` by applying a functorial action to field `path`.

### `act_query : [f : Std::Functor] (Std::Array (Std::String, Std::String) -> f (Std::Array (Std::String, Std::String))) -> Minilib.Net.Request::Request -> f Minilib.Net.Request::Request`

Updates a value of `Request` by applying a functorial action to field `query`.

### `act_remote_addr : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Net.Request::Request -> f Minilib.Net.Request::Request`

Updates a value of `Request` by applying a functorial action to field `remote_addr`.

### `act_request_target : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Net.Request::Request -> f Minilib.Net.Request::Request`

Updates a value of `Request` by applying a functorial action to field `request_target`.

### `find_query : Std::String -> Minilib.Net.Request::Request -> Std::Option Std::String`

### `mod_body : (Std::Array Std::U8 -> Std::Array Std::U8) -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by applying a function to field `body`.

### `mod_connection : (Std::IO::IOHandle -> Std::IO::IOHandle) -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by applying a function to field `connection`.

### `mod_headers : (Minilib.Net.Request::Headers -> Minilib.Net.Request::Headers) -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by applying a function to field `headers`.

### `mod_http_version : (Std::String -> Std::String) -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by applying a function to field `http_version`.

### `mod_method : (Std::String -> Std::String) -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by applying a function to field `method`.

### `mod_path : (Std::String -> Std::String) -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by applying a function to field `path`.

### `mod_query : (Std::Array (Std::String, Std::String) -> Std::Array (Std::String, Std::String)) -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by applying a function to field `query`.

### `mod_remote_addr : (Std::String -> Std::String) -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by applying a function to field `remote_addr`.

### `mod_request_target : (Std::String -> Std::String) -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by applying a function to field `request_target`.

### `parse : Std::IO::IOHandle -> Std::String -> Std::IO::IOFail Minilib.Net.Request::Request`

`Request::parse(connection, remote_addr)` reads the HTTP request from `connection` and parse it.

### `set_body : Std::Array Std::U8 -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by setting field `body` to a specified one.

### `set_connection : Std::IO::IOHandle -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by setting field `connection` to a specified one.

### `set_headers : Minilib.Net.Request::Headers -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by setting field `headers` to a specified one.

### `set_http_version : Std::String -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by setting field `http_version` to a specified one.

### `set_method : Std::String -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by setting field `method` to a specified one.

### `set_path : Std::String -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by setting field `path` to a specified one.

### `set_query : Std::Array (Std::String, Std::String) -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by setting field `query` to a specified one.

### `set_remote_addr : Std::String -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by setting field `remote_addr` to a specified one.

### `set_request_target : Std::String -> Minilib.Net.Request::Request -> Minilib.Net.Request::Request`

Updates a value of `Request` by setting field `request_target` to a specified one.

## `namespace Minilib.Net.Request::Response`

### `@connection : Minilib.Net.Request::Response -> Std::IO::IOHandle`

Retrieves the field `connection` from a value of `Response`.

### `@headers : Minilib.Net.Request::Response -> Minilib.Net.Request::Headers`

Retrieves the field `headers` from a value of `Response`.

### `@headersSent : Minilib.Net.Request::Response -> Std::Bool`

Retrieves the field `headersSent` from a value of `Response`.

### `@http_version : Minilib.Net.Request::Response -> Std::String`

Retrieves the field `http_version` from a value of `Response`.

### `@reason : Minilib.Net.Request::Response -> Std::String`

Retrieves the field `reason` from a value of `Response`.

### `@request : Minilib.Net.Request::Response -> Minilib.Net.Request::Request`

Retrieves the field `request` from a value of `Response`.

### `@status : Minilib.Net.Request::Response -> Std::I64`

Retrieves the field `status` from a value of `Response`.

### `_send_headers : Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response`

Sends headers with a status line if they have not already been sent.

### `act_connection : [f : Std::Functor] (Std::IO::IOHandle -> f Std::IO::IOHandle) -> Minilib.Net.Request::Response -> f Minilib.Net.Request::Response`

Updates a value of `Response` by applying a functorial action to field `connection`.

### `act_headers : [f : Std::Functor] (Minilib.Net.Request::Headers -> f Minilib.Net.Request::Headers) -> Minilib.Net.Request::Response -> f Minilib.Net.Request::Response`

Updates a value of `Response` by applying a functorial action to field `headers`.

### `act_headersSent : [f : Std::Functor] (Std::Bool -> f Std::Bool) -> Minilib.Net.Request::Response -> f Minilib.Net.Request::Response`

Updates a value of `Response` by applying a functorial action to field `headersSent`.

### `act_http_version : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Net.Request::Response -> f Minilib.Net.Request::Response`

Updates a value of `Response` by applying a functorial action to field `http_version`.

### `act_reason : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Net.Request::Response -> f Minilib.Net.Request::Response`

Updates a value of `Response` by applying a functorial action to field `reason`.

### `act_request : [f : Std::Functor] (Minilib.Net.Request::Request -> f Minilib.Net.Request::Request) -> Minilib.Net.Request::Response -> f Minilib.Net.Request::Response`

Updates a value of `Response` by applying a functorial action to field `request`.

### `act_status : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.Net.Request::Response -> f Minilib.Net.Request::Response`

Updates a value of `Response` by applying a functorial action to field `status`.

### `content_type : Std::String -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

`response.content_type(type)` sets the `Content-Type` header.
You can specify an alias for the content type (e.g. "text", "json").
See the definition of `_CONTENT_TYPE_ALIASES` for a list of available aliases.

### `end : Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response`

Sends headers with a status line if they have not already been sent.
Then flush the connection.

### `header : Std::String -> Std::String -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

`response.header(name, value)` sets a response header.

### `make : Minilib.Net.Request::Request -> Minilib.Net.Request::Response`

`Response::make(request)` creates a basic HTTP response for an HTTP request.

### `mod_connection : (Std::IO::IOHandle -> Std::IO::IOHandle) -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by applying a function to field `connection`.

### `mod_headers : (Minilib.Net.Request::Headers -> Minilib.Net.Request::Headers) -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by applying a function to field `headers`.

### `mod_headersSent : (Std::Bool -> Std::Bool) -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by applying a function to field `headersSent`.

### `mod_http_version : (Std::String -> Std::String) -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by applying a function to field `http_version`.

### `mod_reason : (Std::String -> Std::String) -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by applying a function to field `reason`.

### `mod_request : (Minilib.Net.Request::Request -> Minilib.Net.Request::Request) -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by applying a function to field `request`.

### `mod_status : (Std::I64 -> Std::I64) -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by applying a function to field `status`.

### `set_connection : Std::IO::IOHandle -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by setting field `connection` to a specified one.

### `set_headers : Minilib.Net.Request::Headers -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by setting field `headers` to a specified one.

### `set_headersSent : Std::Bool -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by setting field `headersSent` to a specified one.

### `set_http_version : Std::String -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by setting field `http_version` to a specified one.

### `set_reason : Std::String -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by setting field `reason` to a specified one.

### `set_request : Minilib.Net.Request::Request -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by setting field `request` to a specified one.

### `set_status : Std::I64 -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

Updates a value of `Response` by setting field `status` to a specified one.

### `status : Std::I64 -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

`response.status(code)` sets the HTTP status code. (eg. 404)
It will also set the reason phrase (eg. "Not Found") of the status.

### `write_bytes : Std::Array Std::U8 -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response`

`response.write_bytes(bytes)` sends headers with a status line if they have not already been sent.
Then it sends the specified bytes.

### `write_str : Std::String -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response`

`response.write_str(str)` sends headers with a status line if they have not already been sent.
Then it sends the specified string.