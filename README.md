This repository contains a template to create plugins for the Ibex library with
CMake.

To customize this template, one can change these two lines in
[CMakeLists.txt](./CMakeLists.txt):

```
project (IBEX_MYPLUGIN VERSION 0.42 LANGUAGES CXX)
set (IBEX_MYPLUGIN_DESCRIPTION "Short description of the plugin")
```

with the actual name, version and description of the plugin.

In [src/CMakeLists.txt](./src/CMakeLists.txt), there is an example of the
compilation of a library depending on the Ibex library.
In [src/bin/CMakeLists.txt](./src/bin/CMakeLists.txt), there is two examples of
the compilation of a binary.
One can remove the lines corresponding to examples that are not needed and can
customize the other ones (mostly by appending new source files and changing the
name of the targets).
