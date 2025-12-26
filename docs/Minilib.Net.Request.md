# Minilib.Net.Request

Defined in minilib-net@0.6.4

HTTP request and response.
- Parses HTTP request headers and query strings, POST data
  (currently only `application/x-www-form-urlencoded` is supported)
- Writes response back to client

## Values

### namespace Minilib.Net.Request::Headers

#### append

Type: `Std::String -> Std::String -> Minilib.Net.Request::Headers -> Minilib.Net.Request::Headers`

`headers.append(name, value)` appends a new field `(name, value)` to the current headers collection.
The field name is converted to lowercase.
It will not be removed even if a field with the same name already exists,

#### empty

Type: `Minilib.Net.Request::Headers`

An empty collection of headers.

#### find

Type: `Std::String -> Minilib.Net.Request::Headers -> Std::Option Std::String`

`headers.find(name)` finds the field with name `name`.
The field name is converted to lowercase.

#### set

Type: `Std::String -> Std::String -> Minilib.Net.Request::Headers -> Minilib.Net.Request::Headers`

`headers.set(name, value)` sets the value of the field named `name` to `value`.
The field name is converted to lowercase.
If a field with the same name already exists, it will be removed first.

#### to_iter

Type: `Minilib.Net.Request::Headers -> Std::Iterator::DynIterator (Std::String, Std::String)`

`headers.to_iter` returns an iterator of headers.

### namespace Minilib.Net.Request::Request

#### find_query

Type: `Std::String -> Minilib.Net.Request::Request -> Std::Option Std::String`

#### parse

Type: `Std::IO::IOHandle -> Std::String -> Std::IO::IOFail Minilib.Net.Request::Request`

`Request::parse(connection, remote_addr)` reads the HTTP request from `connection` and parse it.

### namespace Minilib.Net.Request::Response

#### content_type

Type: `Std::String -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

`response.content_type(type)` sets the `Content-Type` header.
You can specify an alias for the content type (e.g. "text", "json").
See the definition of `_CONTENT_TYPE_ALIASES` for a list of available aliases.

#### end

Type: `Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response`

Sends headers with a status line if they have not already been sent.
Then flush the connection.

#### header

Type: `Std::String -> Std::String -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

`response.header(name, value)` sets a response header.

#### make

Type: `Minilib.Net.Request::Request -> Minilib.Net.Request::Response`

`Response::make(request)` creates a basic HTTP response for an HTTP request.

#### status

Type: `Std::I64 -> Minilib.Net.Request::Response -> Minilib.Net.Request::Response`

`response.status(code)` sets the HTTP status code. (eg. 404)
It will also set the reason phrase (eg. "Not Found") of the status.

#### write_bytes

Type: `Std::Array Std::U8 -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response`

`response.write_bytes(bytes)` sends headers with a status line if they have not already been sent.
Then it sends the specified bytes.

#### write_str

Type: `Std::String -> Minilib.Net.Request::Response -> Std::IO::IOFail Minilib.Net.Request::Response`

`response.write_str(str)` sends headers with a status line if they have not already been sent.
Then it sends the specified string.

## Types and aliases

### namespace Minilib.Net.Request

#### Header

Defined as: `type Header = (Std::String, Std::String)`

A type that represents a header. The header is a tuple of field name and field value.
Note that the field name is case-insensitive (RFC9112).

#### Headers

Defined as: `type Headers = unbox struct { ...fields... }`

A collection of headers.

##### field `iter`

Type: `Std::Iterator::DynIterator Minilib.Net.Request::Header`

#### Request

Defined as: `type Request = unbox struct { ...fields... }`

A type that represents an HTTP request.

##### field `connection`

Type: `Std::IO::IOHandle`

##### field `remote_addr`

Type: `Std::String`

##### field `method`

Type: `Std::String`

##### field `request_target`

Type: `Std::String`

##### field `http_version`

Type: `Std::String`

##### field `headers`

Type: `Minilib.Net.Request::Headers`

##### field `path`

Type: `Std::String`

##### field `query`

Type: `Std::Array (Std::String, Std::String)`

##### field `body`

Type: `Std::Array Std::U8`

#### Response

Defined as: `type Response = unbox struct { ...fields... }`

A type that represents an HTTP response.

##### field `request`

Type: `Minilib.Net.Request::Request`

##### field `connection`

Type: `Std::IO::IOHandle`

##### field `http_version`

Type: `Std::String`

##### field `status`

Type: `Std::I64`

##### field `reason`

Type: `Std::String`

##### field `headers`

Type: `Minilib.Net.Request::Headers`

##### field `headersSent`

Type: `Std::Bool`

## Traits and aliases

## Trait implementations

### impl `Minilib.Net.Request::Headers : Std::ToString`

### impl `Minilib.Net.Request::Request : Std::ToString`