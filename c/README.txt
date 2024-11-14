	   ====================
	   whatever this is for
	   ====================


...brief overview paragraph...

Troy Brumley, blametroi@gmail.com, July 2024.

So let it be written,
So let it be done.



Installation and Use
--------------------




External Dependencies
---------------------

Nothing that isn't already installed or easily obtainable using
a package manager.

 1. A C compiler (C99 support or above)

 2. CMake

 4. ninja



License
-------

My work is all public domain, but if you need an explicit license
you may take your pick from public domain under the terms of the
UNLICENSE or under the terms of the MIT license. Any work by others
that I include is under the original license.

			    ==============
			    Project Layout
			    ==============


...use tree and provide an introductory paragraph along with
a tree diagram of the major directories and artifacts...


.
├── LICENSE
├── MIT-LICENSE
├── Makefile
├── README.txt    <---- you are here <<<<<<<<
├── source
│   ├── CMakeLists.txt <--- but the important details are here <<<<<
│   ├── inc
│   │   └── _your_header_files_here_
│   ├── misc
│   │   └── _your_non_code_artifacts_here_
│   ├── src
│   │   └── _your_source_files_here_
│   └── unit
│       └── _your_unit_tests_here_
└── tree.txt

CMake will create a build/ directory parallel to source/ but is not
part of the git repository. You'll end up running these commands
a few times:

  cmake -G "Ninja Multi-Config" -S . -B build

  cmake --build build --config (Release|Debug|RelWithDebInfo)

			 ====================
			 Implementation Notes
			 ====================

...or whatever else might need to be said...

		     =============================
		     TO DO Items, Ideas, and Notes
		     =============================
...if appropriate...
