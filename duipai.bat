:p
Datamaker.exe > data.in
niuke9e.exe < data.in > My.out
mul9E.exe < data.in > Zyc.out
fc "My.out" "Zyc.out"
if not errorlevel 1 (
    goto p
)
pause