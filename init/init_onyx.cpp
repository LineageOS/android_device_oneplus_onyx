/*
   Copyright (c) 2016, The LineageOS Project
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void vendor_load_properties()
{
    std::string platform, rf_version, device;

    platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    rf_version = property_get("ro.boot.rf_version");

    if (rf_version == "101") {
        /* China */
        property_set("ro.product.model", "ONE E1001");
        property_set("ro.rf_version", "TDD_FDD_Ch_All");
    } else if (rf_version == "102") {
        /* Asia/Europe */
        property_set("ro.product.model", "ONE E1003");
        property_set("ro.rf_version", "TDD_FDD_Eu");
    } else if (rf_version == "103"){
        /* America */
        property_set("ro.product.model", "ONE E1005");
        property_set("ro.rf_version", "TDD_FDD_Am");
    } else if (rf_version == "107"){
        /* China CTCC Version */
        property_set("ro.product.model", "ONE E1000");
        property_set("ro.rf_version", "TDD_FDD_ALL_OPTR");
    }
    device = property_get("ro.product.device");
    INFO("Found rf_version : %s setting build properties for %s device\n", rf_version.c_str(), device.c_str());
}
