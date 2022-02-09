/*
 * WiFi.c
 *
 * Created: 1/30/2019 12:57:49 AM
 *  Author: tasneem samy
 */ 

#include "WiFi.h"

void WiFi_init(void){
	USART0_Init(F_CPU/16/9600-1);
	DDRG |= (1<<4);
	PORTG |=(1<<4);
}

u8 WiFi_initServer(void){
	if(!WiFi_sendAtCommand("AT+CWMODE=2\r\n", "OK"))
		return FALSE;
	WiFi_sendAtCommand("AT+CIPMUX=1\r\n", "OK");
	if(!WiFi_sendAtCommand("AT+CIPSERVER=1\r\n", "OK"))
		return FALSE;
	return TRUE;
}

u8 WiFi_initClient(void){
	if(!WiFi_sendAtCommand("AT+CWMODE=1\r\n", "OK"))
		return FALSE;
	u8* ap = WiFi_checkNearServers();
	if(ap){
		if(WiFi_joinAccessPoint(ap, "") == WIFI_CONNECTED){
				if(WiFi_start("192.168.4.1", "333"))
					return TRUE;	
		}
	}
	return FALSE;
}

u8* WiFi_checkNearServers(void){
	if(!WiFi_sendAtCommand("AT+CWLAP\r\n", "OK"))
		return FALSE;
				
	u8* APs = USART0_readResponse();
	u8* ap = strtok(APs, "\r\n");	
	u8* ser = ap;
	u8 found = 0;
	
	while(ap){	
		ser = strstr(ap, "+CWLAP:(0,\"AI-THINKER_");
		if(ser){
			found = 1;
			break;
		}
		ap = strtok(0, "\r\n");
	}
	
	if(found == 1){
		ser = strtok(ser, ",");
		ser = strtok(0, ",");
		ser = strtok(ser, "\"");
		return ser;
	}
	return FALSE;	
}

u8* WiFi_readData(void){
	u8* msg = USART0_readResponse();
	if(strstr(msg, "+IPD")){
		msg = strtok(msg, ",");
		msg = strtok(0, ",");
		msg = strtok(msg, ":");
		s32 size = atoi(msg);
		msg = strtok(0, ":");
		memcpy(msg, msg, size);
		msg[size] = '\0';
		return msg;
	}
	return FALSE;
}

u8 WiFi_sendAtCommand(u8* command, u8* expected_response){
	USART0_clearResponse();
	USART0_TransmitStr(command);
	return WiFi_checkResponse(expected_response);
}

u8 WiFi_checkResponse(u8* expectedResponse){
	s32 timecount = 0;
	while(1){
		if(timecount>=TIMEOUT)
		return FALSE;
		if(strstr(USART0_readResponse(), expectedResponse))
		return TRUE;
		_delay_ms(1);
		timecount += 1;
	}
	return FALSE;
}

u8 WiFi_checkConnection(void){
	WiFi_sendAtCommand("AT+CIPSTATUS\r\n", "OK");
	if(strstr(USART0_readResponse(), "STATUS:2"))
		return CONNECTED_TO_AP;
	if(strstr(USART0_readResponse(), "STATUS:3"))
		return CREATED_TRANSMISSION;
	if(strstr(USART0_readResponse(), "STATUS:4"))
		return TRANSMISSION_DISCONNNECTED;
	if(strstr(USART0_readResponse(), "STATUS:5"))
		return NOT_CONNECTED_TO_AP;
	return CONNECT_UNKNOWN_ERROR;
}

u8 WiFi_joinAccessPoint(u8* SSID, u8* pass){
	u8 atCommand[60];
	memset(atCommand, 0, 60);
	sprintf(atCommand, "AT+CWJAP=\"%s\",\"%s\"\r\n", SSID, pass);
	if(WiFi_sendAtCommand(atCommand, "OK")){
		if(strstr(USART0_readResponse(), "WIFI CONNECTED"))
		return WIFI_CONNECTED;
		if(strstr(USART0_readResponse(), "+CWJAP:1"))
		return CONNECTION_TIMEOUT;
		if(strstr(USART0_readResponse(), "+CWJAP:2"))
		return WRONG_PASSWORD;
		if(strstr(USART0_readResponse(), "+CWJAP:3"))
		return NOT_FOUND_TARGET_AP;
		if(strstr(USART0_readResponse(), "+CWJAP:4"))
		return CONNECTION_FAILED;
	}
	return JOIN_UNKNOWN_ERROR;
}

u8 WiFi_start(u8* Domain, u8* Port){
	u8 atCommand[60];
	memset(atCommand, 0, 60);
	sprintf(atCommand, "AT+CIPSTART=\"TCP\",\"%s\",%s\r\n", Domain, Port);
	if(WiFi_sendAtCommand(atCommand, "OK"))
		return TRUE;
	return FALSE;
}

u8 WiFi_send(u8* data){
	u8 atCommand[20]={0};
	u8 len[5]={0};
	sprintf(len, ",%d\r\n", strlen(data));
	s32 link_id;
	u8 error_flag = 0;
	for(link_id=0; link_id<5; link_id++){
		sprintf(atCommand, "AT+CIPSEND=%d", link_id);
		strcat(atCommand, len);
		if(WiFi_sendAtCommand(atCommand, "OK")){
			_delay_ms(50);
			if(!WiFi_sendAtCommand(data, "SEND OK"))
				error_flag += 1;
		}
		else{
			error_flag += 1;
		}
	}
	if(error_flag == 5)
		return FALSE;
	return TRUE;
}

void WiFi_clearBuffer(void){
	USART0_clearResponse();
}

void WiFi_reset(void){
	PORTG &= ~(1<<4);
	_delay_ms(500);
	PORTG |= (1<<4);
}

