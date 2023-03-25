;
; Port operations
;

bits 32
global asm_read_port, asm_write_port

section .txt

;
 ; Read data from port
 ; unsigned char asm_read_port(unsigned char port)
;
asm_read_port:
	mov edx, [esp + 4]
	in al, dx
	ret

;
 ; Send data to port
 ; void asm_write_port(unsigned int port, unsigned char data)
;
asm_write_port:
	mov   edx, [esp + 4]    
	mov   al, [esp + 8]  
	out   dx, al  
	ret