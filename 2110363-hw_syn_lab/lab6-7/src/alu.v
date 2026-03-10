module alu (
    input  wire [31:0] a,            // First operand
    input  wire [31:0] b,            // Second operand
    input  wire [ 3:0] alu_control,  // [Control Signal] ALU control signal
    output reg  [31:0] result        // ALU result
);
    // TODO: Implement the ALU

    // alu_control param
    localparam Add = 0;
    localparam And = 1;
    localparam LeftShiftLogical = 2;
    localparam Less = 3;
    localparam LessUnsigned = 4;
    localparam Or = 5;
    localparam ReturnB = 6;
    localparam RightShiftArithmetic = 7;
    localparam RightShiftLogical = 8;
    localparam Sub = 9;
    localparam Xor = 10;

    always @(*) begin
        case (alu_control)
            Add:                  result <= a + b;
            And:                  result <= a & b;
            LeftShiftLogical:     result <= (a << b);
            Less:                 result <= ($signed(a) < $signed(b));
            LessUnsigned:         result <= ($unsigned(a) < $unsigned(b));
            Or:                   result <= a | b;
            ReturnB:              result <= b;
            RightShiftArithmetic: result <= (a >>> b);
            RightShiftLogical:    result <= (a >> b);
            Sub:                  result <= a - b;
            Xor:                  result <= a ^ b;
            default:              ;
        endcase
    end

endmodule
