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

### `add : Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLDocument -> Minilib.Net.HTML::HTMLDocument`

Adds a child element to `<html>` element.

### `empty : Minilib.Net.HTML::HTMLDocument`

An empty HTML document.

### `to_html : Minilib.Net.HTML::HTMLDocument -> Std::String`

Converts the HTML document to HTML string.

## `namespace Minilib.Net.HTML::HTMLElement`

### `_output_html : Std::Array Std::String -> Minilib.Net.HTML::HTMLElement -> Std::Array Std::String`

`el._output_html` output the element as HTML string.

### `add : Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

`el.add(child)` adds a child element to `el`.

### `attr : Std::String -> Std::String -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

`el.attr(name,value)` adds an attribute to `el`.
If an attribute of same name exists, it will be removed first.
NOTE: validity of attribute names are not checked.

### `make : Std::String -> Minilib.Net.HTML::HTMLElement`

`HTMLElement::make(tag)` creates an empty element with specified tag name.

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