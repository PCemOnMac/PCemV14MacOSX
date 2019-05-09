PCem v14 Mac OS X supplement

You will need the following libraries :

SDL2
wxWidgets 3.x
OpenAL

To install these libraries, use "brew":

    /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

    brew install wxmac sdl2 openal-soft

Open a terminal window, navigate to the PCem directory then enter

autoreconf -i

./configure --enable-networking --enable-release-build

chmod +x install-sh

make -j4

then ./pcem to run.

The Linux version stores BIOS ROM images, configuration files, and other data in ~/.pcem

configure options are :
  --enable-release-build : Generate release build. Recommended for regular use.
  --enable-debug         : Compile with debugging enabled.
  --enable-networking    : Build with networking support.
  --enable-alsa          : Build with support for MIDI output through ALSA. Requires libasound.


The menu is a pop-up menu in the Linux port. Right-click on the main window when mouse is not
captured.

CD-ROM support currently only accesses /dev/cdrom. It has not been heavily tested.
