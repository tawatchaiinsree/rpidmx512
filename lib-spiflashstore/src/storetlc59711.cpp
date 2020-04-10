/**
 * @file storetlc59711.cpp
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

#include <stdint.h>
#include <assert.h>

#include "storetlc59711.h"

#include "tlc59711dmxparams.h"
#include "tlc59711dmxstore.h"

#include "spiflashstore.h"

#include "debug.h"

StoreTLC59711 *StoreTLC59711::s_pThis = 0;

StoreTLC59711::StoreTLC59711(void) {
	DEBUG_ENTRY

	s_pThis = this;

	DEBUG_PRINTF("%p", s_pThis);

	DEBUG_EXIT
}

StoreTLC59711::~StoreTLC59711(void) {
	DEBUG_ENTRY

	DEBUG_EXIT
}

void StoreTLC59711::Update(const struct TTLC59711DmxParams* pTLC59711DmxParams) {
	DEBUG_ENTRY

	SpiFlashStore::Get()->Update(STORE_TLC5711DMX, (void *)pTLC59711DmxParams, sizeof(struct TTLC59711DmxParams));

	DEBUG_EXIT
}

void StoreTLC59711::Copy(struct TTLC59711DmxParams* pTLC59711DmxParams) {
	DEBUG_ENTRY

	SpiFlashStore::Get()->Copy(STORE_TLC5711DMX, (void *)pTLC59711DmxParams, sizeof(struct TTLC59711DmxParams));

	DEBUG_EXIT
}

void StoreTLC59711::SaveDmxStartAddress(uint16_t nDmxStartAddress) {
	DEBUG_ENTRY

	SpiFlashStore::Get()->Update(STORE_TLC5711DMX, __builtin_offsetof(struct TTLC59711DmxParams, nDmxStartAddress), (void *)&nDmxStartAddress, sizeof(uint32_t), TLC59711DMX_PARAMS_MASK_START_ADDRESS);

	DEBUG_EXIT
}
