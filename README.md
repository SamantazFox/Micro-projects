Sam's micro projects
====================

This repository is a C/C++ utilities code dump.

Projects in this repo fit in a single C source file (plus an optional header
file) and does not require any additional libraries, outside of stdlib.


Folders description
-------------------

The `standalone` directory contains code that can be compiled and ran as is,
i.e code that contains a `main()` function.

The `library` directory contains code that must be compiled either as a shared
library or as part of another project (using header file).


How to use
----------

For standalone projects:

``` sh
# Compile project (C)
gcc -std=c11 -o {project} {project}.c

# Compile project (C++)
gcc -std=c++11 -o {project} {project}.cxx

# Run the binary
./project [args]
```

For other projects, read project-specific instructions in the comment at the top
of the project's file(s).


Compatibility
-------------

All the code in this repo has been optimized for GCC.

Compilation has been tested on Linux and Windows (using MinGW).


Licensing
---------

This repo's content is released under the public domain.

Feel free to copy, modify and redistribute the code.

Read the UNLICENSE file for more infos.
