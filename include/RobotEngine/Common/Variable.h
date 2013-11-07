#ifndef NATIV_GAMES_STUDIOS_ROBOT_ENGINE_COMMON_VARIABLE_H
#define NATIV_GAMES_STUDIOS_ROBOT_ENGINE_COMMON_VARIABLE_H

#include <RobotEngine/Common/Platform.h>

#ifdef RE_PLATFORM_ARDUINO
#include <stdint.h>
#else
#include <cstdint>
#endif

namespace re {

	typedef int8_t Sint8;
	typedef int16_t Sint16;
#ifndef RE_PLATFORM_ARDUINO
	typedef int32_t Sint32;
#endif

	typedef uint8_t Uint8;
	typedef uint16_t Uint16;
#ifndef RE_PLATFORM_ARDUINO
	typedef uint32_t Uint32;
#endif

  struct Buffer {
    void *datas;
    Uint16 size;
  };

  /*enum VariableType {
    NONE = 0,
    UINT8 = 1,
    UINT16 = 2,
#ifndef RE_PLATFORM_ARDUINO
    UINT32 = 3,
#endif
    SINT8 = 4,
    SINT16 = 5,
#ifndef RE_PLATFORM_ARDUINO
    SINT32 = 6,
#endif
    STRING = 10
  };

  struct VariableInfo {
    char *name;
    VariableType type;
  };

  union VariableData {
    Uint8  u8;
    Uint16 u16;
#ifndef RE_PLATFORM_ARDUINO
    Uint32 u32;
#endif
    Sint8  s8;
    Sint16 s16;
#ifndef RE_PLATFORM_ARDUINO 
    Sint32 s32;
#endif
    float f;
    double d;
    char *s;
    Uint8 b;
  };
*/
}

#endif

