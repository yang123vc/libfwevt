/*
 * Library provider type testing program
 *
 * Copyright (C) 2011-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fwevt_test_libcerror.h"
#include "fwevt_test_libfwevt.h"
#include "fwevt_test_macros.h"
#include "fwevt_test_memory.h"
#include "fwevt_test_unused.h"

#ifdef TODO

/* Tests the libfwevt_provider_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_provider_initialize(
     void )
{
	libcerror_error_t *error      = NULL;
	libfwevt_provider_t *provider = NULL;
	int result                    = 0;

	/* Test libfwevt_provider_initialize
	 */
	result = libfwevt_provider_initialize(
	          &provider,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWEVT_TEST_ASSERT_IS_NOT_NULL(
         "provider",
         provider );

        FWEVT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwevt_provider_free(
	          &provider,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWEVT_TEST_ASSERT_IS_NULL(
         "provider",
         provider );

        FWEVT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwevt_provider_initialize(
	          NULL,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWEVT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	provider = (libfwevt_provider_t *) 0x12345678UL;

	result = libfwevt_provider_initialize(
	          &provider,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWEVT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	provider = NULL;

#if defined( HAVE_FWEVT_TEST_MEMORY )

	/* Test libfwevt_provider_initialize with malloc failing
	 */
	fwevt_test_malloc_attempts_before_fail = 0;

	result = libfwevt_provider_initialize(
	          &provider,
	          &error );

	if( fwevt_test_malloc_attempts_before_fail != -1 )
	{
		fwevt_test_malloc_attempts_before_fail = -1;

		if( provider != NULL )
		{
			libfwevt_provider_free(
			 &provider,
			 NULL );
		}
	}
	else
	{
		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NULL(
		 "provider",
		 provider );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libfwevt_provider_initialize with memset failing
	 */
	fwevt_test_memset_attempts_before_fail = 0;

	result = libfwevt_provider_initialize(
	          &provider,
	          &error );

	if( fwevt_test_memset_attempts_before_fail != -1 )
	{
		fwevt_test_memset_attempts_before_fail = -1;

		if( provider != NULL )
		{
			libfwevt_provider_free(
			 &provider,
			 NULL );
		}
	}
	else
	{
		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NULL(
		 "provider",
		 provider );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FWEVT_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( provider != NULL )
	{
		libfwevt_provider_free(
		 &provider,
		 NULL );
	}
	return( 0 );
}

#endif /* TODO */

/* Tests the libfwevt_provider_free function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_provider_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwevt_provider_free(
	          NULL,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FWEVT_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FWEVT_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FWEVT_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FWEVT_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FWEVT_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FWEVT_TEST_UNREFERENCED_PARAMETER( argc )
	FWEVT_TEST_UNREFERENCED_PARAMETER( argv )

#ifdef TODO
	FWEVT_TEST_RUN(
	 "libfwevt_provider_initialize",
	 fwevt_test_provider_initialize );
#endif

	FWEVT_TEST_RUN(
	 "libfwevt_provider_free",
	 fwevt_test_provider_free );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

