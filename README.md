## Inofficial PCem v14 port for macOS and Mac OS X

If you're a user looking for the Mac OS X build of PCem, click [Releases](https://github.com/kyr0/PCemV14MacOSX/releases)  and download 
the latest release. Please note that atm this is an *unofficial* build. If you have issues,
report those issue here first, not on the official forum. Thanks :)

1. Download a release (`.dmg`) here and install via drag & drop
2. Download [ROMS](https://archive.org/details/dos_rom_bios_collection) and put them into `~/Library/Application Support/PCem/`
3. Downlaod an old operating system and their respective [boot disks](https://www.allbootdisks.com/):
   - [DOS 6.22](https://archive.org/details/MS_DOS_6.22_MICROSOFT)
   - [Windows 3.11](https://archive.org/details/win3_stock)
   - [Windows 95 SR2](https://archive.org/details/Win95OSR2)
   - [Windows 98 SE](https://archive.org/details/win98se_201801)
4. Download, install and use my [Folder to ISO helper](https://github.com/kyr0/MacOS-Finder-Convert-Folder-To-CD-Image) 
   to easily transfer files from macOS to DOS/Windows by mounting the ISO as a CD ROM.

![Screencast](pcem_mac_demo.gif)

Please note:
- You can mount CD ROMs as .ISO files at runtime (right-click, context menu)
- You can and should change the rendering to OpenGL (context menu) at runtime
- A high performance configuration is: 
  - Machine: [Socket 7] Award 430VX PCI
  - CPU: Intel Pentium MMX 233
  - Memory: 256 MB
  - Video: S3 ViRGE/DX | 4MB
  - Speed: Fast VLB/PCI
  - [x] Voodoo Graphics
    - Type: Vooodoo 2
    - Framebuffer memory size: 4MB
    - Textture memory size: 4MB
    - [x] SLI
    - [x] Recompiler
  - Sound: Sound Blaster PCI 128
  - [x] Gravis Ultrasound
  - Mouse: 2-button mouse (PS/2)
   
### Known issues

- It may happen that you need to start PCem twice to open (sometimes)
- PCem segfaults on exit, but that doesn't mean anything bad for the user. 
  Still, an error message will be shown after quit.
   
### Source modifications

There are only two issues with the official v14 release of PCem blocking full Mac OS X support (from my perspective).
Both issues have been fixed in this branch (see commits for diff.):

1. `src/cdrom-ioctl-osx.c`: An OS X system header file globally defines `cycles` which conflicts with 
   the globally defined `cycles` in PCem source code. This branches solution is to lower the priority (locally overwrite)
   the global system header definition by moving the system header includes below the project header includes.
   (suggestion: Better prefix all global definitions like `PCem_cycles`?)
   
2. `src/wx-sdl2.c:get_pcem_path()`: The default path for ROM's etc. should be the users library application support folder.
   (`~/Library/Application Support/PCem/`) - therefore this brach implements this.

### How to build the app bundle and .dmg installer

You need to install the following libraries: SDL2, wxWidgets 3.x (for Mac OS X), OpenAL.
OpenAL is part of the OS X system libraries in OS X 10.13.*, so on this OS, openal-soft isn't necessary to install. 

Prerequisites: https://brew.sh

To install these libraries, use `brew` from the Homebrew project:

    brew install wxmac sdl2 openal-soft
    
Additionally, to create the `.dmg` installer, we need `create-dmg` https://github.com/andreyvit/create-dmg:

    brew install create-dmg

Then run:

    # re-build the configure script based on current system conditions
    autoreconf -i

    # dependency tracking isn't wanted here
    ./configure --enable-networking --enable-release-build --disable-dependency-tracking
 
    # permission to execute the shell scripts
    chmod +x install-sh macos-make-app-bundle-sh macos-make-app-dmg-sh

    # -j4 stands for 4 CPU parallel compilation; 
    # for dual core processors, use -j2 etc.
    # headerpad_max_install_names makes sure there is space in the binary
    # for library names/path names that may differ in length after re-write (see below) 
    make -j4 -Wl,headerpad_max_install_names

    # Locally 
    ./macos-make-app-bundle-sh
    ./macos-make-app-dmg-sh

This creates the `PCem` executable, the app bundle in `macos/build/PCem.app` and the packaged, optimized installer `PCem.dmg`.

### How to create the iconset

Use [icns-Creator](https://github.com/jamf/icns-Creator):

    icns_creator.sh macos/pcem-icon.png

### Thanks

To Sarah Walker for creating PCem and Vashpan and JosepMa (PCem forum) for some initial help.