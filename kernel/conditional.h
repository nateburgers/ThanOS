#pragma once

#ifdef DEBUG
# define DebugOnlyCode(__code) (__code)
#else
# define DebugOnlyCode(__code)
#endif

#ifdef TESTING
# define TestingOnlyCode(__code) (__code)
#else
# define TestingOnlyCode(__code)
#endif
