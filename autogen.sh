#!/bin/sh

set -e

origdir="$(pwd)"
srcdir="$(dirname $0)"

if [ -z "$srcdir" ]
then
    srcdir="."
fi

cd "$srcdir"
autoreconf --force --verbose --install
cd "$origdir"
