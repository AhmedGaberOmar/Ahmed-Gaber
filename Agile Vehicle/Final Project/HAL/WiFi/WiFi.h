/*
 * WiFi.h
 *
 * Created: 1/30/2019 12:58:04 AM
 *  Author: tasneem samy
 */ 


#ifndef WIFI_H_
#define WIFI_H_

#include "USART.h"
#include <string.h>

#define TIMEOUT 5000

#define TRUE 1
#define FALSE 0


enum CONNECT_STATUS{
	CONNECTED_TO_AP,
	CREATED_TRANSMISSION,
	TRANSMISSION_DISCONNNECTED,
	NOT_CONNECTED_TO_AP,
	CONNECT_UNKNOWN_ERROR
};

enum JOINAP_STATUS {
	WIFI_CONNECTED,
	CONNECTION_TIMEOUT,
	WRONG_PASSWORD,
	NOT_FOUND_TARGET_AP,
	CONNECTION_FAILED,
	JOIN_UNKNOWN_ERROR
};

void WiFi_init(void);
u8 WiFi_initServer(void);
u8 WiFi_initClient(void);
u8* WiFi_checkNearServers(void);
u8* WiFi_readData(void);
u8 WiFi_sendAtCommand(u8* command, u8* expected_response);
u8 WiFi_checkResponse(u8* expectedResponse);
u8 WiFi_checkConnection(void);
u8 WiFi_joinAccessPoint(u8* SSID, u8* pass);
u8 WiFi_start(u8* Domain, u8* Port);
u8 WiFi_send(u8* data);
void WiFi_clearBuffer(void);
void WiFi_reset(void);

#endif /* WIFI_H_ */