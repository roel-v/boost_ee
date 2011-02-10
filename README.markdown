Introduction
============

A collection of Expression Evaluator objects (visualizers) that show human-readable
forms of boost objects in the Visual Studio debugger.

Classes supported so far:
- boost::posix_time::ptime
- boost::gregoran::date

Installation
============

- Copy boostee.dll to devenv.exe dir (done automatically in post-build step)
  Alternatively, copy it anywhere where LoadLibrary can find it (in %PATH%, ...)
  Or, specify the full path in the entries below.

- Add this to autoexp.dat (c:\Program Files\Microsoft Visual Studio 9.0\Common7\Packages\Debugger):

boost::posix_time::ptime=$ADDIN(boostee.dll,AddIn_Boost_Posix_time_Ptime)
boost::posix_time::ptime=$ADDIN(boostee.dll,AddIn_Boost_Gregorian_Date)

