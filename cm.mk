# Copyright (C) 2016 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit from onyx device
$(call inherit-product, device/oneplus/onyx/onyx.mk)

# Enhanced NFC
$(call inherit-product, vendor/cm/config/nfc_enhanced.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

PRODUCT_NAME := cm_onyx
PRODUCT_DEVICE := onyx
PRODUCT_MANUFACTURER := OnePlus
PRODUCT_MODEL := OnePlus X

PRODUCT_GMS_CLIENTID_BASE := android-oneplus

## Use the latest approved GMS identifiers unless running a signed build
ifneq ($(SIGN_BUILD),true)
PRODUCT_BUILD_PROP_OVERRIDES += \
    BUILD_FINGERPRINT=oneplus/onyx/E1003:5.1.1/LMY47V/1441677661:user/release-keys \
    PRIVATE_BUILD_DESC="onyx-user 5.1.1 LMY47V 1441677661 release-keys"
endif
