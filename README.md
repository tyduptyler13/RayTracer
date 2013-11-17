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

`./RayTracer [[file.obj] file2.obj]... -c commandfile`

Notes: `-c <commandfile>`. Object files are optional but without them a camera will have nothing
to render. Currently any file that is not formated correctly or that the program does not
recognize will be ignored. (Within a obj or commandfile, individual lines can be ignored if
the program can recover from the error.)

Warning: A command file is executed when it is read. Including it before object files will result
in those objects not being included in the render when that command file is executed. You can
include multiple commandfiles, simply use multiple `-c <commandfile>` to your list of args. 

Special Case: If only two arguments are used, the program will assume the first is a .obj and
the second is a command file! This means you can ignore the -c for this case.

Special Flags
----

`-h` || `--help` will request you view this document. (These are ignored if other arguments are present)

Future Flags
----

`-fc` - Enable face culling (Intersections with faces that have a non clockwise rotation to their sides are ignored)

`-ss` - Enable spacial splits. (Will break all sections recursively into manageable blocks to check intersections.)

`-aa` - Anti-Alias (Uses super sampling to fix aliasing of edges.)

Current Supported Formats
----
.obj: `g`,`f`,`mtllib`,`usemtl`,`#`,`v`,`s`

`s` is a unique type added for raytracers. It defines a sphere like so: `s name X Y Z radius`

.mtl currently only reads diffuse, specular, and ambient of each material. Texture mapping is not yet
available.

Building
----
Use `make` to create all required binaries.

Note: Once this program is finished, the output will be compiled with -O4 optimizations to improve speed
and reduce size. This usually results in a binary that is 1/10th the original size and runs much faster.
Until then it uses -Og and -g flags to allow for debugging with some optimization. (gcc 4.7 and under don't
have -Og so remove it from the master makefile should you be building a version that uses it.)
