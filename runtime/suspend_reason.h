/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ART_RUNTIME_SUSPEND_REASON_H_
#define ART_RUNTIME_SUSPEND_REASON_H_

#include <iosfwd>

#include "base/macros.h"

namespace art HIDDEN {

// The various reasons that we might be suspending a thread.
enum class SuspendReason : char {
  // Suspending for internal reasons (e.g. GC, stack trace, etc.).
  // TODO Split this into more descriptive sections.
  kInternal,
  // Suspending due to non-runtime, user controlled, code. (For example Thread#Suspend()).
  kForUserCode,
};

std::ostream& operator<<(std::ostream& os, SuspendReason thread);

}  // namespace art

#endif  // ART_RUNTIME_SUSPEND_REASON_H_
