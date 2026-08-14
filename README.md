# rapidxml - XML DOM-style parser C++ library

This is a `build2` package repository for
[RapidXml](http://rapidxml.sourceforge.net/), a header-only XML DOM-style
parser for C++.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`rapidxml` in your `build2`-based project, then instead see the accompanying
[`librapidxml/PACKAGE-README.md`](librapidxml/PACKAGE-README.md) file.

The development setup for `rapidxml` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules https://github.com/build2-packaging/rapidxml.git
cd rapidxml

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
