// Copyright 2023 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "rcpputils/process.hpp"

#include <stdexcept>
#include <string>

#include "rcutils/allocator.h"
#include "rcutils/process.h"

namespace rcpputils
{

std::string get_executable_name()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  char * executable_name = rcutils_get_executable_name(allocator);
  if (nullptr == executable_name) {
    throw std::runtime_error("Failed to get executable name");
  }
  std::string ret(executable_name);
  allocator.deallocate(executable_name, allocator.state);
  return ret;
}

}  // namespace rcpputils
