#ifndef VMPS_H
#define VMPS_H
/*
 *	vmps.h	Routines to handle VMPS sockets.
 *
 * Version:	$Id: ff4476634eb9a96a8ce1b20cbbd4e58ae35784b7 $
 *
 */

#include <freeradius/ident.h>
RCSIDH(vmps_h, "$Id: ff4476634eb9a96a8ce1b20cbbd4e58ae35784b7 $")

#ifdef __cplusplus
extern "C" {
#endif

int vqp_socket_recv(rad_listen_t *listener,
		    RAD_REQUEST_FUNP *pfun, REQUEST **prequest);
int vqp_socket_send(rad_listen_t *listener, REQUEST *request);
int vqp_socket_encode(UNUSED rad_listen_t *listener, REQUEST *request);
int vqp_socket_decode(UNUSED rad_listen_t *listener, REQUEST *request);
int vmps_process(REQUEST *request);

#ifdef __cplusplus
}
#endif

#endif /* VMPS_H */
