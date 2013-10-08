RayTracer
====
By: Tyler Scott


Purpose
----
This program will read in various files to form a virtual scene of objects and will
raytrace the scene based on cameras. It will then output images formated in ppm format
to a file related to the cameras name and the type of render.

Usage
----

This program will accept an unlimited number of arguments.

(Ignore the .exe for non windows systems, it compiles on most systems.)

`RayTracer.exe [[file.obj] file2.obj]... -c commandfile`

Notes: `-c <commandfile>`. Object files are optional but without them a camera will have nothing
to render. Currently any file that is not formated correctly or that the program does not
recognize will be ignored. (Within a obj or commandfile, individual lines can be ignored if
the program can recover from the error.)

Warning: A command file is executed when it is read. Including it before object files will result
in those objects not being included in the render when that command file is executed. You can
include multiple commandfiles, simply use multiple `-c <commandfile>` to your list of args. 


Special Flags
----

`-h` || `--help` will request you view this document. (These are ignored if other arguments are present)

Building
----
Use `make` to create all required binaries.

This build is parallel safe and you can just `make -j#` to allow it to build faster. Where # is the number of threads.

Note: Once this program is finished, the output will be compiled with -O4 optimizations to improve speed and reduce size. This usually results in a binary that is 1/10th the original size and runs much faster. Until then it uses -Og and -g flags to allow for debugging with some optimization.