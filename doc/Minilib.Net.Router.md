# `module Minilib.Net.Router`

HTTP request router.
- Mounts a request handler to specific path and method
- Finds a request handler from path and method of the HTTP request

# Types and aliases

## `namespace Minilib.Net.Router`

### `type Router h = box struct { ...fields... }`

Router is a mapping from a method name and a path to a request handler.
`h` is a type of request handler.

#### field `root : Minilib.Net.Router::RouterNode h`

### `type RouterEntry h = box struct { ...fields... }`

`RouterEntry h` represents a map from method name to a request handler.
`h` is a type of request handler.

#### field `map : HashMap::HashMap Std::String h`

### `type RouterNode h = box struct { ...fields... }`

`RouterNode h` represents a resource of URI.
`h` is a type of request handler.

#### field `directory : HashMap::HashMap Std::String (Minilib.Net.Router::RouterNode h)`

#### field `entry : Minilib.Net.Router::RouterEntry h`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Net.Router::Router`

### `@root : Minilib.Net.Router::Router h -> Minilib.Net.Router::RouterNode h`

Retrieves the field `root` from a value of `Router`.

### `act_root : [f : Std::Functor] (Minilib.Net.Router::RouterNode h -> f (Minilib.Net.Router::RouterNode h)) -> Minilib.Net.Router::Router h -> f (Minilib.Net.Router::Router h)`

Updates a value of `Router` by applying a functorial action to field `root`.

### `empty : Minilib.Net.Router::Router h`

An empty router.

### `find : Std::String -> Std::String -> Minilib.Net.Router::Router h -> Std::Option h`

`router.find(method, path)` finds the handler that matches `method` and `path`.

### `insert : Std::String -> Std::String -> h -> Minilib.Net.Router::Router h -> Minilib.Net.Router::Router h`

`router.insert(method, path, handler)` tells that `method` and  path
should be mapped to this handler.

### `mod_root : (Minilib.Net.Router::RouterNode h -> Minilib.Net.Router::RouterNode h) -> Minilib.Net.Router::Router h -> Minilib.Net.Router::Router h`

Updates a value of `Router` by applying a function to field `root`.

### `set_root : Minilib.Net.Router::RouterNode h -> Minilib.Net.Router::Router h -> Minilib.Net.Router::Router h`

Updates a value of `Router` by setting field `root` to a specified one.

## `namespace Minilib.Net.Router::RouterEntry`

### `@map : Minilib.Net.Router::RouterEntry h -> HashMap::HashMap Std::String h`

Retrieves the field `map` from a value of `RouterEntry`.

### `act_map : [f : Std::Functor] (HashMap::HashMap Std::String h -> f (HashMap::HashMap Std::String h)) -> Minilib.Net.Router::RouterEntry h -> f (Minilib.Net.Router::RouterEntry h)`

Updates a value of `RouterEntry` by applying a functorial action to field `map`.

### `empty : Minilib.Net.Router::RouterEntry h`

An empty entry.

### `find : Std::String -> Minilib.Net.Router::RouterEntry h -> Std::Option h`

`router_entry.find(method)` finds the handler of the method.

### `is_empty : Minilib.Net.Router::RouterEntry h -> Std::Bool`

Returns true iff it is an empty entry.

### `mod_map : (HashMap::HashMap Std::String h -> HashMap::HashMap Std::String h) -> Minilib.Net.Router::RouterEntry h -> Minilib.Net.Router::RouterEntry h`

Updates a value of `RouterEntry` by applying a function to field `map`.

### `set_map : HashMap::HashMap Std::String h -> Minilib.Net.Router::RouterEntry h -> Minilib.Net.Router::RouterEntry h`

Updates a value of `RouterEntry` by setting field `map` to a specified one.

### `show : [h : Std::ToString] Minilib.Net.Router::RouterEntry h -> Std::IO ()`

### `update : Std::String -> h -> Minilib.Net.Router::RouterEntry h -> Minilib.Net.Router::RouterEntry h`

`router_entry.update(method, handler)` sets the handler of the method `method` to `handler`.

## `namespace Minilib.Net.Router::RouterNode`

### `@directory : Minilib.Net.Router::RouterNode h -> HashMap::HashMap Std::String (Minilib.Net.Router::RouterNode h)`

Retrieves the field `directory` from a value of `RouterNode`.

### `@entry : Minilib.Net.Router::RouterNode h -> Minilib.Net.Router::RouterEntry h`

Retrieves the field `entry` from a value of `RouterNode`.

### `act_directory : [f : Std::Functor] (HashMap::HashMap Std::String (Minilib.Net.Router::RouterNode h) -> f (HashMap::HashMap Std::String (Minilib.Net.Router::RouterNode h))) -> Minilib.Net.Router::RouterNode h -> f (Minilib.Net.Router::RouterNode h)`

Updates a value of `RouterNode` by applying a functorial action to field `directory`.

### `act_entry : [f : Std::Functor] (Minilib.Net.Router::RouterEntry h -> f (Minilib.Net.Router::RouterEntry h)) -> Minilib.Net.Router::RouterNode h -> f (Minilib.Net.Router::RouterNode h)`

Updates a value of `RouterNode` by applying a functorial action to field `entry`.

### `create : Std::Iterator Std::String -> (Minilib.Net.Router::RouterEntry h -> Minilib.Net.Router::RouterEntry h) -> Minilib.Net.Router::RouterNode h`

`RouterNode::create(path, entry_updater)` creates a node.

### `empty : Minilib.Net.Router::RouterNode h`

An empty router node.

### `find : Std::Iterator Std::String -> Minilib.Net.Router::RouterNode h -> Std::Option (Minilib.Net.Router::RouterEntry h)`

Finds the entry in the node following the path from the current node.

### `mod_directory : (HashMap::HashMap Std::String (Minilib.Net.Router::RouterNode h) -> HashMap::HashMap Std::String (Minilib.Net.Router::RouterNode h)) -> Minilib.Net.Router::RouterNode h -> Minilib.Net.Router::RouterNode h`

Updates a value of `RouterNode` by applying a function to field `directory`.

### `mod_entry : (Minilib.Net.Router::RouterEntry h -> Minilib.Net.Router::RouterEntry h) -> Minilib.Net.Router::RouterNode h -> Minilib.Net.Router::RouterNode h`

Updates a value of `RouterNode` by applying a function to field `entry`.

### `set_directory : HashMap::HashMap Std::String (Minilib.Net.Router::RouterNode h) -> Minilib.Net.Router::RouterNode h -> Minilib.Net.Router::RouterNode h`

Updates a value of `RouterNode` by setting field `directory` to a specified one.

### `set_entry : Minilib.Net.Router::RouterEntry h -> Minilib.Net.Router::RouterNode h -> Minilib.Net.Router::RouterNode h`

Updates a value of `RouterNode` by setting field `entry` to a specified one.

### `show : [h : Std::ToString] Std::String -> Minilib.Net.Router::RouterNode h -> Std::IO ()`

### `update : Std::Iterator Std::String -> (Minilib.Net.Router::RouterEntry h -> Minilib.Net.Router::RouterEntry h) -> Minilib.Net.Router::RouterNode h -> Minilib.Net.Router::RouterNode h`

`current_node.update(path, entry_updater)` updates the entry of a target node that is reached via `path` from `current_node`.
`path` is a path from `current_node` to the target node. If `path` is an empty iterator, `current_node` becomes the target node.
`entry_updater` is a function that updates the `RouterEntry` of the target node.