DATA    SEGMENT
    DATA1   DB 80 DUP(?)
    DATA2   DB 5 DUP(0)
DATA    ENDS



CODE    SEGMENT
        ASSUME CS : CODE, DS : DATA
START:  MOV     AX, DATA  
        MOV     DX, AX
        MOV     CX, 80
        LEA     SI, DATA1
        LEA     DI, DATA2
AGAIN:  MOV     AL, [SI]
        CMP     AL, 90
        JC      NEXT1
        INC     BYTE PTR[DI]
        JMP     STO
NEXT1:  CMP     AL, 80
        JC      NEXT2
        INC     BYTE PTR[DI + 1]
        JMP     STO
NEXT2:  CMP     AL, 70
        JC      NEXT3
        INC     BYTE PTR[DI + 2]
        JMP     STO
NEXT3:  CMP     AL, 60
        JC      NEXT4
        INC     BYTE PTR[DI + 3]
        JMP     STO
NEXT4:  INC     BYTE PTR[DI + 4]
STO:    INC     SI
        LOOP    AGAIN
        MOV     AH, 4CH
        INT     21H
CODE ENDS
END START

ret




