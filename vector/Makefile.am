AM_CFLAGS = -Wall      \
			-Wextra    \
			-Werror    \
			-std=c99   \
			-pedantic  \
			-fPIC      \
			-fvisibility=hidden

include_HEADERS = \
					vector.h

lib_LTLIBRARIES = libvector.la
libvector_la_SOURCES = \
					vector.c

check_LDADD = $(lib_LTLIBRARIES)
check_PROGRAMS = \
				 tests/template

test_template_LDADD = $(check_LDADD)

TESTS = $(check_PROGRAMS)
