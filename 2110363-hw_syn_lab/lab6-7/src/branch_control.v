module branch_control (
    input  wire [31:0] a,      // Value of register rs1
    input  wire [31:0] b,      // Value of register rs2
    input  wire [ 2:0] ops,    // [Control Signal] Branch type (e.g., BEQ, BNE, BLT, BGE, etc.)
    output reg         branch  // Output signal indicating whether to take the branch or not
);
    // TODO: Implement the branch control

    // branch_type param
    localparam BE = 0;
    localparam BNE = 1;
    localparam BLT = 2;
    localparam BGE = 3;
    localparam BLTU = 4;
    localparam BGEU = 5;

    always @(*) begin
        case (ops)
            BE:      branch <= (a == b);
            BNE:     branch <= (a != b);
            BLT:     branch <= ($signed(a) < $signed(b));
            BGE:     branch <= ($signed(a) >= $signed(b));
            BLTU:    branch <= ($unsigned(a) < $unsigned(b));
            BGEU:    branch <= ($unsigned(a) >= $unsigned(b));
            default: branch <= 0;
        endcase
    end

endmodule
