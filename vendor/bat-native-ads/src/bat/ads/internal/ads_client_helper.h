/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_ADS_CLIENT_HELPER_H_
#define BAT_ADS_INTERNAL_ADS_CLIENT_HELPER_H_

#include "bat/ads/ads_client.h"

namespace ads {

class AdsClientHelper {
 public:
  AdsClientHelper(
      AdsClient* ads_client);

  ~AdsClientHelper();

  static AdsClient* Get();

  static bool HasInstance();
};

}  // namespace ads

#endif  // BAT_ADS_INTERNAL_ADS_CLIENT_HELPER_H_