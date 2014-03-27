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
.obj: `g`, `f`, `mtllib`, `usemtl`, `#`, `v`, `s`

.obj extension definitions:

* `s` is a unique type added for raytracers. It defines a sphere like so: `s name X Y Z radius`

.mtl: `Ns`, `Ka`, `Kd`, `Ks`, `Kr`, `Tr`

.mtl extension definitions:

 * `Kr` is reflectivity value. (Default is 1)
 * `Tr` is transparency value. (Default is 1 aka opaque)

__Command File:__
* `l` - Light defined as follows: `l x y z w red green blue`
  + w is the homogeneous value. A value other than 1 can cause effects like a sun or directional light.
* `c` - Camera: `c name prp_x prp_y prp_z vpn_x vpx_y vpn_z vup_x vup_y vup_z near far`
  + prp is the Perspective reference point aka where the camera is
  + vpn is the View Point Normal aka where to point the camera
  + vup is what the camera will consider the up vector. Changing this will rotate the camera.
  + near is how far a ray must travel before it will be allowed to hit something.
  + far is how far a ray can travel before it is considered a miss (objects beyond this plane won't render)
* `r` - Render: `r name width height recursion_depth`
  + Recusion_depth is the number of bounces a ray will make before it stops.

Note: This renderer does not use the far plane in bounces so objects outside of the view plane can show up in
reflections. This can be fixed by doing some simple changes in the reflection code but wasn't desired for this
project.

Current work
----
The following is still work in progress and will not function correctly.

1. Reflection (Still having bugs in various tests)
2. Refraction (Doesn't work at all yet)
3. OpenCL (Working on a realtime renderer for graphics cards that can handle the calculations.)
  * Will have a minimum requirement when we complete this portion of the project.

Building
----
Use `make` to create all required binaries.

Note: Once this program is finished, the output will be compiled with -O3 optimizations to improve speed
and reduce size. This usually results in a binary that is 1/10th the original size and runs much faster.
Until then it uses -Og and -g flags to allow for debugging with some optimization. (gcc 4.7 and under don't
have -Og so remove it from the master makefile should you be building a version that uses it.)
