#!/bin/sh

set -e

red='\033[0;31m'
green='\033[0;32m'
normal='\033[0m'

ret_value=0

make_files='Makefile map/Makefile vector/Makefile'
libs='libmap.so libvector.so'

srcdir="$(dirname $0)"
origdir="$(pwd)"
test "$srcdir" == "." && srcdir="$origdir"
tmpdir="$(mktemp -d)"

trap "cd $origdir; rm -rf $tmpdir" EXIT

cd "$srcdir"

if ! which valgrind 2>/dev/null >&2
then
    printf "Please install valgrind and add it to your \$PATH\n" >&2
    exit 1
fi

for make_input in $make_files
do
    if ! [ -f $make_input ]
    then
        ./autogen.sh && ./configure
        break
    fi
done

make

cd "$tmpdir"

for lib in $libs
do
    dir="${lib#lib}"
    dir="${dir%.so}"
    testdir="$dir/tests"

    printf "$dir:\n"

    for t in $srcdir/$testdir/*.c
    do
        name="$(basename $t)"
        printf "\t%s: " "${name%.c}"
        cp "$t" .
        gcc -I"$srcdir/$dir" -O0 -g3 "$name" -fsanitize=address -lasan \
            -pthread -L"$srcdir/$dir/.libs" -l$dir -o "${name%.c}"
        set +e
        output=$(LD_LIBRARY_PATH="$srcdir/$dir/.libs" valgrind --leak-check=full ./"${name%.c}" 2>&1 | grep 'lost: [0-9]*[,]*[0-9]* bytes in [0-9]* blocks$')"\n"
        set -e
        printf "$output" | if grep -q 'lost: [0-9]*[,][0-9]* bytes in [^0][0-9]* blocks'; then printf "${red}failed${normal}\n" && printf "$output" && ret_value=1 ; else printf "${green}success${normal}\n" ;fi
    done
done

exit $ret_value
