# regex

General format:

`/character-set/flags`

## Character classes

> Use brackets to create capture groups, helpful for logical operator `|`. `&` is implicit.

`.` : Match all characters except newlines. Also see the `/s` flag.

`\w` : Any word. Same as `[A-Za-z0-9_]`.

`\W` : Opposite of `\w`.

`\d` : Any digit. Same as `[0-9]`.

`\D` : Opposite of `\d`.

`\s` : Matches a witespace.

`\S` : Match anything that is not a whitespace. Used in conjunction with `\s` to match anything, inculding line breaks.

`[]` : Character set. Used to choose any of the characters in the bracket. A range can be specified with a `-` in between two characters. Eg: `[A-Z]`

`[^]` : Negated character set. *DO NOT* match any of the letters inside.

`()` : Capture group. 

## Anchors and Quantifiers

`^` : Beginning of the text. See also the `/m` flag.

`$` : Matches the end of the text.

`*` : Match 0 or more of the preceding token.

`+` : Match 1 or more of the preceding token.

`?` : Make the previous token optional.

`+?`/`*?` : Make the search lazy. This matches as few characters as possible. 

`|` : Boolean `OR`. Match the expression before or after.

## Flags

Flags can be one of the following:

- global - `/g`
- case insensitive - `/i`
- multiline `/m`

Multiline makes the anchors catch all lines instead of the string beginning and ending.

- unicode `/u`

When the unicode flag is enabled, you can use extended unicode escapes in the form `\x{FFFFF}`.

- sticky `/y`

Undo the global flag.

- dotall `/s`

Dot (`.`) will match newlines as well.

The flags can be combined. Eg: `/ms`
