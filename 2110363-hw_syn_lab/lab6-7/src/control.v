module control (
    input wire [6:0] opcode,  // Opcode from the instruction
    input wire [2:0] funct3,  // funct3 field from the instruction
    input wire [6:0] funct7,  // funct7 field from the instruction
    output reg mem_read,  // Memory read control signal
    output reg mem_write,  // Memory write control signal
    output reg [2:0] data_mask,  // Memory data mask control signal (indicates how many bytes to read/write and whether it's signed/unsigned, usually derived from funct3)
    output reg reg_write,  // Register write control signal
    output reg alu_src_1,  // ALU source select control signal 1 (0 = from rs1, 1 = from PC)
    output reg alu_src_2,  // ALU source select control signal 2 (0 = from rs2, 1 = from immediate)
    output reg [3:0] alu_control,  // ALU control signal
    output reg [1:0] write_to_reg_sel,    // Control signal for MUX which selects data to write back to register (0 = from ALU, 1 = from memory, 2 = from PC + 4)
    output reg [2:0] branch_type,  // Control signal for branch type (derived from funct3 for B-type instructions, can be used to determine the type of branch condition to check)
    output reg is_branch,    // Control signal indicating whether the instruction is a branch (can be used to control PC update logic
    output reg is_jump     // Control signal indicating whether the instruction is a jump (e.g., JAL, JALR)
);
    // TODO: Implement the control logic

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

    // branch_type param
    localparam BE = 0;
    localparam BNE = 1;
    localparam BLT = 2;
    localparam BGE = 3;
    localparam BLTU = 4;
    localparam BGEU = 5;

    always @(*) begin
        // mem_read
        case (opcode[6:2])
            5'b00000: mem_read <= 1;
            default:  mem_read <= 0;
        endcase
        // mem_write
        case (opcode[6:2])
            5'b01000: mem_write <= 1;
            default:  mem_write <= 0;
        endcase
        // data_mask
        case (opcode[6:2])
            5'b00000: data_mask <= funct3;
            5'b01000: data_mask <= funct3;
            default:  data_mask <= 3'bxxx;
        endcase
        // reg_write
        case (opcode[6:2])
            5'b01000: reg_write <= 0;
            5'b11000: reg_write <= 0;
            default:  reg_write <= 1;
        endcase
        // alu_src_1
        case (opcode[6:2])
            5'b00101: alu_src_1 <= 1;
            5'b11000: alu_src_1 <= 1;
            5'b11011: alu_src_1 <= 1;
            default:  alu_src_1 <= 0;
        endcase
        // alu_src_2
        case (opcode[6:2])
            5'b01100: alu_src_2 <= 0;
            default:  alu_src_2 <= 1;
        endcase
        // alu_control
        case (opcode[6:2])
            5'b00000: alu_control <= Add;
            5'b00100: begin
                case (funct3)
                    3'b000:  alu_control <= Add;
                    3'b001:  alu_control <= LeftShiftLogical;
                    3'b010:  alu_control <= Less;
                    3'b011:  alu_control <= LessUnsigned;
                    3'b100:  alu_control <= Xor;
                    3'b101: begin
                        case (funct7[6:2])
                            5'b00000: alu_control <= RightShiftLogical;
                            5'b01000: alu_control <= RightShiftArithmetic;
                            default:  ;
                        endcase
                    end
                    3'b110:  alu_control <= Or;
                    3'b111:  alu_control <= And;
                    default: ;
                endcase
            end
            5'b00101: alu_control <= Add;
            5'b01000: alu_control <= Add;
            5'b01100: begin
                case (funct3)
                    3'b000: begin
                        case (funct7[6:2])
                            5'b00000: alu_control <= Add;
                            5'b01000: alu_control <= Sub;
                            default:  ;
                        endcase
                    end
                    3'b001:  alu_control <= LeftShiftLogical;
                    3'b010:  alu_control <= Less;
                    3'b011:  alu_control <= LessUnsigned;
                    3'b100:  alu_control <= Xor;
                    3'b101: begin
                        case (funct7[6:2])
                            5'b00000: alu_control <= RightShiftLogical;
                            5'b01000: alu_control <= RightShiftArithmetic;
                            default:  ;
                        endcase
                    end
                    3'b110:  alu_control <= Or;
                    3'b111:  alu_control <= And;
                    default: ;
                endcase
            end
            5'b01101: alu_control <= ReturnB;
            5'b11000: alu_control <= Add;
            5'b11001: alu_control <= Add;
            5'b11011: alu_control <= Add;
            default:  ;
        endcase
        // write_to_reg_sel
        case (opcode[6:2])
            5'b00000: write_to_reg_sel <= 1;
            5'b11001: write_to_reg_sel <= 2;
            5'b11011: write_to_reg_sel <= 2;
            default:  write_to_reg_sel <= 0;
        endcase
        // branch_type
        case (opcode[6:2])
            5'b11000: begin
                case (funct3)
                    3'b000:  branch_type <= BE;
                    3'b001:  branch_type <= BNE;
                    3'b100:  branch_type <= BLT;
                    3'b101:  branch_type <= BGE;
                    3'b110:  branch_type <= BLTU;
                    3'b111:  branch_type <= BGEU;
                    default: ;
                endcase
            end
            default: ;
        endcase
        // is_branch
        case (opcode[6:2])
            5'b11000: is_branch <= 1;
            default:  is_branch <= 0;
        endcase
        // is_jump
        case (opcode[6:2])
            5'b11001: is_jump <= 1;
            5'b11011: is_jump <= 1;
            default:  is_jump <= 0;
        endcase
    end

endmodule
