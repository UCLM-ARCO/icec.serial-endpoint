/* -*- mode: c; coding: utf-8 -*- */

#ifndef _ICEC_SERIAL_ENDPOINT_H_
#define _ICEC_SERIAL_ENDPOINT_H_

#include <IceC/IceC.h>

#ifdef __cplusplus
extern "C" {
#endif

#define Ice_EndpointTypeSerial 12

bool IceC_Serial_getProtocolType(const char* proto, Ice_EndpointType* result);
bool IceC_Serial_InputStream_init(Ice_InputStreamPtr self, int fd, Ice_EndpointType type);
bool IceC_Serial_ObjectAdapter_activate(Ice_ObjectAdapterPtr self);
bool IceC_Serial_EndpointInfo_init(Ice_EndpointInfoPtr self,
				 Ice_EndpointType type,
				 const char* endpoint);

bool IceC_Serial_ObjectPrx_connect(Ice_ObjectPrxPtr self);
bool IceC_Serial_ObjectPrx_init(Ice_ObjectPrxPtr self,
			      Ice_EndpointType type,
			      const char* strprx);

bool IceC_Serial_Connection_send(Ice_ConnectionPtr self, int fd, byte* data,
				 uint16_t* size);

/* plugin specific functions */
void IceC_Serial_init(Ice_CommunicatorPtr ic);

#ifdef __cplusplus
}
#endif

#endif /* _ICEC_SERIAL_ENDPOINT_H_ */
