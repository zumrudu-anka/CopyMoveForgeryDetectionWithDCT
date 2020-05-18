@echo off
title Welcome
color F3
echo.
echo Welcome to Setup Screen
echo.
echo Please wait for all processes to finish
timeout 3 >nul
cls
color F0
python -m venv myvenv
call myvenv\Scripts\activate.bat
python -m pip install --upgrade pip
pip install -r requirements.txt
python CopyMoveForgeryDetection.py
pause
exit