README
======

Boilerplate structure and code for my personal projects. I think in
terms of langauge and tools for organization so that's how this is
broken down.

Within in each subdirectory find the files and directories for
projects using that primary language. for example the c/ subdirectory
becomes the root for a C based project.

Troy Brumley
November 2024.


STATUS
======

Only the C boilerplate is useful, I've opted to delete the old faulty
work for other languages.

At one time I had Fortran and Pascal populated, but I grew frustrated
with the FPC/Lazarus interdependence and moved to Fortran and C,
stripping out the kludge I had in place for Pascal.

After I transitioned more fully to C, the Fortran people started
really pushing the Fortran Package Manager. That may be all that we
need. If I do another Fortran project, I'll update that boilerplate as
well.

Placeholders for assembly language and Scheme are provided but they
are also empty.


DIRECTORY LAYOUT
================

.
├── LICENSE
├── README.txt <--- you are here <<<<<<<<
├── armasm
│   └── _to_be_provided_
├── c
│   ├── LICENSE
│   ├── MIT-LICENSE
│   ├── Makefile
│   ├── README.txt
│   └── source
│       ├── CMakeLists.txt
│       ├── inc
│       │   └── _your_header_files_here_
│       ├── misc
│       │   └── _your_non_code_artifacts_here_
│       ├── src
│       │   └── _your_source_files_here_
│       └── unit
│           └── _your_unit_tests_here_
├── f90
│   ├── README.txt
│   └── _see_readme_
├── pascal
│   └── _to_be_determined_but_fpc_based_
├── scheme
│   └── _probably_guile_or_chez_to_be_provided_
└── tree.txt


AUTHORSHIP, LICENSING, AND COPYRIGHT
====================================

Some or all of the code in this project is by Troy Brumley
(BlameTroi). Prior work preserves its original licensing and author
copyrights. Anything I write all public domain as far as I'm
concerned, but you can use this software either as public domain under
the unlicense or under the terms of the MIT license.

Troy Brumley
blametroi@gmail.com

So let it be written,
So let it be done.


