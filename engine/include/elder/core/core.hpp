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

#define EE_DEBUG_ALL         false
#define EE_DEBUG_ID_CREATION (false || EE_DEBUG_ALL)
#define EE_DEBUG_CTOR        (true || EE_DEBUG_ALL)
#define EE_DEBUG_DTOR        (true || EE_DEBUG_ALL)
#define EE_DEBUG_LAYER_PUSH  (true || EE_DEBUG_ALL)
#define EE_DEBUG_LAYER_POP   (true || EE_DEBUG_ALL)

namespace Elder {

    template <typename T> using Shared = std::shared_ptr<T>;
    template <typename T> using Unique = std::unique_ptr<T>;

} // namespace Elder
