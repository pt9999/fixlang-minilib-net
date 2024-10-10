# `module Minilib.Net.HTML`

Simple HTML DOM model, as well as escaping/unescaping HTML special characters.

# Types and aliases

## `namespace Minilib.Net.HTML`

### `type HTMLAttribute = (Std::String, Std::String)`

A type that represents name and value of an attribute.

### `type HTMLDocument = unbox struct { ...fields... }`

A type that represents an HTML document.

#### field `html : Minilib.Net.HTML::HTMLElement`

### `type HTMLElement = unbox struct { ...fields... }`

A type that represents an HTML element.

#### field `tag : Std::String`

#### field `attrs : Std::Iterator (Std::String, Std::String)`

#### field `children : Std::Array Minilib.Net.HTML::HTMLNode`

### `type HTMLNode = box union { ...variants... }`

A type that represents an HTML node.

#### variant `element : Minilib.Net.HTML::HTMLElement`

#### variant `text_node : Std::String`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Net.HTML::HTML`

### `body : Minilib.Net.HTML::HTMLElement`

An empty `<body>` element.

### `button : Minilib.Net.HTML::HTMLElement`

An empty `<button>` element.

### `div : Minilib.Net.HTML::HTMLElement`

An empty `<div>` element.

### `div_ : Minilib.Net.HTML::HTMLElement`

to avoid ambiguity with Std::Div::div

### `h1 : Minilib.Net.HTML::HTMLElement`

An empty `<h1>` element.

### `h2 : Minilib.Net.HTML::HTMLElement`

An empty `<h2>` element.

### `h3 : Minilib.Net.HTML::HTMLElement`

An empty `<h3>` element.

### `h4 : Minilib.Net.HTML::HTMLElement`

An empty `<h4>` element.

### `h5 : Minilib.Net.HTML::HTMLElement`

An empty `<h5>` element.

### `head : Minilib.Net.HTML::HTMLElement`

An empty `<head>` element.

### `html : Minilib.Net.HTML::HTMLDocument`

An empty HTML document.

### `input : Minilib.Net.HTML::HTMLElement`

An empty `<input>` element.

### `meta : Minilib.Net.HTML::HTMLElement`

An empty `<meta>` element.

### `p : Minilib.Net.HTML::HTMLElement`

An empty `<p>` element.

### `script : Minilib.Net.HTML::HTMLElement`

An empty `<script>` element.

### `span : Minilib.Net.HTML::HTMLElement`

An empty `<span>` element.

### `table : Minilib.Net.HTML::HTMLElement`

An empty `<table>` element.

### `td : Minilib.Net.HTML::HTMLElement`

An empty `<td>` element.

### `th : Minilib.Net.HTML::HTMLElement`

An empty `<th>` element.

### `title : Minilib.Net.HTML::HTMLElement`

An empty `<title>` element.

### `tr : Minilib.Net.HTML::HTMLElement`

An empty `<tr>` element.

## `namespace Minilib.Net.HTML::HTMLAttribute`

### `_output_html : Std::Array Std::String -> Std::Iterator (Std::String, Std::String) -> Std::Array Std::String`

`attrs._output_html` output the attributes as HTML string.

## `namespace Minilib.Net.HTML::HTMLDocument`

### `@html : Minilib.Net.HTML::HTMLDocument -> Minilib.Net.HTML::HTMLElement`

Retrieves the field `html` from a value of `HTMLDocument`.

### `act_html : [f : Std::Functor] (Minilib.Net.HTML::HTMLElement -> f Minilib.Net.HTML::HTMLElement) -> Minilib.Net.HTML::HTMLDocument -> f Minilib.Net.HTML::HTMLDocument`

Updates a value of `HTMLDocument` by applying a functorial action to field `html`.

### `add : Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLDocument -> Minilib.Net.HTML::HTMLDocument`

Adds a child element to `<html>` element.

### `empty : Minilib.Net.HTML::HTMLDocument`

An empty HTML document.

### `mod_html : (Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement) -> Minilib.Net.HTML::HTMLDocument -> Minilib.Net.HTML::HTMLDocument`

Updates a value of `HTMLDocument` by applying a function to field `html`.

### `set_html : Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLDocument -> Minilib.Net.HTML::HTMLDocument`

Updates a value of `HTMLDocument` by setting field `html` to a specified one.

### `to_html : Minilib.Net.HTML::HTMLDocument -> Std::String`

Converts the HTML document to HTML string.

## `namespace Minilib.Net.HTML::HTMLElement`

### `@attrs : Minilib.Net.HTML::HTMLElement -> Std::Iterator (Std::String, Std::String)`

Retrieves the field `attrs` from a value of `HTMLElement`.

### `@children : Minilib.Net.HTML::HTMLElement -> Std::Array Minilib.Net.HTML::HTMLNode`

Retrieves the field `children` from a value of `HTMLElement`.

### `@tag : Minilib.Net.HTML::HTMLElement -> Std::String`

Retrieves the field `tag` from a value of `HTMLElement`.

### `_output_html : Std::Array Std::String -> Minilib.Net.HTML::HTMLElement -> Std::Array Std::String`

`el._output_html` output the element as HTML string.

### `act_attrs : [f : Std::Functor] (Std::Iterator (Std::String, Std::String) -> f (Std::Iterator (Std::String, Std::String))) -> Minilib.Net.HTML::HTMLElement -> f Minilib.Net.HTML::HTMLElement`

Updates a value of `HTMLElement` by applying a functorial action to field `attrs`.

### `act_children : [f : Std::Functor] (Std::Array Minilib.Net.HTML::HTMLNode -> f (Std::Array Minilib.Net.HTML::HTMLNode)) -> Minilib.Net.HTML::HTMLElement -> f Minilib.Net.HTML::HTMLElement`

Updates a value of `HTMLElement` by applying a functorial action to field `children`.

### `act_tag : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.Net.HTML::HTMLElement -> f Minilib.Net.HTML::HTMLElement`

Updates a value of `HTMLElement` by applying a functorial action to field `tag`.

### `add : Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

`el.add(child)` adds a child element to `el`.

### `attr : Std::String -> Std::String -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

`el.attr(name,value)` adds an attribute to `el`.
If an attribute of same name exists, it will be removed first.
NOTE: validity of attribute names are not checked.

### `make : Std::String -> Minilib.Net.HTML::HTMLElement`

`HTMLElement::make(tag)` creates an empty element with specified tag name.

### `mod_attrs : (Std::Iterator (Std::String, Std::String) -> Std::Iterator (Std::String, Std::String)) -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

Updates a value of `HTMLElement` by applying a function to field `attrs`.

### `mod_children : (Std::Array Minilib.Net.HTML::HTMLNode -> Std::Array Minilib.Net.HTML::HTMLNode) -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

Updates a value of `HTMLElement` by applying a function to field `children`.

### `mod_tag : (Std::String -> Std::String) -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

Updates a value of `HTMLElement` by applying a function to field `tag`.

### `set_attrs : Std::Iterator (Std::String, Std::String) -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

Updates a value of `HTMLElement` by setting field `attrs` to a specified one.

### `set_children : Std::Array Minilib.Net.HTML::HTMLNode -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

Updates a value of `HTMLElement` by setting field `children` to a specified one.

### `set_tag : Std::String -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

Updates a value of `HTMLElement` by setting field `tag` to a specified one.

### `text : Std::String -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

`el.text(txt)` adds a text node to `el`.

### `to_html : Minilib.Net.HTML::HTMLElement -> Std::String`

`el.to_html` converts the element to HTML string.

## `namespace Minilib.Net.HTML::HTMLHelpers`

### `escape_html : Std::String -> Std::String`

Escapes HTML special characters.
eg. `&` -> `&amp;`, `<` -> `&lt;`, `>` -> `&gt;`, `\"` -> `&quot;`, `'` -> `&#039;`

### `unescape_html : Std::String -> Std::String`

Unescapes HTML special characters.
eg. `&amp;` -> `&`, `&lt;` -> `<`, `&gt;` -> `>`, `&quot;` -> `\"`, `&#039;` -> `'`.
NOTE: Other character references is also converted.

## `namespace Minilib.Net.HTML::HTMLNode`

### `as_element : Minilib.Net.HTML::HTMLNode -> Minilib.Net.HTML::HTMLElement`

Unwraps a union value of `HTMLNode` as the variant `element`.
If the value is not the variant `element`, this function aborts the program.

### `as_text_node : Minilib.Net.HTML::HTMLNode -> Std::String`

Unwraps a union value of `HTMLNode` as the variant `text_node`.
If the value is not the variant `text_node`, this function aborts the program.

### `element : Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLNode`

Constructs a value of union `HTMLNode` taking the variant `element`.

### `is_element : Minilib.Net.HTML::HTMLNode -> Std::Bool`

Checks if a union value of `HTMLNode` is the variant `element`.

### `is_text_node : Minilib.Net.HTML::HTMLNode -> Std::Bool`

Checks if a union value of `HTMLNode` is the variant `text_node`.

### `mod_element : (Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement) -> Minilib.Net.HTML::HTMLNode -> Minilib.Net.HTML::HTMLNode`

Updates a value of union `HTMLNode` by applying a function if it is the variant `element`, or doing nothing otherwise.

### `mod_text_node : (Std::String -> Std::String) -> Minilib.Net.HTML::HTMLNode -> Minilib.Net.HTML::HTMLNode`

Updates a value of union `HTMLNode` by applying a function if it is the variant `text_node`, or doing nothing otherwise.

### `text_node : Std::String -> Minilib.Net.HTML::HTMLNode`

Constructs a value of union `HTMLNode` taking the variant `text_node`.