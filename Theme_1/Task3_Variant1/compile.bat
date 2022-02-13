::::
:: Description: .bat file to compile c++ files
:: Autor: DM
:: Date: 2022-02-08
::::

@echo off

call g++ .\main.cpp -o program.exe

set /A cmdErrorLevel = %errorlevel%

if %cmdErrorLevel% equ 0 (
	echo --------------------------------
	echo --     Program compiled!      --
	echo --  Created program.exe file  --
	echo -------------------------------- )
if %cmdErrorLevel% geq 1 (
	echo --------------------------------
	echo --          ERROR!            --
	echo --   Program not compiled!    --
	echo -------------------------------- )
