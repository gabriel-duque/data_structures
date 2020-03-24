AM_CFLAGS = -Wall      \
			-Wextra    \
			-Werror    \
			-std=c99   \
			-pedantic  \
			-fPIC      \
			-fvisibility=hidden


lib_LTLIBRARIES = libmap.la
libmap_la_SOURCES = \
					map.c

check_LDADD = $(lib_LTLIBRARIES)
check_PROGRAMS = \
				 tests/template    \
				 tests/init_normal \
				 tests/init_null

tests_template_LDADD = $(check_LDADD)
tests_init_null_LDADD = $(check_LDADD)
tests_init_normal_LDADD = $(check_LDADD)

TESTS = $(check_PROGRAMS)
