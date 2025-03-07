# Minilib.Net.URL

Defined in minilib-net@0.5.2

URL and URI parsing

## Values

### namespace Minilib.Net.URL::URI

#### _alpha_numeric

Type: `Std::Array Std::U8`

Lookup table of characters that consists of `[A-Za-z0-9]`.

#### _decodeURIComponent_table

Type: `Std::Array Std::U8`

Lookup table of characters that `decodeURIComponent()` should not unescape.

#### _decodeURI_table

Type: `Std::Array Std::U8`

Lookup table of characters that `decodeURI()` should not unescape.

#### _decode_with

Type: `Std::Array Std::U8 -> Std::String -> Std::Result Std::ErrMsg Std::String`

Decodes a string with a table.

#### _encodeURIComponent_table

Type: `Std::Array Std::U8`

Lookup table of characters that `encodeURIComponent()` should not escape.

#### _encodeURI_table

Type: `Std::Array Std::U8`

Lookup table of characters that `encodeURI()` should not escape.

#### _encode_with

Type: `Std::Array Std::U8 -> Std::String -> Std::String`

Encodes a string with a table.

#### decodeURI

Type: `Std::String -> Std::Result Std::ErrMsg Std::String`

Same as JavaScript `decodeURI()`.
For details, see [decodeURI()](https://developer.mozilla.org/ja/docs/Web/JavaScript/Reference/Global_Objects/decodeURI)
of MDN web docs.

#### decodeURIComponent

Type: `Std::String -> Std::Result Std::ErrMsg Std::String`

Same as JavaScript `decodeURIComponent()`.
For details, see [decodeURIComponent()](https://developer.mozilla.org/ja/docs/Web/JavaScript/Reference/Global_Objects/decodeURIComponent)
of MDN web docs.

#### encodeURI

Type: `Std::String -> Std::String`

Same as JavaScript `encodeURI()`.
For details, see [encodeURI()](https://developer.mozilla.org/ja/docs/Web/JavaScript/Reference/Global_Objects/encodeURI)
of MDN web docs.

#### encodeURIComponent

Type: `Std::String -> Std::String`

Same as JavaScript `encodeURIComponent()`.
For details, see [encodeURIComponent()](https://developer.mozilla.org/ja/docs/Web/JavaScript/Reference/Global_Objects/encodeURIComponent)
of MDN web docs.

### namespace Minilib.Net.URL::URL

#### parse

Type: `Std::String -> Std::Result Std::ErrMsg Minilib.Net.URL::URL`

Parses a string as a URL.
Recognized format of a URL is:
   [scheme://]host[:port][path]
If the scheme part is omitted, a default value ("http") is used as a scheme.
The host and port part should not contain "/".
If the port part is omitted, a default value ("443" if scheme == "https", "80" otherwise)
is used as a port.
The path part should be starts with "/".
If the path part is omitted, a default value ("/") is used as a path.

## Types and aliases

### namespace Minilib.Net.URL

#### URL

Defined as: `type URL = unbox struct { ...fields... }`

A structure that represents an URL.

##### field `url`

Type: `Std::String`

##### field `scheme`

Type: `Std::String`

##### field `host`

Type: `Std::String`

##### field `port`

Type: `Std::String`

##### field `path`

Type: `Std::String`

## Traits and aliases

## Trait implementations

### impl `Minilib.Net.URL::URL : Std::Eq`

Checks whether two URLs are equal.

### impl `Minilib.Net.URL::URL : Std::ToString`

Converts an URL to a string.