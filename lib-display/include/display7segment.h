/**
 * @file display7segment.h
 *
 */
/* Copyright (C) 2019 by Arjan van Vught mailto:info@orangepi-dmx.nl
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef DISPLAY7SEGMENT_H_
#define DISPLAY7SEGMENT_H_

enum TDisplay7SegmentCharacters {
  	DISPLAY_7SEGMENT_0 = 0x3F,		// 0b00111111
	DISPLAY_7SEGMENT_1 = 0x06,		// 0b00000110
	DISPLAY_7SEGMENT_2 = 0x5B,		// 0b01011011
	DISPLAY_7SEGMENT_3 = 0x4F,		// 0b01001111
	DISPLAY_7SEGMENT_4 = 0x66,		// 0b01100110
	DISPLAY_7SEGMENT_5 = 0x6D,		// 0b01101101
	DISPLAY_7SEGMENT_6 = 0x7D,		// 0b01111101
	DISPLAY_7SEGMENT_7 = 0x07,		// 0b00000111
	DISPLAY_7SEGMENT_8 = 0x7F,		// 0b01111111
	DISPLAY_7SEGMENT_9 = 0x6F,		// 0b01101111
	DISPLAY_7SEGMENT_A = 0x77,		// 0b01110111
	DISPLAY_7SEGMENT_B = 0x7C,		// 0b01111100
	DISPLAY_7SEGMENT_C = 0x39,		// 0b00111001
	DISPLAY_7SEGMENT_D = 0x5E,		// 0b01011110
	DISPLAY_7SEGMENT_E = 0x79,		// 0b01111001
	DISPLAY_7SEGMENT_F = 0x71,		// 0b01110001
	DISPLAY_7SEGMENT_P = 0x73,		// 0b01110011
	DISPLAY_7SEGMENT_MIN = 0x40,	// 0b01000000
	DISPLAY_7SEGMENT_DP = 0x80,		// 0b10000000
	DISPLAY_7SEGMENT_BLANK = 0x00	// 0b00000000
};

#define DISPLAY_7SEGMENT(x, y)		(((y) << 8) | (x))

enum TDisplay7SegmentMessages {
	// Generic Digits
	DISPLAY_7SEGMENT_MSG_GENERIC_0 = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_0, DISPLAY_7SEGMENT_BLANK),
	DISPLAY_7SEGMENT_MSG_GENERIC_1 = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_1, DISPLAY_7SEGMENT_BLANK),
	DISPLAY_7SEGMENT_MSG_GENERIC_2 = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_2, DISPLAY_7SEGMENT_BLANK),
	DISPLAY_7SEGMENT_MSG_GENERIC_3 = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_3, DISPLAY_7SEGMENT_BLANK),
	DISPLAY_7SEGMENT_MSG_GENERIC_4 = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_4, DISPLAY_7SEGMENT_BLANK),
	DISPLAY_7SEGMENT_MSG_GENERIC_5 = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_5, DISPLAY_7SEGMENT_BLANK),
	DISPLAY_7SEGMENT_MSG_GENERIC_6 = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_6, DISPLAY_7SEGMENT_BLANK),
	DISPLAY_7SEGMENT_MSG_GENERIC_7 = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_7, DISPLAY_7SEGMENT_BLANK),
	DISPLAY_7SEGMENT_MSG_GENERIC_8 = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_8, DISPLAY_7SEGMENT_BLANK),
	DISPLAY_7SEGMENT_MSG_GENERIC_9 = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_9, DISPLAY_7SEGMENT_BLANK),
	// Startup messages
	DISPLAY_7SEGMENT_MSG_INFO_STARTUP = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_BLANK, DISPLAY_7SEGMENT_0),
	DISPLAY_7SEGMENT_MSG_INFO_NETWORK_INIT = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_BLANK, DISPLAY_7SEGMENT_1),
	DISPLAY_7SEGMENT_MSG_INFO_DHCP = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_BLANK, DISPLAY_7SEGMENT_2),
	DISPLAY_7SEGMENT_MSG_INFO_IP = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_BLANK, DISPLAY_7SEGMENT_3),
	DISPLAY_7SEGMENT_MSG_INFO_NTP = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_BLANK, DISPLAY_7SEGMENT_4),
	DISPLAY_7SEGMENT_MSG_INFO_SPARKFUN = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_BLANK, DISPLAY_7SEGMENT_5),
	//
	DISPLAY_7SEGMENT_MSG_INFO_NODE_PARMAMS = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_BLANK, DISPLAY_7SEGMENT_4),
	DISPLAY_7SEGMENT_MSG_INFO_BRIDGE_PARMAMS = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_BLANK, DISPLAY_7SEGMENT_4),
	DISPLAY_7SEGMENT_MSG_INFO_OSCCLIENT_PARMAMS = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_BLANK, DISPLAY_7SEGMENT_4),
	//
	DISPLAY_7SEGMENT_MSG_INFO_RDM_RUN = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_BLANK, DISPLAY_7SEGMENT_5),
	DISPLAY_7SEGMENT_MSG_INFO_NODE_START = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_BLANK, DISPLAY_7SEGMENT_6),
	DISPLAY_7SEGMENT_MSG_INFO_BRIDGE_START = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_BLANK, DISPLAY_7SEGMENT_6),
	DISPLAY_7SEGMENT_MSG_INFO_OSCCLIENT_START = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_BLANK, DISPLAY_7SEGMENT_6),
	//
	DISPLAY_7SEGMENT_MSG_INFO_NONE = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_DP, DISPLAY_7SEGMENT_DP),
	DISPLAY_7SEGMENT_MSG_INFO_NODE_STARTED = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_DP, DISPLAY_7SEGMENT_DP),
	DISPLAY_7SEGMENT_MSG_INFO_BRIDGE_STARTED = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_DP, DISPLAY_7SEGMENT_DP),
	DISPLAY_7SEGMENT_MSG_INFO_OSCCLIENT_STARTED = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_DP, DISPLAY_7SEGMENT_DP),
	// SPI Flash messages
	DISPLAY_7SEGMENT_MSG_INFO_SPI_NONE = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_C, DISPLAY_7SEGMENT_MIN),
	DISPLAY_7SEGMENT_MSG_INFO_SPI_CHECK = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_C, DISPLAY_7SEGMENT_0),
	DISPLAY_7SEGMENT_MSG_INFO_SPI_ERASE = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_C, DISPLAY_7SEGMENT_1),
	DISPLAY_7SEGMENT_MSG_INFO_SPI_WRITING = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_C, DISPLAY_7SEGMENT_2),
	DISPLAY_7SEGMENT_MSG_INFO_SPI_NODIFF = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_C, DISPLAY_7SEGMENT_3),
	DISPLAY_7SEGMENT_MSG_INFO_SPI_DONE = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_C, DISPLAY_7SEGMENT_C),
	DISPLAY_7SEGMENT_MSG_INFO_SPI_UPDATE = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_C, DISPLAY_7SEGMENT_F),
	// Firmware TFTP messages
	DISPLAY_7SEGMENT_MSG_INFO_TFTP_ON = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_F, DISPLAY_7SEGMENT_MIN),
	DISPLAY_7SEGMENT_MSG_INFO_TFTP_STARTED = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_F, DISPLAY_7SEGMENT_1),
	DISPLAY_7SEGMENT_MSG_INFO_TFTP_ENDED = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_F, DISPLAY_7SEGMENT_2),
	DISPLAY_7SEGMENT_MSG_INFO_TFTP_OFF = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_F, DISPLAY_7SEGMENT_DP),
	// Informational / Warning messages
	DISPLAY_7SEGMENT_MSG_INFO_REBOOTING = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_MIN, DISPLAY_7SEGMENT_MIN),
	DISPLAY_7SEGMENT_MSG_INFO_DATALOSS =  DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_D, DISPLAY_7SEGMENT_MIN),
	// Error messages
	DISPLAY_7SEGMENT_MSG_ERROR_DHCP = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_E, DISPLAY_7SEGMENT_2),
	DISPLAY_7SEGMENT_MSG_ERROR_NTP = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_E, DISPLAY_7SEGMENT_4),
	DISPLAY_7SEGMENT_MSG_ERROR_SPARKFUN = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_E, DISPLAY_7SEGMENT_5),
	DISPLAY_7SEGMENT_MSG_ERROR_MCP23S017 = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_E, DISPLAY_7SEGMENT_8),
	DISPLAY_7SEGMENT_MSG_ERROR_SI5351A = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_E, DISPLAY_7SEGMENT_9),
	DISPLAY_7SEGMENT_MSG_ERROR_NEXTION = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_E, DISPLAY_7SEGMENT_A),
	DISPLAY_7SEGMENT_MSG_ERROR_SPI = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_E, DISPLAY_7SEGMENT_C),
	DISPLAY_7SEGMENT_MSG_ERROR_FATAL = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_E, DISPLAY_7SEGMENT_E),
	DISPLAY_7SEGMENT_MSG_ERROR_TFTP = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_E, DISPLAY_7SEGMENT_F),
	// LTC messages
	DISPLAY_7SEGMENT_MSG_LTC_WAITING = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_DP, DISPLAY_7SEGMENT_DP),
	DISPLAY_7SEGMENT_MSG_LTC_FILM = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_2, DISPLAY_7SEGMENT_4),
	DISPLAY_7SEGMENT_MSG_LTC_EBU = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_2, DISPLAY_7SEGMENT_5),
	DISPLAY_7SEGMENT_MSG_LTC_DF = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_2, DISPLAY_7SEGMENT_9),
	DISPLAY_7SEGMENT_MSG_LTC_SMPTE = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_3, DISPLAY_7SEGMENT_0),
	// OSC Client messages
	DISPLAY_7SEGMENT_MSG_INFO_OSCCLIENT_PING_PONG = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_P, DISPLAY_7SEGMENT_P),
	DISPLAY_7SEGMENT_MSG_ERROR_OSCCLIENT_PING_PONG = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_P, DISPLAY_7SEGMENT_E),
	// Apple MIDI - rtpMIDI messages
	// TODO Apple MIDI - rtpMIDI messages
	// Show File player
	DISPLAY_7SEGMENT_MSG_INFO_PLAYER_IDLE = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_P, DISPLAY_7SEGMENT_0),
	DISPLAY_7SEGMENT_MSG_INFO_PLAYER_RUNNING = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_P, DISPLAY_7SEGMENT_1),
	DISPLAY_7SEGMENT_MSG_INFO_PLAYER_RUNNING_LOOP = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_P, DISPLAY_7SEGMENT_2),
	DISPLAY_7SEGMENT_MSG_INFO_PLAYER_STOPPED = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_P, DISPLAY_7SEGMENT_3),
	DISPLAY_7SEGMENT_MSG_INFO_PLAYER_STOPPED_LOOP = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_P, DISPLAY_7SEGMENT_4),
	DISPLAY_7SEGMENT_MSG_INFO_PLAYER_ENDED = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_P, DISPLAY_7SEGMENT_9),
	DISPLAY_7SEGMENT_MSG_ERROR_PLAYER = DISPLAY_7SEGMENT(DISPLAY_7SEGMENT_P, DISPLAY_7SEGMENT_E)
};

#endif /* DISPLAY7SEGMENT_H_ */
