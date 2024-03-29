/*
 * Copyright (C) 2011 The Android Open Source Project
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

#include "java_frame_root_info.h"

#include "stack.h"

namespace art HIDDEN {

void JavaFrameRootInfo::Describe(std::ostream& os) const {
  const StackVisitor* visitor = stack_visitor_;
  CHECK(visitor != nullptr);
  os << "Type=" << GetType() << " thread_id=" << GetThreadId() << " location=" <<
      visitor->DescribeLocation() << " vreg=";
  if (vreg_ == JavaFrameRootInfo::kUnknownVreg) {
    os << "Unknown";
  } else if (vreg_ == JavaFrameRootInfo::kImpreciseVreg) {
    os << "imprecise";
  } else if (vreg_ == JavaFrameRootInfo::kProxyReferenceArgument) {
    os << "Proxy reference argument";
  } else if (vreg_ == JavaFrameRootInfo::kMethodDeclaringClass) {
    os << "method declaring class";
  } else {
    os << vreg_;
  }
}

}  // namespace art
