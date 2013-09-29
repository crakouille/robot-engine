#ifndef NATIV_GAMES_STUDIOS_ROBOT_ENGINE_COMMON_PLATFORM_H
#define NATIV_GAMES_STUDIOS_ROBOT_ENGINE_COMMON_PLATFORM_H

#ifdef RE_PLATFORM_ARDUINO
#elif defined(RE_PLATFORM_LINUX)
#else
#error The platform has not be mentionned
#error please use 'avr-gcc -DRE_PLATFORM_ARDUINO' or 'gcc -DRE_PLATFORM_LINUX' 
#endif

#endif

