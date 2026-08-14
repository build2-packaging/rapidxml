# librapidxml - XML DOM-style parser C++ library

This is a `build2` package for the [RapidXml](http://rapidxml.sourceforge.net/)
C++ library. It provides a header-only XML DOM-style parser with a small API
and a reduced memory footprint.

This package tracks Debian `rapidxml` 1.13-3 (upstream RapidXml 1.13). It
applies Debian's `fix-iterators.patch` and `rapidxml_print.hpp` Clang
forward-declaration patch, and also finishes the iterator fix on
`attribute_iterator` postfix `++`/`--` (`++this` to `++(*this)`), which
Debian's patch left unfixed.


## Usage

To start using `librapidxml` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: librapidxml ^1.13.0
```

Then import the library in your `buildfile`:

```
import libs = librapidxml%lib{rapidxml}
```


## Importable targets

This package provides the following importable targets:

```
lib{rapidxml}
```

This is a binless (header-only) library. Public headers are included as
`<rapidxml/rapidxml.hpp>`, `<rapidxml/rapidxml_print.hpp>`,
`<rapidxml/rapidxml_iterators.hpp>`, and `<rapidxml/rapidxml_utils.hpp>`.


## Configuration variables

This package has no configuration variables.
