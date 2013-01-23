#!/bin/sh
mkdir -p m4
autopoint --force
AUTOPOINT='intltoolize --automake --copy' autoreconf -fiv -Wall || exit
test -n "$NOCONFIGURE" || ./configure --enable-maintainer-mode "$@"
