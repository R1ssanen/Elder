#pragma once

/* Elder Engine Core Definitions
 */

#if defined(__linux__)
#define ELDER_OS_LINUX

#if defined(__GNUC__)
#define EE_API    __attribute__((visibility("default")))
#define EE_NONAPI __attribute__((visibility("hidden")))
#else
#error Elder Engine currenly supports GCC only.
#endif

#else
#error Elder Engine currenly supports Linux only.
#endif

#define ELDER_DEBUG_ALL         false
#define ELDER_DEBUG_ID_CREATION (false || ELDER_DEBUG_ALL)
#define ELDER_DEBUG_CTOR        (false || ELDER_DEBUG_ALL)
#define ELDER_DEBUG_DTOR        (false || ELDER_DEBUG_ALL)

namespace Elder {

    template <typename T> using Shared = std::shared_ptr<T>;
    template <typename T> using Unique = std::unique_ptr<T>;

} // namespace Elder
