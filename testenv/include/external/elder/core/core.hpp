#pragma once

/* Elder Engine Core Definitions
 */

#if defined(__linux__)
#define ELDER_OS_LINUX

#if defined(__GNUC__)
#define EEAPI __attribute__((visibility("default")))
#else
#error Elder Engine currenly supports GCC only.
#endif

#else
#error Elder Engine currenly supports Linux only.
#endif

EEAPI void init();
