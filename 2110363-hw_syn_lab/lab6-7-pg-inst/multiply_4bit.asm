START: 
    lw x7, 80(x0) # x7 = sext(sw)
    andi x7, x7, 255 # x7 = {24'b0, sw[7:0]}
    add x8, x0, x7 # x8 = {24'b0, sw[7:0]}
    andi x7, x7, 15 # x7 = {28'b0, sw[3:0]}
    srli x8, x8, 4 # x8 = {28'b0, sw[7:4]}
    lui x9, 0 # x9 = 0
MUL:
    beq x8, x0, MUL_DONE # while x8 != 0
    andi x10, x8, 1 # x10 = x8 & 1
    beq x10, x0, SHIFT_BIT # if x10 == 0, do not add
    add x9, x9, x7 # x9 += x7
SHIFT_BIT:
    slli x7, x7, 1 # x7 <<= 1
    srli x8, x8, 1 # x8 >>= 1
    jal x0, MUL # jump to MUL until x8 == 0

MUL_DONE:
    addi x11, x9, 0 # store result at x11, as x9 will be incorrect value most of the time
    sw x11, 84(x0) # store x11 to led
    jal x0, START # jump to START for forever multiplying