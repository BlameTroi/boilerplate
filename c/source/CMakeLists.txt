# CMakeLists.txt
#
# cmake is something of a moving target with a lot of outdated
# information and borderline flamewars out on the net about how or why
# to do things. this works well for me and seems not too offensive to
# purists.
#
# that said, there is a lot of redundancy here, but i think of it like
# a linkdeck from my mainframe days. declarative and the repetition
# isn't very expensive. the gnu make scripting to do this on the fly
# was more hassle than it was worth and i couldn't make eglot and
# clangd happy.
#
# the following passes options to each build configuration properly
# (as of October 2024) and creates a compile-commands.json file that
# clangd seems to like.
#
# troy brumley, blametroi@gmail.com, november 2024.
#
# configurations are typically Debug, Release, and RelWithDebInfo when
# using the Ninja Multi-Config generator.
#
# the intended project directory structure and key files:
# 
# project-root/
#   build/       (created by cmake)
#     ...a lot of stuff for cmake and ninja...
#     compile_commands.json (generated)
#   source/      (you live here)
#     ->compile_commands.json symlink
#     CMakeLists.txt
#     inc/
#     misc/
#     src/
#     unit/
#
# readme and such go at the root, along with your .git/ or other
# source control system artifacts.
#
# enjoy keeping CMakeLists.txt up to date.
#
# cmake -B ../build -S . -G "Ninja Multi-Config" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
#
# cmake --build build --config Release or Debug or RelWithDebInfo ...
#
# to build whatever you need. if you are using emacs with eglot
# the compile_commands.json file needs to be available. i keep
# it parked in source by symlinking to the generated file that
# ends up in ../build/. i have no idea what to do for vscode
# or other editor/ide compinations.


cmake_minimum_required(VERSION 3.5)

project(
  _some_name_
  VERSION 0.0.0.1
  DESCRIPTION "be helpful here"
  HOMEPAGE_URL "https://github... repo"
  LANGUAGES C
)

set(
  CMAKE_C_COMPILER "clang"
)

# configurations are typically Debug, Release, and RelWithDebInfo when
# using the Ninja Multi-Config generator.
#
# create options variable strings for each configuration.
#
# eg: set(MY_REL_OPT "-Wall -Werror -std=c18")
#     set(MY_DEB_OPT "-Wall -Werror -stc=c18 -fsanitize=address")
#     set(MY_DEB_LINK_OPT "-fsanitize=address")
#
# for each target (an executable usually), use the command
# target_<step>_options() to pass values to the compiler
# where (<step>=compile) or linker (<step>=link).
#
# target_compile_options(targ PUBLIC "$<$<CONFIG:DEBUG>:SHELL:${MY_DEB_OPT}>")
# target_link_options(targ PUBLIC "$<$<CONFIG:DEBUG>:SHELL:${MY_DEB_LINK_OPT}>")
#
# where:
#
# * targ is whichever target this is for.
#
# * "$<$<CONFIG:configuration>...text to insert...>" is a generator
#   expression. when the scripting for a configuration is generated,
#   the text to insert will be used in the appropriate place.
#
# * :SHELL: handles spaces in the options string, otherwise the whole
#   string is double quoted and that doesn't work well.
#
# * target_<step>_options(generator_expression:replacement)
#
# so for my builds i need the following for each target (build
# artifact for release):
#
# add_<target_type>(name source_dependency...)
# target_include_directories(name directories...)
# target_link_options(name generator expression) *only for debug atm
# target_compile_options(name PUBLIC "$<$<CONFIG:config>:...>") *for each config
#
# when i have needed to pull other header libraries into a project,
# i've created directory symlinks parallel to inc/ in this structure
# and added that directory to target_link_options.
#
# as i do more, say creating shared libraries, more will be needed,
# but this is sufficient for the time being.

# these are probably the same for all my c based projects:

set(MY_RELEASE_OPTIONS "-Wall -Werror -pedantic-errors -std=c18")
set(MY_RELWITHDEBINFO_OPTIONS "-Wall -Werror -pedantic-errors -std=c18 -g")
set(MY_DEBUG_OPTIONS "-Wall -Werror -pedantic-errors -std=c18 -g -fsanitize=address")
set(MY_DEBUG_LINK_OPTIONS "-fsanitize=address")

# and some sample targets

# just one source file:
add_executable(minunit_example "${CMAKE_CURRENT_SOURCE_DIR}/src/minunit_example.c")
target_include_directories(minunit_example PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/inc")
target_link_options(minunit_example PUBLIC "$<$<CONFIG:DEBUG>:SHELL:${MY_DEBUG_LINK_OPTIONS}>")
target_compile_options(minunit_example PUBLIC "$<$<CONFIG:RELWITHDEBINFO>:SHELL:${MY_REL_DEB_OPTIONS}>")
target_compile_options(minunit_example PUBLIC "$<$<CONFIG:DEBUG>:SHELL:${MY_DEBUG_OPTIONS}>")
target_compile_options(minunit_example PUBLIC "$<$<CONFIG:RELEASE>:SHELL:${MY_RELEASE_OPTIONS}>")

# muliple source dependencies:
add_executable(unitdl "${CMAKE_CURRENT_SOURCE_DIR}/unit/unitdl.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/dl.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/misc.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/rand.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/str.c")
target_include_directories(unitdl PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/inc")
target_link_options(unitdl PUBLIC "$<$<CONFIG:DEBUG>:SHELL:${MY_DEBUG_LINK_OPTIONS}>")
target_compile_options(unitdl PUBLIC "$<$<CONFIG:RELWITHDEBINFO>:SHELL:${MY_REL_DEB_OPTIONS}>")
target_compile_options(unitdl PUBLIC "$<$<CONFIG:DEBUG>:SHELL:${MY_DEBUG_OPTIONS}>")
target_compile_options(unitdl PUBLIC "$<$<CONFIG:RELEASE>:SHELL:${MY_RELEASE_OPTIONS}>")
