#define UNICODE
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define BITMAP WINDOWS_BITMAP
#include <windows.h>
#undef BITMAP
#include "plat-keyboard.h"
#include "win.h"
#include "video.h"

extern "C" int pcem_key[272];

extern "C" void fatal(const char *format, ...);
extern "C" void pclog(const char *format, ...);

extern "C" void keyboard_init();
extern "C" void keyboard_close();
extern "C" void keyboard_poll();

int pcem_key[272];

void keyboard_init()
{
        atexit(keyboard_close);
        
        memset(pcem_key, 0, sizeof(pcem_key));
	pclog("Keyboard initialized!\n");
}

void keyboard_close()
{
}

void keyboard_poll_host()
{
        int c;

        for (c = 0; c < 272; c++)
		pcem_key[c] = rawinputkey[c];

         if ((rawinputkey[0x1D] || rawinputkey[0x9D]) && 
             (rawinputkey[0x38] || rawinputkey[0xB8]) && 
             (rawinputkey[0x51] || rawinputkey[0xD1]) &&
              video_fullscreen)
                 leave_fullscreen();
}
