RayTracer
====
By: Tyler Scott

Version 1

Purpose
----
This program will read in various files to form a virtual scene of objects and will
raytrace the scene based on cameras. It will then output images formated in ppm format
to a file related to the cameras name and the type of render.

This is not a photorealistic shader. It uses several cheap tricks in shading
that achieve better looking results than what would occur in nature. For instance,
the reflections will not reflect the ambient background (black) where in nature they
normally would, doing this in this shader would result in much darker renders and
the images would quickly become degraded without proper lighting.

This raytracer exists as a good example of how to construct your own raytracer.

Examples
----
If you would like a simple usage case the samples folder has a directory called suzanne.

This was rendered using `./Raytracer suzanne.obj commands`

Usage
----

This program will accept an unlimited number of arguments.

`./RayTracer [[file.obj] file2.obj]... -c commandfile` (Unlimited object mode)

--or--

`./RayTracer <file.obj> <commands>` (Single object mode)

__Notes:__

 * Use `-c <commandfile>` to add command files. (You can add as many of these as you want)
 * You can skip the -c if there are only two arguments. (The first must be an obj file and the second must be a command file!)
 * Object files are optional but without them a camera will have nothing
to render. Currently any file that is not formated correctly or that the program does not
recognize will be ignored. (Within a obj or commandfile, individual lines can be ignored if
the program can recover from the error.)

Warning: A command file is executed when it is read. Including it before object files will result
in those objects not being included in the render when that command file is executed. You can
include multiple commandfiles, simply use multiple `-c <commandfile>` to your list of args. 

Special Flags
----

`-h` || `--help` will request you view this document. (These are ignored if other arguments are present)

Future Flags
----

`-fc` - Enable face culling (Intersections with faces that have a non clockwise rotation to their sides are ignored) (Currently automatic)

`-ss` - Enable spacial splits. (Will break all sections recursively into manageable blocks to check intersections.)

`-aa` - Anti-Alias (Does multiple samples per pixel to detect edges)

Current Supported Formats
----
.obj: `g`,`f`,`mtllib`,`usemtl`,`#`,`v`,`s`

.obj extension definitions:

* `s` is a unique type added for raytracers. It defines a sphere like so: `s name X Y Z radius`

.mtl: `Ns`, `Ka`, `Kd`, `Ks`, `Kr`, `Tr`

.mtl extension definitions:

 * `Kr` is reflectivity value. (Default is 1)
 * `Tr` is transparency value. (Default is 1 aka opaque)

Current work
----
The following is still work in progress and will not function correctly.

1. Reflection (Still having bugs in various tests)
2. Refraction (Doesn't work at all yet)

Building
----
Use `make` to create all required binaries.

Note: Once this program is finished, the output will be compiled with -O3 optimizations to improve speed
and reduce size. This usually results in a binary that is 1/10th the original size and runs much faster.
Until then it uses -Og and -g flags to allow for debugging with some optimization. (gcc 4.7 and under don't
have -Og so remove it from the master makefile should you be building a version that uses it.)
