@echo off

if "%1" NEQ "execute123" (    
    call selfcall execute123 > selfcallLog.log
    goto :EOF
)

echo %~f0
echo command 2
echo command 3

