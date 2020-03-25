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
				 tests/vector_template \
				 tests/vector_new_normal \
				 tests/vector_is_empty_empty \
				 tests/vector_is_empty_not_empty \
				 tests/vector_push_back \
				 tests/vector_push_back_resize \
				 tests/vector_pop_back \
				 tests/vector_pop_back_empty \
				 tests/vector_pop_back_only \
				 tests/vector_push_front \
				 tests/vector_push_front_resize \
				 tests/vector_pop_front_empty \
				 tests/vector_pop_front \
				 tests/vector_pop_front_only \
				 tests/vector_clone_empty \
				 tests/vector_clone_only \
				 tests/vector_clone_full \
				 tests/vector_destroy_empty \
				 tests/vector_destroy_normal \
				 tests/vector_destroy_destructor

tests_template_LDADD = $(check_LDADD)

TESTS = $(check_PROGRAMS)

# new
tests_vector_new_normal_LDADD = $(check_LDADD)

# is_empty
tests_vector_is_empty_empty_LDADD = $(check_LDADD)
tests_vector_is_empty_not_empty_LDADD = $(check_LDADD)

# push_back
tests_vector_push_back_LDADD = $(check_LDADD)
tests_vector_push_back_resize_LDADD = $(check_LDADD)

# pop_back
tests_vector_pop_back_LDADD = $(check_LDADD)
tests_vector_pop_back_empty_LDADD = $(check_LDADD)
tests_vector_pop_back_only_LDADD = $(check_LDADD)

# push_front
tests_vector_push_front_LDADD = $(check_LDADD)
tests_vector_push_front_resize_LDADD = $(check_LDADD)

# pop_front
tests_vector_pop_front_empty_LDADD = $(check_LDADD)
tests_vector_pop_front_LDADD = $(check_LDADD)
tests_vector_pop_front_only_LDADD = $(check_LDADD)

# clone
tests_vector_clone_empty_LDADD = $(check_LDADD)
tests_vector_clone_only_LDADD = $(check_LDADD)
tests_vector_clone_full_LDADD = $(check_LDADD)

# destroy
tests_vector_destroy_empty_LDADD = $(check_LDADD)
tests_vector_destroy_normal_LDADD = $(check_LDADD)
tests_vector_destroy_destructor_LDADD = $(check_LDADD)
