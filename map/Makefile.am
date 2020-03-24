AM_CPPFLAGS = -D_GNU_SOURCE

AM_CFLAGS = -Wall      \
			-Wextra    \
			-Werror    \
			-std=gnu99 \
			-pedantic  \
			-fPIC      \
			-fvisibility=hidden


lib_LTLIBRARIES = libmap.la
libmap_la_SOURCES = \
					map.c

check_LDADD = $(lib_LTLIBRARIES)
check_PROGRAMS = \
				 tests/simple

tests_simple_LDADD = $(check_LDADD)

TESTS = $(check_PROGRAMS)
