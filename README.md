# Visual Studio 2017 ignores debugging environment

This repository allows to reproduce issue described here:

  * Visual Studio forum: [C++ debugging environment ignored](https://developercommunity.visualstudio.com/content/problem/412668/c-debugging-environment-ignored.html)
  * Qt bugtracker: [Qt5Cored.dll not found when debugging sample GUI](https://bugreports.qt.io/projects/QTVSADDINBUG/issues/QTVSADDINBUG-600)

To reproduce the issue, you will need Qt 5.12.0 64-bit for Visual Studio 2017 installed in the default location `C:\Qt\5.12.0\msvc2017_64`.

  There are two directories, namely `fail` and `pass` containing the same minimal Qt console app. Opening the `fail` solution and trying to debug it will return a runtime error `cannot find Qt5Cored.dll`. This issue does not occur with the `pass` solution. The only difference between the two is shown in the diff below:

  ```
$ diff -ru pass/ fail/
diff -ru pass/QtConsoleApplication1/QtConsoleApplication1.vcxproj.user fail/QtConsoleApplication1/QtConsoleApplication1.vcxproj.user
--- pass/QtConsoleApplication1/QtConsoleApplication1.vcxproj.user       2019-01-31 17:23:46.124626400 -0500
+++ fail/QtConsoleApplication1/QtConsoleApplication1.vcxproj.user       2019-01-31 17:26:50.954965800 -0500
@@ -5,7 +5,7 @@
     <QTDIR>C:\Qt\5.12.0\msvc2017_64</QTDIR>
     <DebuggerFlavor>WindowsLocalDebugger</DebuggerFlavor>
     <LocalDebuggerEnvironment>PATH=$(QTDIR)\bin%3b$(VCRedistPaths)%PATH%
-</LocalDebuggerEnvironment>
+$(LocalDebuggerEnvironment)</LocalDebuggerEnvironment>
   </PropertyGroup>
   <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
     <QTDIR>C:\Qt\5.12.0\msvc2017_64</QTDIR>

  ```
