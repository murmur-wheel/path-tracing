//
// Created by murmur-wheel on 2020/10/21.
//

#ifndef RT_CORE_COMMON_H
#define RT_CORE_COMMON_H

#include <glog/logging.h>

#include <cassert>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <list>
#include <memory>
#include <numeric>
#include <sstream>
#include <type_traits>
#include <vector>

#define DISABLE_COPY_AND_MOVE(NAME)      \
 public:                                 \
  NAME(const NAME&) = delete;            \
  NAME(NAME&&) = delete;                 \
  NAME& operator=(const NAME&) = delete; \
  NAME& operator=(NAME&&) = delete;

using Float = float;
const Float Infinity = std::numeric_limits<Float>::infinity();

#endif
