module imm_gen (
    input  wire [31:0] inst,  // Input instruction
    output reg  [31:0] imm    // Output immediate value
);
    // TODO: Implement the immediate generator
    always @(*) begin
        case (inst[6:2])
            // I-type
            5'b00100: imm <= {{20{inst[31]}}, inst[31:20]};
            5'b00000: imm <= {{20{inst[31]}}, inst[31:20]};
            // S-type
            5'b01000: imm <= {{20{inst[31]}}, inst[31:25], inst[11:7]};
            // B-type
            5'b11000: imm <= {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
            // U-type
            5'b01101: imm <= {inst[31:12], 12'b0};
            5'b00101: imm <= {inst[31:12], 12'b0};
            // J-type
            5'b11011: imm <= {{19{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0};
            5'b11001: imm <= {{20{inst[31]}}, inst[31:20]};
            default:  imm <= 0;
        endcase
    end

endmodule
