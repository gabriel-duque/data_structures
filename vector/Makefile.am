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
				 tests/template \
				 tests/new_normal \
				 tests/is_empty_empty \
				 tests/is_empty_not_empty \
				 tests/push_back \
				 tests/push_back_resize \
				 tests/pop_back \
				 tests/pop_back_empty \
				 tests/pop_back_only \
				 tests/push_front \
				 tests/push_front_resize \
				 tests/pop_front_empty \
				 tests/pop_front \
				 tests/pop_front_only \
				 tests/clone_empty \
				 tests/clone_only \
				 tests/clone_full \
				 tests/destroy_empty \
				 tests/destroy_normal \
				 tests/destroy_destructor

tests_template_LDADD = $(check_LDADD)

TESTS = $(check_PROGRAMS)

# new
tests_new_normal_LDADD = $(check_LDADD)

# is_empty
tests_is_empty_empty_LDADD = $(check_LDADD)
tests_is_empty_not_empty_LDADD = $(check_LDADD)

# push_back
tests_push_back_LDADD = $(check_LDADD)
tests_push_back_resize_LDADD = $(check_LDADD)

# pop_back
tests_pop_back_LDADD = $(check_LDADD)
tests_pop_back_empty_LDADD = $(check_LDADD)
tests_pop_back_only_LDADD = $(check_LDADD)

# push_front
tests_push_front_LDADD = $(check_LDADD)
tests_push_front_resize_LDADD = $(check_LDADD)

# pop_front
tests_pop_front_empty_LDADD = $(check_LDADD)
tests_pop_front_LDADD = $(check_LDADD)
tests_pop_front_only_LDADD = $(check_LDADD)

# clone
tests_clone_empty_LDADD = $(check_LDADD)
tests_clone_only_LDADD = $(check_LDADD)
tests_clone_full_LDADD = $(check_LDADD)

# destroy
tests_destroy_empty_LDADD = $(check_LDADD)
tests_destroy_normal_LDADD = $(check_LDADD)
tests_destroy_destructor_LDADD = $(check_LDADD)
