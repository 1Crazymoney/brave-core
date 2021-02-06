/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/user_activity/page_transition_util.h"

#include "ui/base/page_transition_types.h"

#include "bat/ads/internal/user_activity/user_activity.h"

namespace ads {

bool DidUseBackOrFowardButtonToTriggerNavigation(
    const int32_t page_transition) {
  return (page_transition & ui::PAGE_TRANSITION_FORWARD_BACK) != 0;
}

bool DidUseAddressBarToTriggerNavigation(const int32_t page_transition) {
  return (page_transition & ui::PAGE_TRANSITION_FROM_ADDRESS_BAR) != 0;
}

bool DidNavigateToHomePage(const int32_t page_transition) {
  return (page_transition & ui::PAGE_TRANSITION_HOME_PAGE) != 0;
}

bool DidTransitionFromExternalApplication(const int32_t page_transition) {
  return (page_transition & ui::PAGE_TRANSITION_FROM_API) != 0;
}

std::string GetCoreTransitionString(const int32_t page_transition) {
  return ui::PageTransitionGetCoreTransitionString(
      ui::PageTransitionFromInt(page_transition));
}

int32_t GetQualifier(const int32_t page_transition) {
  return ui::PageTransitionGetQualifier(
      ui::PageTransitionFromInt(page_transition));
}

base::Optional<UserActivityEventType> ToUserActivityEventType(
    const int32_t page_transition) {
  switch (ui::PageTransitionFromInt(page_transition)) {
    case ui::PAGE_TRANSITION_LINK: {
      return UserActivityEventType::kClickedLink;
    }

    case ui::PAGE_TRANSITION_TYPED: {
      return UserActivityEventType::kTypedUrl;
    }

    case ui::PAGE_TRANSITION_AUTO_BOOKMARK: {
      return UserActivityEventType::kBookmark;
    }

    case ui::PAGE_TRANSITION_GENERATED: {
      return UserActivityEventType::kTypedAndSelectedNonUrl;
    }

    case ui::PAGE_TRANSITION_FORM_SUBMIT: {
      return UserActivityEventType::kSubmittedForm;
    }

    case ui::PAGE_TRANSITION_RELOAD: {
      return UserActivityEventType::kReloaded;
    }

    case ui::PAGE_TRANSITION_KEYWORD: {
      return UserActivityEventType::kKeywordOtherThanDefaultSearchProvider;
    }

    case ui::PAGE_TRANSITION_KEYWORD_GENERATED: {
      return UserActivityEventType::kGeneratedKeyword;
    }

    default: {
      return base::nullopt;
    }
  }
}

}  // namespace ads
