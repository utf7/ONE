/*
 * Copyright (c) 2018 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "nnkit/support/tflite/AbstractBackend.h"
#include "nnkit/support/tflite/TensorSets.h"
#include "nnkit/support/tflite/TensorContext.h"

#include <cassert>

static inline void ensure(TfLiteStatus status) { assert(status == kTfLiteOk); }

namespace nnkit
{
namespace support
{
namespace tflite
{

void AbstractBackend::prepare(const std::function<void(nnkit::TensorContext &)> &f)
{
  ensure(interpreter().AllocateTensors());

  InputTensorSet inputs(interpreter());
  TensorContext ctx(inputs);
  f(ctx);
}

void AbstractBackend::run(void) { ensure(interpreter().Invoke()); }

void AbstractBackend::teardown(const std::function<void(nnkit::TensorContext &)> &f)
{
  OutputTensorSet outputs(interpreter());
  TensorContext ctx(outputs);
  f(ctx);
}

} // namespace tflite
} // namespace support
} // namespace nnkit
