/*
 * Event functions
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

#if !defined( _LIBFWEVT_INTERNAL_EVENT_H )
#define _LIBFWEVT_INTERNAL_EVENT_H

#include <common.h>
#include <types.h>

#include "libfwevt_extern.h"
#include "libfwevt_libcerror.h"
#include "libfwevt_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfwevt_internal_event libfwevt_internal_event_t;

struct libfwevt_internal_event
{
	/* The identifier
	 */
	uint16_t identifier;

	/* The message identifier
	 */
	uint32_t message_identifier;

	/* The level offset
	 */
	uint32_t level_offset;

	/* The opcode offset
	 */
	uint32_t opcode_offset;

	/* The taks offset
	 */
	uint32_t task_offset;

	/* The template offset
	 */
	uint32_t template_offset;
};

LIBFWEVT_EXTERN \
int libfwevt_event_initialize(
     libfwevt_event_t **event,
     libcerror_error_t **error );

LIBFWEVT_EXTERN \
int libfwevt_event_free(
     libfwevt_event_t **event,
     libcerror_error_t **error );

LIBFWEVT_EXTERN \
int libfwevt_event_read(
     libfwevt_event_t *event,
     const uint8_t *data,
     size_t data_size,
     size_t data_offset,
     libcerror_error_t **error );

LIBFWEVT_EXTERN \
int libfwevt_event_get_identifier(
     libfwevt_event_t *event,
     uint32_t *identifier,
     libcerror_error_t **error );

LIBFWEVT_EXTERN \
int libfwevt_event_get_message_identifier(
     libfwevt_event_t *event,
     uint32_t *message_identifier,
     libcerror_error_t **error );

LIBFWEVT_EXTERN \
int libfwevt_event_get_template_offset(
     libfwevt_event_t *event,
     uint32_t *template_offset,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

