AM_CFLAGS = -Wall      \
			-Wextra    \
			-Werror    \
			-std=c99   \
			-pedantic  \
			-fPIC      \
			-fvisibility=hidden

include_HEADERS = \
					map.h

lib_LTLIBRARIES = libmap.la
libmap_la_SOURCES = \
					map.c

check_LDADD = $(lib_LTLIBRARIES)
check_CFLAGS = -g3 -O0
check_PROGRAMS = \
				 tests/template \
				 tests/init_normal \
				 tests/init_null \
				 tests/add_first_in_list \
				 tests/add_middle_in_list \
				 tests/add_second_in_list \
				 tests/add_already_existing \
				 tests/get_only_in_list \
				 tests/get_first_in_list \
				 tests/get_last_in_list \
				 tests/get_middle_in_list \
				 tests/get_non_existant \
				 tests/remove_first_in_list \
				 tests/remove_last_in_list \
				 tests/remove_middle_in_list \
				 tests/remove_non_existant \
				 tests/remove_only_in_list \
				 tests/destroy_all_empty \
				 tests/destroy_first_in_list \
				 tests/destroy_last_in_list \
				 tests/destroy_middle_in_list

TESTS = $(check_PROGRAMS)

# Template

# map_init
tests_template_LDADD = $(check_LDADD)
tests_init_null_LDADD = $(check_LDADD)
tests_init_normal_LDADD = $(check_LDADD)

# map_add
tests_add_first_in_list_LDADD = $(check_LDADD)
tests_add_already_existing_LDADD = $(check_LDADD)
tests_add_middle_in_list_LDADD = $(check_LDADD)
tests_add_second_in_list_LDADD = $(check_LDADD)

# map_get
tests_get_first_in_list_LDADD = $(check_LDADD)
tests_get_last_in_list_LDADD = $(check_LDADD)
tests_get_middle_in_list_LDADD = $(check_LDADD)
tests_get_non_existant_LDADD = $(check_LDADD)
tests_get_only_in_list_LDADD = $(check_LDADD)

# map_remove
tests_remove_first_in_list_LDADD = $(check_LDADD)
tests_remove_last_in_list_LDADD = $(check_LDADD)
tests_remove_middle_in_list_LDADD = $(check_LDADD)
tests_remove_non_existant_LDADD = $(check_LDADD)
tests_remove_only_in_list_LDADD = $(check_LDADD)

# map_destroy
tests_destroy_all_empty_LDADD = $(check_LDADD)
tests_destroy_first_in_list_LDADD = $(check_LDADD)
tests_destroy_last_in_list_LDADD = $(check_LDADD)
tests_destroy_middle_in_list_LDADD = $(check_LDADD)
