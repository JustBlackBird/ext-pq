/*
    +--------------------------------------------------------------------+
    | PECL :: pq                                                         |
    +--------------------------------------------------------------------+
    | Redistribution and use in source and binary forms, with or without |
    | modification, are permitted provided that the conditions mentioned |
    | in the accompanying LICENSE file are met.                          |
    +--------------------------------------------------------------------+
    | Copyright (c) 2013, Michael Wallner <mike@php.net>                |
    +--------------------------------------------------------------------+
*/


#ifndef PHP_PQCONN_EVENT_H
#define PHP_PQCONN_EVENT_H

#include <libpq-events.h>

#include "php_pqconn.h"
#include "php_pqres.h"

typedef struct php_pqconn_event_data {
	php_pqconn_object_t *obj;
	php_pqres_object_t *res;
} php_pqconn_event_data_t;

extern php_pqconn_event_data_t *php_pqconn_event_data_init(php_pqconn_object_t *obj);
extern void php_pqconn_notice_recv(void *p, const PGresult *res);
extern void php_pqconn_notice_ignore(void *p, const PGresult *res);
extern int php_pqconn_event(PGEventId id, void *e, void *data);

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
