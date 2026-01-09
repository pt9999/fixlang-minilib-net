# Minilib.Net.HTML

Defined in minilib-net@0.6.7

Simple HTML DOM model, as well as escaping/unescaping HTML special characters.

## Values

### namespace Minilib.Net.HTML::HTML

#### body

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<body>` element.

#### button

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<button>` element.

#### div

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<div>` element.

#### div_

Type: `Minilib.Net.HTML::HTMLElement`

to avoid ambiguity with Std::Div::div

#### h1

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<h1>` element.

#### h2

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<h2>` element.

#### h3

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<h3>` element.

#### h4

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<h4>` element.

#### h5

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<h5>` element.

#### head

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<head>` element.

#### html

Type: `Minilib.Net.HTML::HTMLDocument`

An empty HTML document.

#### input

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<input>` element.

#### meta

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<meta>` element.

#### p

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<p>` element.

#### script

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<script>` element.

#### span

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<span>` element.

#### table

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<table>` element.

#### td

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<td>` element.

#### th

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<th>` element.

#### title

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<title>` element.

#### tr

Type: `Minilib.Net.HTML::HTMLElement`

An empty `<tr>` element.

### namespace Minilib.Net.HTML::HTMLDocument

#### add

Type: `Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLDocument -> Minilib.Net.HTML::HTMLDocument`

Adds a child element to `<html>` element.

#### empty

Type: `Minilib.Net.HTML::HTMLDocument`

An empty HTML document.

#### to_html

Type: `Minilib.Net.HTML::HTMLDocument -> Std::String`

Converts the HTML document to HTML string.

### namespace Minilib.Net.HTML::HTMLElement

#### add

Type: `Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

`el.add(child)` adds a child element to `el`.

#### attr

Type: `Std::String -> Std::String -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

`el.attr(name,value)` adds an attribute to `el`.
If an attribute of same name exists, it will be removed first.
NOTE: validity of attribute names are not checked.

#### make

Type: `Std::String -> Minilib.Net.HTML::HTMLElement`

`HTMLElement::make(tag)` creates an empty element with specified tag name.

#### text

Type: `Std::String -> Minilib.Net.HTML::HTMLElement -> Minilib.Net.HTML::HTMLElement`

`el.text(txt)` adds a text node to `el`.

#### to_html

Type: `Minilib.Net.HTML::HTMLElement -> Std::String`

`el.to_html` converts the element to HTML string.

### namespace Minilib.Net.HTML::HTMLHelpers

#### escape_html

Type: `Std::String -> Std::String`

Escapes HTML special characters.
eg. `&` -> `&amp;`, `<` -> `&lt;`, `>` -> `&gt;`, `\"` -> `&quot;`, `'` -> `&#039;`

#### unescape_html

Type: `Std::String -> Std::String`

Unescapes HTML special characters.
eg. `&amp;` -> `&`, `&lt;` -> `<`, `&gt;` -> `>`, `&quot;` -> `\"`, `&#039;` -> `'`.
NOTE: Other character references is also converted.

## Types and aliases

### namespace Minilib.Net.HTML

#### HTMLAttribute

Defined as: `type HTMLAttribute = (Std::String, Std::String)`

A type that represents name and value of an attribute.

#### HTMLDocument

Defined as: `type HTMLDocument = unbox struct { ...fields... }`

A type that represents an HTML document.

##### field `html`

Type: `Minilib.Net.HTML::HTMLElement`

#### HTMLElement

Defined as: `type HTMLElement = unbox struct { ...fields... }`

A type that represents an HTML element.

##### field `tag`

Type: `Std::String`

##### field `attrs`

Type: `Std::Iterator::DynIterator Minilib.Net.HTML::HTMLAttribute`

##### field `children`

Type: `Std::Array Minilib.Net.HTML::HTMLNode`

#### HTMLNode

Defined as: `type HTMLNode = box union { ...variants... }`

A type that represents an HTML node.

##### variant `element`

Type: `Minilib.Net.HTML::HTMLElement`

##### variant `text_node`

Type: `Std::String`

## Traits and aliases

## Trait implementations

### impl `Minilib.Net.HTML::HTMLDocument : Std::ToString`

### impl `Minilib.Net.HTML::HTMLElement : Std::ToString`