# Minilib.Net.Router

Defined in minilib-net@0.6.5

HTTP request router.
- Mounts a request handler to specific path and method
- Finds a request handler from path and method of the HTTP request

## Values

### namespace Minilib.Net.Router::Router

#### empty

Type: `Minilib.Net.Router::Router h`

An empty router.

#### find

Type: `Std::String -> Std::String -> Minilib.Net.Router::Router h -> Std::Option h`

`router.find(method, path)` finds the handler that matches `method` and `path`.

#### insert

Type: `Std::String -> Std::String -> h -> Minilib.Net.Router::Router h -> Minilib.Net.Router::Router h`

`router.insert(method, path, handler)` tells that `method` and  path
should be mapped to this handler.

### namespace Minilib.Net.Router::RouterEntry

#### empty

Type: `Minilib.Net.Router::RouterEntry h`

An empty entry.

#### find

Type: `Std::String -> Minilib.Net.Router::RouterEntry h -> Std::Option h`

`router_entry.find(method)` finds the handler of the method.

#### is_empty

Type: `Minilib.Net.Router::RouterEntry h -> Std::Bool`

Returns true iff it is an empty entry.

#### update

Type: `Std::String -> h -> Minilib.Net.Router::RouterEntry h -> Minilib.Net.Router::RouterEntry h`

`router_entry.update(method, handler)` sets the handler of the method `method` to `handler`.

### namespace Minilib.Net.Router::RouterNode

#### create

Type: `Std::Iterator::DynIterator Std::String -> (Minilib.Net.Router::RouterEntry h -> Minilib.Net.Router::RouterEntry h) -> Minilib.Net.Router::RouterNode h`

`RouterNode::create(path, entry_updater)` creates a node.

#### empty

Type: `Minilib.Net.Router::RouterNode h`

An empty router node.

#### find

Type: `Std::Iterator::DynIterator Std::String -> Minilib.Net.Router::RouterNode h -> Std::Option (Minilib.Net.Router::RouterEntry h)`

Finds the entry in the node following the path from the current node.

#### show

Type: `[h : Std::ToString] Std::String -> Minilib.Net.Router::RouterNode h -> Std::IO ()`

TODO: use Writer monad

#### update

Type: `Std::Iterator::DynIterator Std::String -> (Minilib.Net.Router::RouterEntry h -> Minilib.Net.Router::RouterEntry h) -> Minilib.Net.Router::RouterNode h -> Minilib.Net.Router::RouterNode h`

`current_node.update(path, entry_updater)` updates the entry of a target node that is reached via `path` from `current_node`.
`path` is a path from `current_node` to the target node. If `path` is an empty iterator, `current_node` becomes the target node.
`entry_updater` is a function that updates the `RouterEntry` of the target node.

## Types and aliases

### namespace Minilib.Net.Router

#### Router

Defined as: `type Router h = box struct { ...fields... }`

Router is a mapping from a method name and a path to a request handler.
`h` is a type of request handler.

##### field `root`

Type: `Minilib.Net.Router::RouterNode h`

#### RouterEntry

Defined as: `type RouterEntry h = box struct { ...fields... }`

`RouterEntry h` represents a map from method name to a request handler.
`h` is a type of request handler.

##### field `map`

Type: `HashMap::HashMap Std::String h`

#### RouterNode

Defined as: `type RouterNode h = box struct { ...fields... }`

`RouterNode h` represents a resource of URI.
`h` is a type of request handler.

##### field `directory`

Type: `HashMap::HashMap Std::String (Minilib.Net.Router::RouterNode h)`

##### field `entry`

Type: `Minilib.Net.Router::RouterEntry h`

## Traits and aliases

## Trait implementations

### impl `[h : Std::ToString] Minilib.Net.Router::RouterEntry h : Std::ToString`