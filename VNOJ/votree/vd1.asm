.Model Small
.Stack 100
.Data
    CRLF DB 13, 10, '$'
    English DB 'Chaotay.$'
    Vietnamese DB 'Chaota.$'
.Code 
MAIN Proc    
    MOV AX, @Data
    MOV DS, AX  
    
    MOV AH, 9
    
    LEA DX, English 
    INT 21H
    
    
    Mov CX, 5    ;cout << endl
    LEA DX, CRLF
    Lap: INT 21H
         LOOP Lap
    
    LEA DX, Vietnamese
    INT 21H
    
    MOV AH, 4CH
    INT 21H
MAIN ENDp
END