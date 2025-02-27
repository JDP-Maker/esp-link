#ifndef CONFIG_H
	#define CONFIG_H
	
	// Flash configuration settings. When adding new items always add them at the end and formulate
	// them such that a value of zero is an appropriate default or backwards compatible. Existing
	// modules that are upgraded will have zero in the new fields. This ensures that an upgrade does
	// not wipe out the old settings.
	typedef struct {
		uint32_t seq; // flash write sequence number
		uint16_t magic, crc;
		int8_t   reset_pin, isp_pin, conn_led_pin, ser_led_pin;
		int32_t  baud_rate;
		char     hostname[32];               // if using DHCP
		uint32_t staticip, netmask, gateway; // using DHCP if staticip==0
		uint8_t  log_mode;                   // UART log debug mode
		uint8_t   swap_uart;                  // swap uart0 to gpio 13&15
		uint8_t  tcp_enable, rssi_enable;    // TCP client settings
		char     api_key[48];                // RSSI submission API key (Grovestreams for now)
		uint8_t  slip_enable, mqtt_enable,   // SLIP protocol, MQTT client
		mqtt_status_enable,         // MQTT status reporting
		mqtt_timeout,               // MQTT send timeout
		mqtt_clean_session;         // MQTT clean session
		uint16_t mqtt_port, mqtt_keepalive;  // MQTT Host port, MQTT Keepalive timer
		char     mqtt_old_host[32],          // replaced by 64-char mqtt_host below
		mqtt_clientid[48],
		mqtt_old_username[32],
		mqtt_old_password[32],      // replaced by 70-char mqtt_password below
		mqtt_status_topic[32];
		char     sys_descr[129];             // system description
		int8_t   rx_pullup;                  // internal pull-up on RX pin
		char     sntp_server[32];
		char     syslog_host[32];
		uint16_t syslog_minheap;             // min. heap to allow queuing
	uint8_t  syslog_filter,              // min. severity
	syslog_showtick,            // show system tick (µs)
	syslog_showdate;            // populate SYSLOG date field
	uint8_t  mdns_enable;
	char     mdns_servername[32];
	char     mdns_service_1[32];	//J_D_P add MDNS Sevice options
	char     mdns_service_2[32];	//J_D_P add MDNS Sevice options
	char     mdns_service_3[32];	//J_D_P add MDNS Sevice options
	char     mdns_service_4[32];	//J_D_P add MDNS Sevice options
	char     mdns_service_5[32];	//J_D_P add MDNS Sevice options
	uint16_t mdns_ota_port;			//J_D_P added changeable MDNS OTA port
	int8_t   timezone_offset;
	char     mqtt_host[64];              // MQTT host we connect to, was 32-char mqtt_old_host
	int8_t   data_bits;
	int8_t   parity;
	int8_t   stop_bits;
	char     mqtt_password[70];          // MQTT password, was 32-char mqtt_old_password
	char     mqtt_username[70];          // MQTT username, was 32-char mqtt_old_username
	} FlashConfig;
	extern FlashConfig flashConfig;
	
	bool configSave(void);
	bool configRestore(void);
	void configWipe(void);
	const size_t getFlashSize();
	
	const uint32_t getUserPageSectionStart();
	const uint32_t getUserPageSectionEnd();
	
	#endif
		