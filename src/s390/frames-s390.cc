// Copyright 2011 the V8 project authors. All rights reserved.
//
// Copyright IBM Corp. 2012-2014. All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "v8.h"

#if V8_TARGET_ARCH_S390

#include "assembler.h"
#include "assembler-s390.h"
#include "assembler-s390-inl.h"
#include "frames.h"
#include "macro-assembler.h"
#include "macro-assembler-s390.h"

namespace v8 {
namespace internal {


Register JavaScriptFrame::fp_register() { return v8::internal::fp; }
Register JavaScriptFrame::context_register() { return cp; }
Register JavaScriptFrame::constant_pool_pointer_register() {
#if V8_OOL_CONSTANT_POOL
  ASSERT(FLAG_enable_ool_constant_pool);
  return kConstantPoolRegister;
#else
  UNREACHABLE();
  return no_reg;
#endif
}


Register StubFailureTrampolineFrame::fp_register() { return v8::internal::fp; }
Register StubFailureTrampolineFrame::context_register() { return cp; }
Register StubFailureTrampolineFrame::constant_pool_pointer_register() {
#if V8_OOL_CONSTANT_POOL
  ASSERT(FLAG_enable_ool_constant_pool);
  return kConstantPoolRegister;
#else
  UNREACHABLE();
  return no_reg;
#endif
}


Object*& ExitFrame::constant_pool_slot() const {
#if V8_OOL_CONSTANT_POOL
  ASSERT(FLAG_enable_ool_constant_pool);
  const int offset = ExitFrameConstants::kConstantPoolOffset;
  return Memory::Object_at(fp() + offset);
#else
  UNREACHABLE();
  return Memory::Object_at(NULL);
#endif
}


} }  // namespace v8::internal

#endif  // V8_TARGET_ARCH_S390