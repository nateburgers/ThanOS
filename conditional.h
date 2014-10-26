#pragma once

#pragma mark - Debug
#ifdef DEBUG
# define DebugOnlyCode(__code) (__code)
#else
# define DebugOnlyCode(__code)
#endif

#pragma mark - Testing
#ifdef TESTING
# define TestingOnlyCode(__code) (__code)
#else
# define TestingOnlyCode(__code)
#endif
