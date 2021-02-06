/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_USER_ACTIVITY_USER_ACTIVITY_EVENT_TYPES_H_
#define BAT_ADS_INTERNAL_USER_ACTIVITY_USER_ACTIVITY_EVENT_TYPES_H_

#include <stdint.h>

namespace ads {

enum class UserActivityEventType : int8_t {
  kOpenedNewOrFocusedOnExistingTab,
  kClosedTab,
  kPlayedMedia,
  kBrowserWindowDidBecomeActive,
  kBrowserWindowDidEnterBackground,
  kClickedLink,
  kTypedUrl,
  kBookmark,
  kTypedAndSelectedNonUrl,
  kSubmittedForm,
  kReloaded,
  kKeywordOtherThanDefaultSearchProvider,
  kGeneratedKeyword
};

}  // namespace ads

#endif  // BAT_ADS_INTERNAL_USER_ACTIVITY_USER_ACTIVITY_EVENT_TYPES_H_
