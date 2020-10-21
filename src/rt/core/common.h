//
// Created by murmur-wheel on 2020/10/21.
//

#ifndef RT_CORE_COMMON_H
#define RT_CORE_COMMON_H

#define DISABLE_COPY_AND_MOVE(NAME)      \
 public:                                 \
  NAME(const NAME&) = delete;            \
  NAME(NAME&&) = delete;                 \
  NAME& operator=(const NAME&) = delete; \
  NAME& operator=(NAME&&) = delete;

#endif
