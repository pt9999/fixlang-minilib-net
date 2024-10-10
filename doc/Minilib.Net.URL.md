# `module Minilib.Net.URL`

URL and URI parsing

# Types and aliases

## `namespace Minilib.Net.URL`

### `type URL = unbox struct { ...fields... }`

A structure that represents an URL.

#### field `url : Std::String`

#### field `scheme : Std::String`

#### field `host : Std::String`

#### field `port : Std::String`

#### field `path : Std::String`

# Traits and aliases

# Trait implementations

### `impl Minilib.Net.URL::URL : Std::Eq`

Checks whether two URLs are equal.

### `impl Minilib.Net.URL::URL : Std::ToString`

Converts an URL to a string.

# Values

## `namespace Minilib.Net.URL::URI`

### `_alpha_numeric : Std::Array Std::U8`

Lookup table of characters that consists of `[A-Za-z0-9]`.

### `_decodeURIComponent_table : Std::Array Std::U8`

Lookup table of characters that `decodeURIComponent()` should not unescape.

### `_decodeURI_table : Std::Array Std::U8`

Lookup table of characters that `decodeURI()` should not unescape.

### `_decode_with : Std::Array Std::U8 -> Std::String -> Std::Result Std::String Std::String`

Decodes a string with a table.

### `_encodeURIComponent_table : Std::Array Std::U8`

Lookup table of characters that `encodeURIComponent()` should not escape.

### `_encodeURI_table : Std::Array Std::U8`

Lookup table of characters that `encodeURI()` should not escape.

### `_encode_with : Std::Array Std::U8 -> Std::String -> Std::String`

Encodes a string with a table.

### `decodeURI : Std::String -> Std::Result Std::String Std::String`

Same as JavaScript `decodeURI()`.
For details, see [decodeURI()](https://developer.mozilla.org/ja/docs/Web/JavaScript/Reference/Global_Objects/decodeURI)
of MDN web docs.

### `decodeURIComponent : Std::String -> Std::Result Std::String Std::String`

Same as JavaScript `decodeURIComponent()`.
For details, see [decodeURIComponent()](https://developer.mozilla.org/ja/docs/Web/JavaScript/Reference/Global_Objects/decodeURIComponent)
of MDN web docs.

### `encodeURI : Std::String -> Std::String`

Same as JavaScript `encodeURI()`.
For details, see [encodeURI()](https://developer.mozilla.org/ja/docs/Web/JavaScript/Reference/Global_Objects/encodeURI)
of MDN web docs.

### `encodeURIComponent : Std::String -> Std::String`

Same as JavaScript `encodeURIComponent()`.
For details, see [encodeURIComponent()](https://developer.mozilla.org/ja/docs/Web/JavaScript/Reference/Global_Objects/encodeURIComponent)
of MDN web docs.

## `namespace Minilib.Net.URL::URL`

### `@host : Minilib.Net.URL::URL -> Std::String`

Retrieves the field `host` from a value of `URL`.

### `@path : Minilib.Net.URL::URL -> Std::String`

Retrieves the field `path` from a value of `URL`.

### `@port : Minilib.Net.URL::URL -> Std::String`

Retrieves the field `port` from a value of `URL`.

### `@scheme : Minilib.Net.URL::URL -> Std::String`

Retrieves the field `scheme` from a value of `URL`.

### `@url : Minilib.Net.URL::URL -> Std::String`

Retrieves the field `url` from a value of `URL`.

### `act_host : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Net.URL::URL -> f Minilib.Net.URL::URL`

Updates a value of `URL` by applying a functorial action to field `host`.

### `act_path : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Net.URL::URL -> f Minilib.Net.URL::URL`

Updates a value of `URL` by applying a functorial action to field `path`.

### `act_port : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Net.URL::URL -> f Minilib.Net.URL::URL`

Updates a value of `URL` by applying a functorial action to field `port`.

### `act_scheme : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Net.URL::URL -> f Minilib.Net.URL::URL`

Updates a value of `URL` by applying a functorial action to field `scheme`.

### `act_url : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Net.URL::URL -> f Minilib.Net.URL::URL`

Updates a value of `URL` by applying a functorial action to field `url`.

### `mod_host : (Std::String -> Std::String) -> Minilib.Net.URL::URL -> Minilib.Net.URL::URL`

Updates a value of `URL` by applying a function to field `host`.

### `mod_path : (Std::String -> Std::String) -> Minilib.Net.URL::URL -> Minilib.Net.URL::URL`

Updates a value of `URL` by applying a function to field `path`.

### `mod_port : (Std::String -> Std::String) -> Minilib.Net.URL::URL -> Minilib.Net.URL::URL`

Updates a value of `URL` by applying a function to field `port`.

### `mod_scheme : (Std::String -> Std::String) -> Minilib.Net.URL::URL -> Minilib.Net.URL::URL`

Updates a value of `URL` by applying a function to field `scheme`.

### `mod_url : (Std::String -> Std::String) -> Minilib.Net.URL::URL -> Minilib.Net.URL::URL`

Updates a value of `URL` by applying a function to field `url`.

### `parse : Std::String -> Std::Result Std::String Minilib.Net.URL::URL`

Parses a string as a URL.
Recognized format of a URL is:
   [scheme://]host[:port][path]
If the scheme part is omitted, a default value ("http") is used as a scheme.
The host and port part should not contain "/".
If the port part is omitted, a default value ("443" if scheme == "https", "80" otherwise)
is used as a port.
The path part should be starts with "/".
If the path part is omitted, a default value ("/") is used as a path.

### `set_host : Std::String -> Minilib.Net.URL::URL -> Minilib.Net.URL::URL`

Updates a value of `URL` by setting field `host` to a specified one.

### `set_path : Std::String -> Minilib.Net.URL::URL -> Minilib.Net.URL::URL`

Updates a value of `URL` by setting field `path` to a specified one.

### `set_port : Std::String -> Minilib.Net.URL::URL -> Minilib.Net.URL::URL`

Updates a value of `URL` by setting field `port` to a specified one.

### `set_scheme : Std::String -> Minilib.Net.URL::URL -> Minilib.Net.URL::URL`

Updates a value of `URL` by setting field `scheme` to a specified one.

### `set_url : Std::String -> Minilib.Net.URL::URL -> Minilib.Net.URL::URL`

Updates a value of `URL` by setting field `url` to a specified one.