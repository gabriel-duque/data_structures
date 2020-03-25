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
check_PROGRAMS = \
				 tests/map_template \
				 tests/map_init_normal \
				 tests/map_init_null \
				 tests/map_add_first_in_list \
				 tests/map_add_middle_in_list \
				 tests/map_add_second_in_list \
				 tests/map_add_already_existing \
				 tests/map_get_only_in_list \
				 tests/map_get_first_in_list \
				 tests/map_get_last_in_list \
				 tests/map_get_middle_in_list \
				 tests/map_get_non_existant \
				 tests/map_remove_first_in_list \
				 tests/map_remove_last_in_list \
				 tests/map_remove_middle_in_list \
				 tests/map_remove_non_existant \
				 tests/map_remove_only_in_list \
				 tests/map_destroy_all_empty \
				 tests/map_destroy_first_in_list \
				 tests/map_destroy_last_in_list

TESTS = $(check_PROGRAMS)

# Template

# map_init
tests_map_template_LDADD = $(check_LDADD)
tests_map_init_null_LDADD = $(check_LDADD)
tests_map_init_normal_LDADD = $(check_LDADD)

# map_add
tests_map_add_first_in_list_LDADD = $(check_LDADD)
tests_map_add_already_existing_LDADD = $(check_LDADD)
tests_map_add_middle_in_list_LDADD = $(check_LDADD)
tests_map_add_second_in_list_LDADD = $(check_LDADD)

# map_get
tests_map_get_first_in_list_LDADD = $(check_LDADD)
tests_map_get_last_in_list_LDADD = $(check_LDADD)
tests_map_get_middle_in_list_LDADD = $(check_LDADD)
tests_map_get_non_existant_LDADD = $(check_LDADD)
tests_map_get_only_in_list_LDADD = $(check_LDADD)

# map_remove
tests_map_remove_first_in_list_LDADD = $(check_LDADD)
tests_map_remove_last_in_list_LDADD = $(check_LDADD)
tests_map_remove_middle_in_list_LDADD = $(check_LDADD)
tests_map_remove_non_existant_LDADD = $(check_LDADD)
tests_map_remove_only_in_list_LDADD = $(check_LDADD)

# map_destroy
tests_map_destroy_all_empty_LDADD = $(check_LDADD)
tests_map_destroy_first_in_list_LDADD = $(check_LDADD)
tests_map_destroy_last_in_list_LDADD = $(check_LDADD)
