/*
 * Copyright (c) 2019 Samsung Electronics Co., Ltd. All Rights Reserved
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

#ifndef __LOCOEX_COPDIALECT_H__
#define __LOCOEX_COPDIALECT_H__

#include <loco/IR/Dialect.h>

namespace locoex
{

/**
 * @brief A singleton for locoex custom op Dialect
 */
class COpDialect final : public loco::Dialect
{
private:
  COpDialect() = default;

public:
  COpDialect(const Dialect &) = delete;
  COpDialect(Dialect &&) = delete;

public:
  static loco::Dialect *get(void);
};

} // namespace locoex

#endif // __LOCOEX_COPDIALECT_H__
