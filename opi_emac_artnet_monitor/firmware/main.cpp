/**
 * @file main.cpp
 *
 */
/* Copyright (C) 2019-2020 by Arjan van Vught mailto:info@orangepi-dmx.nl
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

#include <stdio.h>
#include <stdint.h>

#include "hardware.h"
#include "networkh3emac.h"
#include "ledblink.h"

#include "h3/showsystime.h"

#include "ntpclient.h"

#include "displayudf.h"
#include "displayudfparams.h"

#include "networkconst.h"

#include "artnet4node.h"
#include "artnet4params.h"
#include "artnetmsgconst.h"

#include "ipprog.h"
#include "timecode.h"
#include "timesync.h"

// Monitor Output
#include "dmxmonitor.h"

#include "firmwareversion.h"
#include "software_version.h"

#include "displayudfhandler.h"
#include "displayhandler.h"

extern "C" {

void notmain(void) {
	Hardware hw;
	NetworkH3emac nw;
	LedBlink lb;
	DisplayUdf display;
	DisplayUdfHandler displayUdfHandler;
	FirmwareVersion fw(SOFTWARE_VERSION, __DATE__, __TIME__);
	ShowSystime showSystime;

	fw.Print();

	console_puts("Ethernet Art-Net 4 Node ");
	console_set_fg_color(CONSOLE_GREEN);
	console_puts("Real-time DMX Monitor");
	console_set_fg_color(CONSOLE_WHITE);
	console_putc('\n');

	hw.SetLed(HARDWARE_LED_ON);
	lb.SetLedBlinkDisplay(new DisplayHandler);

	display.TextStatus(NetworkConst::MSG_NETWORK_INIT, DISPLAY_7SEGMENT_MSG_INFO_NETWORK_INIT, CONSOLE_YELLOW);

	nw.Init();
	nw.SetNetworkDisplay(&displayUdfHandler);
	nw.Print();

	NtpClient ntpClient;
	ntpClient.SetNtpClientDisplay(&displayUdfHandler);
	ntpClient.Init();
	ntpClient.Print();

	display.TextStatus(ArtNetMsgConst::PARAMS, DISPLAY_7SEGMENT_MSG_INFO_NODE_PARMAMS, CONSOLE_YELLOW);

	ArtNet4Node node;
	ArtNet4Params artnetparams;

	if (artnetparams.Load()) {
		artnetparams.Set(&node);
		artnetparams.Dump();
	}

	IpProg ipprog;
	node.SetIpProgHandler(&ipprog);

	TimeCode timecode;
	if (artnetparams.IsUseTimeCode()) {
		timecode.Start();
		node.SetTimeCodeHandler(&timecode);
	}

	TimeSync timesync;
	if (artnetparams.IsUseTimeSync()) {
		node.SetTimeSyncHandler(&timesync);
	}

	node.SetArtNetDisplay(&displayUdfHandler);
	node.SetUniverseSwitch(0, ARTNET_OUTPUT_PORT, artnetparams.GetUniverse());

	DMXMonitor monitor;
	// There is support for HEX output only
	node.SetDirectUpdate(false);
	node.SetOutput(&monitor);
	monitor.Cls();
	console_set_top_row(20);
	node.Print();

	display.SetTitle("Eth Art-Net 4 Monitor");
	display.Set(2, DISPLAY_UDF_LABEL_NODE_NAME);
	display.Set(3, DISPLAY_UDF_LABEL_IP);
	display.Set(4, DISPLAY_UDF_LABEL_VERSION);
	display.Set(5, DISPLAY_UDF_LABEL_UNIVERSE);
	display.Set(6, DISPLAY_UDF_LABEL_AP);

	DisplayUdfParams displayUdfParams;

	if(displayUdfParams.Load()) {
		displayUdfParams.Set(&display);
		displayUdfParams.Dump();
	}

	display.Show(&node);

	display.TextStatus(ArtNetMsgConst::START, DISPLAY_7SEGMENT_MSG_INFO_NODE_START, CONSOLE_YELLOW);

	node.Start();

	display.TextStatus(ArtNetMsgConst::STARTED, DISPLAY_7SEGMENT_MSG_INFO_NODE_STARTED, CONSOLE_GREEN);

	hw.WatchdogInit();

	for (;;) {
		hw.WatchdogFeed();
		nw.Run();
		node.Run();
		ntpClient.Run();
		lb.Run();
		showSystime.Run();
		display.Run();
	}
}

}
